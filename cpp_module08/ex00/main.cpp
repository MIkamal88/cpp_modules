#include "easyfind.hpp"

int main() {
  std::list<int> lst;
  std::vector<int> vec;
  std::deque<int> deq;

  for (int i = 0; i < 10; i++) {
    lst.push_back(i);
    vec.push_back(i);
    deq.push_back(i);
  }

	// Attempting to find 5 and 10 in Lists Containers
  try {
    std::cout << "List: Looking for 5" << std::endl;
    std::cout << *easyfind(lst, 5) << std::endl;
    std::cout << "List: Looking for 10" << std::endl;
    std::cout << *easyfind(lst, 10) << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
	// Attempting to find 5 and 10 in Vector Containers
  try {
    std::cout << "Vector: Looking for 5" << std::endl;
    std::cout << *easyfind(vec, 5) << std::endl;
    std::cout << "Vector: Looking for 10" << std::endl;
    std::cout << *easyfind(vec, 10) << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
	// Attempting to find 5 and 10 in Deque Containers
  try {
    std::cout << "Deque: Looking for 5" << std::endl;
    std::cout << *easyfind(deq, 5) << std::endl;
    std::cout << "Deque: Looking for 10" << std::endl;
    std::cout << *easyfind(deq, 10) << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return (0);
}
