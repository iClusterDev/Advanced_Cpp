#include <iostream>
#include <string>

//template functions can be stand-alone functions or methods of template classes
//in the template definition <class T> sometimes is replaced with <typename T>
//this because the type passed to the template doesn't have to be only a class type,
//but could be also a primitive type (so typename is preferred)

//when calling template functions we don't need to specify the type like this: function<type>
//because the compiler will infer the type looking at the argument passed to the function

template<typename Ty>
void Print(const Ty &item) {
	std::cout << item << std::endl;
}

int main() {

	Print<int>(10);
	Print<float>(0.45f);
	Print<std::string>("hello");
	Print("Type Inference");

	std::cin.get();
}