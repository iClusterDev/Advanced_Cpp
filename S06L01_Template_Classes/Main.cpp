#include <iostream>

//templates allow to work with types specified at instantiation
//an example is the vector class

//important notes:
//a better solution when working with templates is to include
//the prototypes and definitions togethers in the header files
//because cpp compiler needs to compile the class that is specifically
//working with the types specified at the moment of instantiation

template<class Ty>

class vector2d {

public:
	vector2d(Ty x, Ty y) : _x(x), _y(y) {};

	~vector2d() {};

	inline Ty X() const { return this->_x; }

	inline Ty Y() const { return this->_y; }

	inline void Print() const { std::cout << this->_x << " - " << this->_y << std::endl; }

private:
	Ty _x;
	Ty _y;

};

int main() {

	vector2d<double> myVector(5, 6);
	std::cout << myVector.X() << std::endl;
	std::cout << myVector.Y() << std::endl;
	myVector.Print();

	std::cin.get();
}