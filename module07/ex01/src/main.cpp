#include "./iter/iter.hpp"

int main()
{
	char arrayChar[] = {'h','i','v','e'};
	int arrayInt[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	iter(arrayInt, 10, printElem<int>);
	iter(arrayChar, 4, printElem<const char>);
}

// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }

// template< typename T >
// void print( T& x )
// {
//   std::cout << x << std::endl;
//   return;
// }

// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];

//   iter( tab, 5, print<const int> );
//   iter( tab2, 5, print<Awesome> );

//   return 0;
// }