#include "Iter.hpp"

int main(void) {
	int arr[5] = {1, 2 , 3, 4, 5};
	std::string arr2[5] = {"one", "two", "three", "four", "five"};

	std::cout << "Printing integers in an array1" << std::endl;
	::iter(arr, 5, print<int>);
	std::cout << "Printing strings in an array2" << std::endl;
	::iter(arr2, 5, print<std::string>);
}
