#include <iostream>
#include <string>

//a derived custom exception
class invalid_operation : public std::exception {
public:
	const char* what() const noexcept {
		return "items are not the same!";
	}
};

//a simple item class
class item {
	//overloaded shift bit operator
	friend std::ostream& operator<<(std::ostream& out, const item& item) {
		out << "id: " + item._id + " - name: " + item._name + " - quantity: " << item._quantity;
		return out;
	}

	//overloaded plus
	//the overloaded plus returns a new object
	//in this case the plus operation has got a specific logic behind
	friend item operator+(const item& lhs, const item& rhs) {
		if (!((lhs._id == rhs._id) && (lhs._name == rhs._name))) {
			throw invalid_operation();
		}
		else {
			return item(lhs._id, lhs._name, lhs._quantity + rhs._quantity);
		}
	}

private:
	//properties
	std::string _id;
	std::string _name;
	int _quantity;

public:
	//costructors 
	//note the constructor chaining
	item() {
		_id = "empty";
		_name = "empty";
		_quantity = 0;
	};
	item(std::string id) : item() { _id = id; }
	item(std::string id, std::string name) : item(id) { _name = name; }
	item(std::string id, std::string name, int quantity) : item(id, name) { _quantity = quantity; }

	//destructor
	~item() {}

	//copy constructor
	item(const item& source) {
		*this = source;
	}

	//overloaded assignment
	item& operator=(const item& sourceItem) {
		_id = sourceItem._id;
		_name = sourceItem._name;
		_quantity = sourceItem._quantity;
		return *this;
	}

	//overloaded += (this is calling the overloaded plus)
	item& operator+=(const item& rhs) {
		*this = *this + rhs;
		return *this;
	}
};



int main() {

	item i1("4", "gun", 30);
	item i2("4", "gun", 20);
	item i3("4", "gun", 50);

	i1 += (i2 + i3);

	std::cout << i1 << std::endl;
	std::cout << i2 << std::endl;
	std::cout << i3 << std::endl;

	std::cin.get();
}