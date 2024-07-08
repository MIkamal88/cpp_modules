#include "Span.hpp"

int main(void) {
  std::cout << RED << "---- Test 1 ----" << RESET << std::endl;
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);

  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;

  std::cout << RED << "---- Test 2 ----" << RESET << std::endl;
  try {
    sp.addNumber(100);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

	std::cout << RED << "---- Test 3 ----" << RESET << std::endl;
	Span sp3 = Span(10000);
	// Random filling the container
	std::srand(time(NULL));
	for (int i = 0; i < 10000; i++)
		sp3.addNumber(std::rand() % 10000);
	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;

	return EXIT_SUCCESS;
}
