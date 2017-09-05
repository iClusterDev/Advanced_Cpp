#include <iostream>
#include <string>

//a simple class for managing Key Value Pairs
class KeyValue {
private:
	std::string _key;
	int _value;

public:
	//default constructor
	KeyValue() = default;

	//overloaded constructor
	KeyValue(std::string key, int value) : _key(key), _value(value) {};

	//overloaded assignment operator
	const KeyValue& operator=(const KeyValue& source) {
		this->_key = source._key;
		this->_value = source._value;
		return *this;
	}

	//copy constructor
	KeyValue(const KeyValue& source) { *this = source; }

	//destructor
	~KeyValue() {};

	//this must be declared as friend (if needs access to private members)
	friend std::ostream& operator<<(std::ostream& outStream, const KeyValue& source);

};

//implementation of the overloaded left bit shift operator
//this returns a reference to ostream object because
//the left shift bit is a left to right operator
std::ostream& operator<<(std::ostream& outStream, const KeyValue& source) {
	outStream << source._key << " - " << source._value;
	return outStream;
}

int main() {

	KeyValue test1("Fabio", 38);

	std::cout << test1 << std::endl;

	std::cin.get();
}