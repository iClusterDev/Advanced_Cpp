#include <iostream>
#include <fstream>
#include <string>


int main() {

	//first creates a test file
	std::string fileName = "test.txt";

	std::ofstream outStream;

	outStream.open(fileName);

	if (!outStream.is_open()) {
		std::cout << "Cannot open the file: " << fileName << std::endl;
	}
	else {
		outStream << "This is a test file" << std::endl;
		outStream.close();
	}


	//now reads in the file: test.txt
	std::ifstream inStream(fileName);

	std::string fileContent;

	if (!inStream.is_open()) {
		std::cout << "Cannot open the file: " << fileName << std::endl;
	}
	else {		
		while (inStream) {
			std::getline(inStream, fileContent);
			std::cout << fileContent << std::endl;
		}		
	}

	std::cin.get();
}