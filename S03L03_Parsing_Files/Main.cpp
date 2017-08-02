#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

int main() {

	std::string fileName = "book.txt";
	std::fstream inputStream(fileName, std::fstream::in);
	
	std::vector<std::string> bookName;
	std::vector<std::string> bookPrice;

	if (inputStream) {
		std::string line;
		while (std::getline(inputStream, line)) {
			std::stringstream record(line);
			std::string name;
			std::string price;
			record >> name >> price;
			bookName.push_back(name);
			bookPrice.push_back(price);
		}
	}

	for (auto &r : bookName) {
		std::cout << r << std::endl;
	}

	for (auto &r : bookPrice) {
		std::cout << r << std::endl;
	}

	inputStream.close();

	std::cin.get();
}