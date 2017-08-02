#include <iostream>

//custom exception class deriving from std::exception
class MyException : public std::exception {

public:

	const char* what() const noexcept {
		return "MyException: Something bad Happened!";
	}

};

//a generic class using the custom exception
class Test {

public:

	void GoesWrong() {
		throw MyException();
	}

};



int main() {

	Test test;

	try {
		test.GoesWrong();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cin.get();
}