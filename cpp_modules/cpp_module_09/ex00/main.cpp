#include <iostream>

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: ./btc input_file" << std::endl;
		return 1;
	}
	
	std::string exchange_file = "data.csv";
	std::string input_file = argv[1];
	BitcoinExchange btc(exchange_file);
	btc.printPrices(input_file);
	return 0;
}
