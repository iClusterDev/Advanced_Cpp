#include <iostream>

//GoesWrong() might throw three different exceptions
void GoesWrong() {

	bool error1 = false;
	bool error2 = false;
	bool error3 = true;

	if (error1) throw std::bad_alloc();
	if (error2) throw std::runtime_error("Runtime Error");
	if (error3) throw std::exception();

}


int main() {

	//in the try - catch block always start with the most
	//specific kind of exceptions. The generic catch case should
	//be in the end
	try {
		GoesWrong();
	}
	catch (std::bad_alloc &e) {
		std::cout << "Catching bad-alloc: " << e.what() << std::endl;
	}
	catch (std::runtime_error &e) {
		std::cout << "Catching runtime error: " << e.what() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Catching exception: " << e.what() << std::endl;
	}

	std::cin.get();
}