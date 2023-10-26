#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>

template < typename T >
class MutantStack: public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		MutantStack();
		MutantStack(const MutantStack& mstack);
		MutantStack& operator=(const MutantStack& mstack);
		~MutantStack();

		iterator 		begin();
		const_iterator	begin() const;
		iterator		end();
		const_iterator	end() const;
};

#include "MutantStack.tpp"

#endif