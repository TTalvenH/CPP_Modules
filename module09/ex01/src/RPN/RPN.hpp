#ifndef RPN_HPP
#define RPN_HPP

#include <string>

class RPN
{
private:
	RPN(const RPN& copy);
	RPN& operator=(const RPN& copy);

	bool isValidToken(std::string token) const;

public:
	RPN();
	~RPN();
	
	void calculate(std::string expression);
};

#endif