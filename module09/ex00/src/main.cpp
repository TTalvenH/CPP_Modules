#include "./BitcoinExhange/BitcoinExchange.hpp"

int main(int argc, char* argv[])
{
	if (argc == 2)
	{
		try
		{
			BitcoinExchange exchange("./db/data.csv", argv[1]);

			exchange.printConversion();
	
		}	
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cout << "Error: could not open file." << std::endl;
	return 0;
}