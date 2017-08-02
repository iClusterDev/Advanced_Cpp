#include <iostream>
#include <fstream>
#include <exception>
#include <string>

//custom exception
class File_Not_Opened : std::exception {

public:

	const char* what() const override {
		return "Cannot open the File";
	}

};


//writer() - writes on a file the argument str
void writer(const std::string &str, const std::string fileName) {

	std::fstream outStream;

	outStream.open(fileName);

	if (!outStream.is_open()) {
		throw File_Not_Opened();
	}
	else {
		outStream << str << std::endl;
		outStream.close();
	}

}


//app entry point
int main() {

	try	{
		writer("Hello There!", "Text.txt");
	}
	catch (const File_Not_Opened& e) { 
		std::cout << e.what() << std::endl;
	}	

	std::cin.get();
}