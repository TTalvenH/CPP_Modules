#include "RPN.hpp"
#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <limits>

RPN::RPN(){}

RPN::~RPN(){}

bool RPN::overflowCheck(int a, int b, char _operator) const
{
	typedef std::numeric_limits<int> limits;

    if (_operator == '+')
	{
        if ((b > 0 && a > limits::max() - b) || (b < 0 && a < limits::min() - b))
            return true;
    }
	else if (_operator == '-')
	{
        if ((b > 0 && a < limits::min() + b) || (b < 0 && a > limits::max() + b))
            return true;
    }
	else if (_operator == '*')
	{
        if (a > 0 && (b > limits::max() / a || b < limits::min() / a))
            return true;
        if (a < 0 && (b > 0 && a < limits::min() / b))
            return true;
    }
	else if (_operator == '/')
	{
        if (b == 0)
            return true;
    }
    return false; 
}

bool RPN::isValidToken(std::string token) const
{
	if (token.length() != 1
		||(!std::isdigit(token[0])
		&& !(  token[0] == '+'
			|| token[0] == '-'
			|| token[0] == '*'
			|| token[0] == '/')))
		return false;
	return true;
	
}

void RPN::calculate(std::string expression)
{
	std::stack<int>		stack;
	std::istringstream	stream(expression);
	std::string			token;

	while (stream >> token)
	{
		if (!isValidToken(token))
			throw std::runtime_error("Error: invalid token.");
		if (std::isdigit(token[0]))
			stack.push(std::atoi(token.c_str()));
		else if (stack.size() >= 2)
		{
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();
			if (overflowCheck(a, b, token[0]))
				throw std::runtime_error("Error: overflow or dividing by zero.");
			if (token[0] == '+')
				stack.push(a + b);
			else if (token[0] == '-')
				stack.push(a - b);
			else if (token[0] == '*')
				stack.push(a * b);
			else if (token[0] == '/')
				stack.push(a / b);
		}
		else
			throw std::runtime_error("Error: invalid expression.");

	}

	if (stack.size() == 1 && !stack.empty())
		std::cout << stack.top() << std::endl;
	else
		throw std::runtime_error("Error");
}
