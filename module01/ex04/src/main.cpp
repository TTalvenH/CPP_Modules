#include <string>
#include <iostream>
#include <fstream>

int	main(int argc, char *argv[]){
	if (argc == 4){
		std::string		line;
		std::string		fileName = argv[1];
		std::string		oldWord = argv[2];
		std::string		newWord = argv[3];

		std::fstream	file(fileName, std::ios::in | std::ios::out);
		if (!file.is_open()){
			std::cerr << "Error opening input file!" << std::endl;
			return 1;
		}
		std::fstream	fileOut(fileName + ".replace", std::ios::out);
		if (!fileOut.is_open()){
			std::cerr << "Error opening output file!" << std::endl;
			file.close(); fileOut.close();
			return 1;
		}	
		while (std::getline(file, line)){
			size_t		pos = 0;
			while (oldWord.length() && (pos = line.find(oldWord, pos)) != std::string::npos){
			line.erase(pos, oldWord.length());
			line.insert(pos, newWord);
			pos += newWord.length();
			}
			fileOut << line << std::endl;
		}
		file.close();
		fileOut.close();
	}
	else
		std::cerr << "Error wrong amount of arguments" << std::endl;
	return 0;
}