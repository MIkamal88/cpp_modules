#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << RED "Usage: ./btc ./input.txt" RESET << std::endl;
    return (1);
  } else {
    try {
      BitcoinExchange btc;
      btc.readInput(argv[1]);
    } catch (std::exception &e) {
      std::cerr << RED << e.what() << RESET << std::endl;
      return (EXIT_FAILURE);
    }
  }
  return (EXIT_SUCCESS);
}
