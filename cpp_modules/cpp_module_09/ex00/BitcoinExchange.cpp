#include <iostream>
#include <sstream>
#include <fstream>
#include <errno.h>

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &database)
{
	parseExchangeFile(exchangeData, database);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
: exchangeData(other.getExchangeData()) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this == &other) return *this;

	exchangeData.clear();
	exchangeData = other.exchangeData;
	return *this;
}

std::map<std::string, double> BitcoinExchange::getExchangeData() const
{
	return exchangeData;
}

void BitcoinExchange::printPrices(const std::string &input_file) const
{
	std::ifstream file;
	try { file.open(input_file); } catch (std::exception &e)
		{ std::cout << "Error: failed to read input file" << std::endl; }
	std::string line;
	getline(file, line); // Skip first line
	while (getline(file, line))
	{
		std::string date;
		double amount;
		try { parseInputLine(line, date, &amount); } catch (std::exception &e)
			{ std::cout << "Error: failed to parse line: " << line << std::endl; continue; };
		if (exchangeData.count(date) == 0)
		{
			int year, month, day;
			try { parseDate(date, &year, &month, &day); } catch (std::exception &e)
				{ std::cout << "Error: bad input => " << date << std::endl; continue; }
			try { date = findClosestDate(exchangeData, year, month, day); } catch (std::exception &e)
				{ std::cout << "Error: no entry found with a date before or on " << date << std::endl; continue; }
		}
		std::cout << date << " => " << amount << " = " 
			<< std::fixed << std::setprecision(2) << amount * exchangeData.at(date) << std::endl;
	}
	file.close();
}

void BitcoinExchange::parseExchangeFile(
	std::map<std::string, double> &map, const std::string &exchange_file) const
{
	std::ifstream file;
	try { file.open(exchange_file); } catch (std::exception &e)
		{ std::cout << "Error: failed to read exchange rate file data.csv" << std::endl; }
	std::string line;
	getline(file, line); // Skip first line
	while (getline(file, line))
	{
		size_t delimiter = line.find(',');
		std::string date = line.substr(0, delimiter);
		std::string rate = line.substr(delimiter + 1, line.size());
		char *end;
		map[date] = strtof(rate.c_str(), &end);
		if (errno == ERANGE || end == rate.c_str())
		{
			std::cout << "Error: failed to parse exchange rate data" << std::endl;
			file.close();
			exit(1);
		}
	}
	file.close();
}

void BitcoinExchange::parseDate(
	const std::string &date, int *year, int *month, int *day) const
{
	size_t date_delimiter_1 = date.find('-');
	if (date_delimiter_1 == std::string::npos) throw std::exception();
	size_t date_delimiter_2 = date.find('-', date_delimiter_1 + 1);
	if (date_delimiter_2 == std::string::npos) throw std::exception();

	int delimiter_count = 0;
	for (size_t i = 0; i < date.size(); i++)
		if (date[i] == '-') delimiter_count++;
		else if (!isdigit(date[i])) throw std::exception();
	if (delimiter_count != 2) throw std::exception();

	*year = strtol(date.substr(0, date_delimiter_1).c_str(), nullptr, 10);
	*month = strtol(date.substr(date_delimiter_1 + 1, date_delimiter_2).c_str(), nullptr, 10);
	*day = strtol(date.substr(date_delimiter_2 + 1, date.size()).c_str(), nullptr, 10);

	if (errno == ERANGE
		|| *year > 9999 || *month > 12 || *day > 31
		|| *year < 1 || *month < 1 || *day < 1)
		throw std::exception();
}

std::string BitcoinExchange::findClosestDate(
	const std::map<std::string, double> &map, int year, int month, int day) const
{
	while (year > 2008)
	{
		while (month > 0)
		{
			while (day > 0)
			{
				std::ostringstream convert;
				convert << year << '-' << month << '-' << day;
				std::string nearest_date(convert.str());
				if (map.count(nearest_date)) return nearest_date;
				day--;
			}
			day = 31;
			month--;
		}
		month = 12;
		year--;
	}
	throw std::exception();
}

void BitcoinExchange::parseInputLine(
	const std::string &line, std::string &date, double *value) const
{
	size_t line_delimiter = line.find(" | ");
	if (line_delimiter == std::string::npos) throw std::exception();
	date = line.substr(0, line_delimiter);
	std::string value_str = line.substr(line_delimiter + 3, line.size());
	char *end;
	*value = strtod(value_str.c_str(), &end);
	if (end != &(*value_str.end()) || *value < 0 || *value > 1000) throw std::exception();
}
