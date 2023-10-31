#ifndef RPN_HPP
#define RPN_HPP

#include <string>

class RPN
{
private:
	RPN(const RPN& copy);
	RPN& operator=(const RPN& copy);

	bool isValidToken(std::string token) const;
	bool overflowCheck(int a, int b, char _operator) const;
public:
	RPN();
	~RPN();
	
	void calculate(std::string expression);
};

#endif