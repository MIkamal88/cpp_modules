#include "RPN.hpp"

int main(int argc, char **argv) {
  RPN rpn;

  if (argc != 2) {
    std::cout << "Usage: ./RPN \"<expression>\"" << std::endl;
    return (EXIT_FAILURE);
  }
  try {
		std::cout << rpn.calculate(argv[1]) << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return (EXIT_SUCCESS);
}
