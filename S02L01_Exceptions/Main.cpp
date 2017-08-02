#include <iostream>
#include <string>


//A function calling MightThrowException() 
void MightThrowException() {

	bool error1 = false;
	bool error2 = true;
	bool error3 = false;

	if (error1) throw 8;
	if (error2) throw "Char* error";
	if (error3) throw std::string("string error");

}

//A function that might throw an exception
void UsesMightThrowException() {

	MightThrowException();

}


int main() {
	
	//exceptionn handling block
	try {
		UsesMightThrowException();
	}
	catch (int e) {
		std::cout << "Error Code: " << e << std::endl;
	}
	catch (const char * e) {
		std::cout << "Error Code: " << e << std::endl;
	}
	catch (std::string &e) {
		std::cout << "Error Code: " << e << std::endl;
	}

	std::cin.get();
}