//the compiler provides a default copy assignement operator (if not defined)
//this however performs a shallow copy only
//there are situations in which a shallow copy is not convenient and 
//an override of the default = operator is required

//the copy assignement must not to be confused to the copy constructor
//the copy assignment overload returns a reference
//the copy constructor has not return type

//rule of 3:
//if you define a copy constructor or overloaded assignement or a destructor, you should define the other two
//it's a good practice to use the copy assignment call in the copy constructor definition
//the destructor is necessary if the class contains pointers to dynamic memory


#include <iostream>
#include <string>


//a simple class with memory allocation in its constructor
class Test {
private:
	//private property (pointer to string)
	std::string* _name = nullptr;

public:
	//constructor (allocates new memory)
	Test() { _name = new std::string(); }

	//constructor (allocates new memory)
	Test(const std::string arg) { _name = new std::string(arg); }

	//copy assignment operator
	const Test& operator=(const Test& source) {
		*_name = *source._name;
		return *this;
	}

	//copy constructor
	Test(const Test& source) { _name = source._name; }

	//destructor (deletes the allocated memory)
	~Test() {
		if (_name) {
			delete _name;
			_name = nullptr;
		}
	}

	//returns the name property
	inline std::string GetName() const { return *_name; }

	//returns the name address property
	inline std::string* GetNameAddress() const { return _name; }
};


int main() {

	Test test1("Fabio");
	Test test2;

	//with the copy assignment defined (deep copy)
	//now test1 and test2 are independent objects
	//storing the same content
	test2 = test1;

	std::cout << test1.GetNameAddress() << " - " << test1.GetName() << std::endl;
	std::cout << test2.GetNameAddress() << " - " << test2.GetName() << std::endl;

	std::cin.get();
}