#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>

class BitcoinExchange
{
public:
	BitcoinExchange(const std::string &database);
	BitcoinExchange(const BitcoinExchange &other);
	~BitcoinExchange();
	BitcoinExchange &operator=(const BitcoinExchange &other);

	std::map<std::string, double> getExchangeData() const;

	void printPrices(const std::string &input_file) const;

private:
	std::map<std::string, double> exchangeData;

	void parseExchangeFile(std::map<std::string, double> &map, const std::string &exchange_file) const;
	void parseDate(const std::string &date, int *year, int *month, int *day) const;
	std::string findClosestDate(const std::map<std::string, double> &map, int year, int month, int day) const;
	void parseInputLine(const std::string &line, std::string &date, double *value) const;
};

#endif
