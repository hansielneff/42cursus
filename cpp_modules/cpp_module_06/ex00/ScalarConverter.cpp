#include "ScalarConverter.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

void ScalarConverter::convert(std::string &str)
{
	char c = 0;
	int i = 0;
	float f = 0;
	double d = 0;

	bool c_possible = true;
	bool i_possible = true;

	if (str.compare("-inff") == 0 || str.compare("-inf") == 0)
	{
		f = -std::numeric_limits<float>::infinity();
		d = -std::numeric_limits<double>::infinity();
		c_possible = false;
		i_possible = false;
	}
	else if (str.compare("+inff") == 0 || str.compare("+inf") == 0)
	{
		f = std::numeric_limits<float>::infinity();
		d = std::numeric_limits<double>::infinity();
		c_possible = false;
		i_possible = false;
	}
	else if (str.compare("nanf") == 0 || str.compare("nan") == 0)
	{
		f = std::numeric_limits<float>::quiet_NaN();
		d = std::numeric_limits<double>::quiet_NaN();
		c_possible = false;
		i_possible = false;
	}
	else if (str.find('.') != std::string::npos && str.find('f') != std::string::npos)
	{
		try { f = std::stof(str); } catch (std::exception &e)
		{
			std::cout << "Invalid input!" << std::endl;
			return;
		}
		d = static_cast<double>(f);
		c = static_cast<char>(f);
		i = static_cast<int>(f);
	}
	else if (str.find('.') != std::string::npos)
	{
		try { d = std::stod(str); } catch (std::exception &e)
		{
			std::cout << "Invalid input!" << std::endl;
			return;
		}
		f = static_cast<float>(d);
		c = static_cast<char>(d);
		i = static_cast<int>(d);
	}
	else if (str.size() == 1)
	{
		c = str.at(0);
		d = static_cast<double>(c);
		f = static_cast<float>(c);
		i = static_cast<int>(c);
	}
	else
	{
		try { i = std::stoi(str); } catch (std::exception &e)
		{
			std::cout << "Invalid input!" << std::endl;
			return;
		}
		d = static_cast<double>(i);
		f = static_cast<float>(i);
		c = static_cast<char>(i);
	}

	if (!c_possible)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
	
	if (!i_possible)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;

	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}
