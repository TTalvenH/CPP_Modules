#include "BitcoinExchange.hpp"
#include <sstream>
#include <fstream>


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
			if (year > 9999
				|| month > 12
				|| day > 31
				|| (!(month % 2) && day > 30)
				|| ((month == 2) && day > 28
				&& (!(year % 4) && ((year % 100) || !(year % 400))) && day > 29))
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
		lineStream >> value;
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
		parseLineToMap(line, m_dataBaseDateValueMap, ',');
	}
	file.close();
}

void BitcoinExchange::printBitcoinValues()
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
		try
		{
			std::istringstream 	stream(line);
			std::string			date;

			std::getline(stream, date, ' ');
			if (!isValidDate(date))
				throw std::runtime_error("Error: bad input => " + date);
			parseLineToMap(line, m_inFileDateValueMap, '|');

			DateValueMap::const_iterator it = m_inFileDateValueMap.end();
			it--;
			std::cout << it->first << " " << it->second << std::endl;
		}
		catch(std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}


	// for (DateValueMap::const_iterator it = m_dateValueMap.begin(); it != m_dateValueMap.end(); it++)
	// {
	// 	        std::cout << it->first << " " << it->second << std::endl;
	// }
	std::cout << std::endl;

}