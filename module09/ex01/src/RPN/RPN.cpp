#include "RPN.hpp"
#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>

RPN::RPN(){}

RPN::~RPN(){}

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
			throw std::runtime_error("Error");
		if (std::isdigit(token[0]))
			stack.push(std::atoi(token.c_str()));
		else if (stack.size() >= 2)
		{
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();

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
			throw std::runtime_error("Error");

	}

	if (stack.size() == 1 && !stack.empty())
		std::cout << stack.top() << std::endl;
	else
		throw std::runtime_error("Error");
}
