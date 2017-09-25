#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//a function defining the result of some search criteria
bool Match(int value) {
	return value == 7;
}

//this is a custom implementation of count_if (just for exercise)
//this function takes as a second argument a function pointer defining the 
//test criteria
int myCount_if(std::vector<int> &container, bool(*predicate)(int test)) {
	int result = 0;
	for (auto it : container) {
		if (predicate(it))
			result++;
	}
	return result;
}

int main() {

	//this is a vector containing numbers
	std::vector<int> numbers;
	numbers.push_back(8);
	numbers.push_back(5);
	numbers.push_back(0);
	numbers.push_back(2);
	numbers.push_back(7);
	numbers.push_back(0);
	numbers.push_back(7);

	//here we call count_if passing a function pointer as third argument (Match)
	//this is to show that function pointers are often used with std algorithm
	//std::cout << std::count_if(numbers.begin(), numbers.end(), Match) << std::endl;
	//std::cout << std::endl;

	//here we do the same thing with our custom function
	std::cout << myCount_if(numbers, Match) << std::endl;

	std::cin.get();
}