#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <ctime>
#include <map>

class BitcoinExchange
{
typedef std::multimap<std::time_t, double> DateValueMap;

private:
	const std::string	m_dbPath;
	const std::string	m_inFilePath;
	DateValueMap		m_dataBaseDateValueMap;
	DateValueMap		m_inFileDateValueMap;

	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& copy);
	BitcoinExchange& operator=(const BitcoinExchange& copy);

	void parseDbIntoMap();
	void parseLineToMap(const std::string& line, DateValueMap& map, char delim);
	bool isValidDate(const std::string& date) const;

public:
	BitcoinExchange(std::string dbPath, std::string inFilePath);
	~BitcoinExchange();

	void printBitcoinValues();
};

#endif