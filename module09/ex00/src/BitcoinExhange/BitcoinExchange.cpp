#include "BitcoinExchange.hpp"
#include <sstream>
#include <fstream>
#include <iomanip>

BitcoinExchange::BitcoinExchange(std::string dbPath, std::string inFilePath)
: m_dbPath(dbPath)
, m_inFilePath(inFilePath) {}

BitcoinExchange::~BitcoinExchange(){}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
	if (date.length() != 10)
		return false;
	std::istringstream streamDate(date);
	unsigned int year, month, day;
	char dash1, dash2;

	if (streamDate >> year >> dash1 >> month >> dash2 >> day)
	{
		if (streamDate.eof() && dash1 == '-' && dash2 == '-')
		{	
			unsigned int febDays = 28;

			if (year > 9999
				|| month > 12
				|| day > 31
				|| (!(month % 2) && day > 30))
				return false;
			if (!(year % 400) || (year % 100 && !(year % 4)))
				febDays = 29;
			if (month == 2 && day > febDays)
				return false;
			return true;
		}
	}
	return false;
}
void	BitcoinExchange::parseLineToMap(const std::string& line, DateValueMap& map, char delim)
{
		std::istringstream	lineStream(line);
		std::string			date;
		double				value;

		std::getline(lineStream, date, delim);
		if (!(lineStream >> value) || !lineStream.eof())
			throw std::runtime_error("Error: Invalid value.");
		if (delim == '|')
		{
			if (value > 1000)
				throw std::runtime_error("Error: too large a number.");
			if (value < 0)
				throw std::runtime_error("Error: not a positive number.");
		}
		struct tm dateTm = {};
		if (strptime(date.c_str(), "%Y-%m-%d", &dateTm))
		{
			std::time_t dateTime = mktime(&dateTm);
			map.insert(std::make_pair(dateTime, value));
		}
}

void BitcoinExchange::parseDbIntoMap()
{
	std::ifstream 	file(m_dbPath);
	std::string		line;
	
	if (!file.is_open())
		throw std::runtime_error("Couldn't open " + m_dbPath);
	std::getline(file, line);
	line.clear();
	while (std::getline(file, line))
	{
		parseLineToMap(line, m_dbDateValueMap, ',');
	}
	file.close();
}

void BitcoinExchange::printConversion()
{
	std::ifstream 	file(m_inFilePath);
	std::string		line;
	DateValueMap	inFileMap;

	parseDbIntoMap();
	if (!file.is_open())
		throw std::runtime_error("Couldn't open " + m_inFilePath);
	std::getline(file, line);
	line.clear();
	while(std::getline(file, line))
	{
		if (line.empty())
			continue;
		try
		{
			DateValueMap		lineDateValueMap;
			std::istringstream 	stream(line);
			std::string			date;

			std::getline(stream, date, ' ');
			if (!isValidDate(date))
				throw std::runtime_error("Error: bad input => " + date);
			parseLineToMap(line, lineDateValueMap, '|');
			
			DateValueMap::const_iterator it = lineDateValueMap.begin();
			DateValueMap::const_iterator dbIt = m_dbDateValueMap.begin();

			if (it->first < dbIt->first)
				throw std::runtime_error("Error: Bitcoint exchange rates start from 2009-01-02.");
			for ( ; dbIt != m_dbDateValueMap.end(); dbIt++)
			{
				if (dbIt->first == it->first)
					break;
				else if (dbIt->first > it->first)
				{
					dbIt--;
					break;
				}
			}
			if (dbIt == m_dbDateValueMap.end())
				dbIt--;
			std::cout << date 
			<< " => " 
			<<  it->second 
			<< " = "
			<<  std::fixed << std::setprecision(1) 
			<<  dbIt->second * it->second
			<< std::endl;
		}
		catch(std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}