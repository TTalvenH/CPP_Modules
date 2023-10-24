#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter &);
	~ScalarConverter();
	static void convertChar(const std::string& input);
	static void convertInt(const std::string& input);
	static void convertFloat(const std::string& input);
	static void convertDouble(const std::string& input);
	static void validInput(const std::string& input);

public:

	static void convert(std::string& input);
};

#endif