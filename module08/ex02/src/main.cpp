#include "./MutantStack/MutantStack.hpp"
#include <iostream>
#include <list>
int main()
{
	{
	std::cout << "\n=================My tests===================" <<  std::endl;
	MutantStack<std::string> stringStack;

	stringStack.push("Hey");
	stringStack.push("Hoi");
	stringStack.push("Hai!");

	MutantStack<std::string> copyStack(stringStack);
	std::cout << "copyStack(stringStack)" << std::endl;
	MutantStack<std::string>::iterator it = copyStack.begin();
	MutantStack<std::string>::iterator ite = copyStack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << "copyStack: " << *it << std::endl;
	++it;
	}

	copyStack.pop();
	copyStack.pop();
	copyStack.pop();
	std::cout << "copyStack popped" << std::endl;
	it = stringStack.begin();
	ite = stringStack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << "stringStack: " << *it << std::endl;
	++it;
	}

	copyStack = stringStack;
	stringStack.pop();
	stringStack.pop();
	stringStack.pop();
	std::cout << "copyStack = stringStack and stringStack popped" << std::endl;

	const MutantStack<std::string> constStack(copyStack);
	copyStack.pop();
	copyStack.pop();
	copyStack.pop();
	std::cout << "constStack(copyStack) and copyStack popped" << std::endl;

	MutantStack<std::string>::const_iterator constIt = constStack.begin();
	MutantStack<std::string>::const_iterator constIte = constStack.end();
	++constIt;
	--constIt;
	while (constIt != constIte)
	{
	std::cout << "constStack: " << *constIt << std::endl;
	++constIt;
	}

	}


	{
	std::cout << "\n=================PDF tests===================" <<  std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	}

	{
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	return 0;
	}
}