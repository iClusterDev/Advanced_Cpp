#include <iostream>
#include <string>

//function pointers are mainly used to pass blocks of code to other functions
//(think at the std::algorithm where functions take predicates)
//lambda expression are an alternative to function pointers;
//we create a function and so a pointer to that function. through this we can pass an entire block of code
//to another function;
//the virtual keyword is an instruction to make cpp creating a vtable (a table of function pointers);


//a simple parameterless function
void Test() {
	std::cout << "hello" << std::endl;
}

//a function with a return type and parameter list
std::string myName(std::string name) {
	return ("Hello " + name);
}

int main() {

	//the trick here is to think at the function name as a pointer to
	//the actual function. when we call the call operator() we are dereferencing
	//that pointer and we return the function return type
	//this is a standard function call
	Test();

	//this is a function pointer:
	//we need the function return type (void pointers can point to any type)
	//we declare a pointer within brackets (to avoid ambiguity)
	//we specify that this is a pointer to function with the final ();
	void(*pTest)() = Test;

	//here we call tie function pointer
	//note that the () operator is dereferencing that pointer
	pTest();

	//example:
	//a function pointer to myName()
	std::string(*myName_ptr)(std::string) = myName;

	//a call to myName throughg the pointer
	std::cout << myName_ptr("Fabio") << std::endl;

	//this will give the address of the function pointer
	std::cout << myName_ptr << std::endl;


	std::cin.get();
}