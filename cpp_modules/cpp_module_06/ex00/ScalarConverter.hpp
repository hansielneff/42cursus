#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <string>

class ScalarConverter
{
public:
	static void convert(std::string &str);
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &scalarConverter);
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &scalarConverter);
};

#endif
