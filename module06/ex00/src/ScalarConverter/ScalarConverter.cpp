#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <limits>
#include <iomanip>

static char		_char = 0;
static int		_int = 0;
static float	_float = 0;
static double	_double = 0;
static bool		_isImpossible = false;

void convertChar(const std::string& input)
{
	std::istringstream	_stream(input);
	if (_stream >> _char)
	{
		_int = static_cast<int>(_char);
		_float = static_cast<float>(_char);
		_double = static_cast<double>(_char);
	}
	else
	{
		std::cerr << "Invalid input!!!" << std::endl; return;
	}
}

void convertInt(const std::string& input)
{
	std::istringstream	_stream(input);

	if (_stream >> _int)
	{
		_char = static_cast<char>(_int);
		_float = static_cast<float>(_int);
		_double = static_cast<double>(_int);
	}
	else
	{
		std::cerr << "Invalid input!!!" << std::endl; return;
	}
}

void convertFloat(const std::string& input)
{
	std::istringstream	_stream(input);

	if (_stream >> _float)
	{
		_char = static_cast<char>(_float);
		_int = static_cast<int>(_float);
		_double = static_cast<double>(_float);
	}
	else
	{
		std::cerr << "Invalid input!!!" << std::endl; return;
	}
}

void convertDouble(const std::string& input)
{
	std::istringstream	_stream(input);

	if (_stream >> _double)
	{
		_char = static_cast<char>(_double);
		_int = static_cast<int>(_double);
		_float = static_cast<float>(_double);
	}
	else
	{
		std::cerr << "Invalid input!!!" << std::endl; return;
	}
}

void ScalarConverter::convert(std::string& input)
{
	if (  !input.compare("+inff") || !input.compare("-inff")
		||!input.compare("+inf")  || !input.compare("-inf"))
	{
		_float = std::numeric_limits<float>::infinity();
		_double = std::numeric_limits<double>::infinity();
		_isImpossible = true;
	}
	else if (!input.compare("nanf") || !input.compare("nan"))
	{
		_float = std::numeric_limits<float>::quiet_NaN();
		_double = std::numeric_limits<double>::quiet_NaN();
		_isImpossible = true;
	}
	else if (input.length() == 1 && !std::isdigit(input[0]))
		convertChar(input);
	else if (input.find('f') != std::string::npos)
		convertFloat(input);
	else if (input.find('.') != std::string::npos)
		convertDouble(input);
	else
		convertInt(input);

	if (_isImpossible)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		std::cout << "char: ";
		if (_int < 32 || _int > 126)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << _char << std::endl;
		std::cout << "int: " << _int << std::endl;
	}
	std::cout << std::fixed << std::setprecision(1) <<  "float: " << _float << "f" << std::endl;
	std::cout << "double: " << _double << std::endl;
}

