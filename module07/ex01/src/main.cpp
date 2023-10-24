#include "./iter/iter.hpp"

int main()
{
	char arrayChar[] = {'h','i','v','e'};
	int arrayInt[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	iter(arrayInt, 10, printElem);
	iter(arrayChar, 4, printElem);
}