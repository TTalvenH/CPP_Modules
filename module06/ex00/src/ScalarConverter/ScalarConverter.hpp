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

public:

	static void convert(std::string& input);
};

void convertChar(const std::string& input);
void convertInt(const std::string& input);
void convertFloat(const std::string& input);
void convertDouble(const std::string& input);

#endif