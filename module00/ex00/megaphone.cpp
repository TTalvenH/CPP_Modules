#include <iostream>
#include <string>
#include <cctype>

void	StringToUpper(char* str){
	for(size_t i = 0; str[i] != '\0'; i++){
		str[i] = std::toupper(static_cast<unsigned char>(str[i]));
	}
}

int	main(int argc, char **argv){
	if (argc == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for(int i = 1; i < argc; i++){
		StringToUpper(argv[i]);
		for(size_t j = 0; argv[i][j] != '\0'; j++){
			std::cout << argv[i][j];
		}
	}
	std::cout << std::endl;
}
