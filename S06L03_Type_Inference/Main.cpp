#include <iostream>
#include <string>

//template definition
template<typename Ty>
void Print(const Ty& value) {
	std::cout << "Template version: " << value << std::endl;
}

//overloaded function definition
void Print(const int& value) {
	std::cout << "Non Template version: " << value << std::endl;
}


int main() {

	//normal template call
	Print<int>(55);

	//type inference happens when the <type> is not specified at the template function call
	Print(66);

	//however if an overloaded function exist and provides a better 
	//argument list match, this is going to have precedence over the 
	//template version
	Print(77);

	//in the case of an overloaded function precedence, we can explicitly choose to execute
	//the templated version using the following syntax:
	Print<>(88);

	std::cin.get();
}