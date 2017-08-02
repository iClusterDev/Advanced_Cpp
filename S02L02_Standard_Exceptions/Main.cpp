#include <iostream>


//a class that might throw an exception from its constructor
//note that the exception thrown belongs to the base
//std::exception (bad_alloc)
class MightGoWrong {

public:
	MightGoWrong() {
		MightThrow();
	}

private:
	void MightThrow() {
		bool error = true;
		if (error) throw std::bad_alloc();
	}
};


int main() {

	//the std::exception base class has a virtual what()
	//to print info about the exception thrown
	try {
		MightGoWrong testMemory;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}	

	std::cin.get();
}