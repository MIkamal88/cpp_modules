#include "BitcoinExchange.hpp"
#include <string>

// Constructors and Destructor
BitcoinExchange::BitcoinExchange(void) : _database() {
  try {
    _loadDatabase();
  } catch (std::exception &e) {
    throw DatabaseLoadException(e.what());
  }
  _minDate = _database.begin()->first;
  _maxDate = _database.rbegin()->first;
}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) {
  this->_database = src._database;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src) {
  this->_database = src._database;
  return *this;
}

// Member Function
/**
 * @brief This function is used to parse the input file and pass the date and
 * fval to _btc function for processing
 *
 * @param filename The name of the file to be read
 */
void BitcoinExchange::readInput(std::string filename) {
  std::ifstream file(filename.c_str());
  std::string line;
  std::string date;
  std::string value;
  float fval;

  if (!file.is_open())
    throw InputNotFoundException();
  std::getline(file, line);
  if (!_checkHeader(line, INPUT))
    throw BadInputFormatException();
  while (std::getline(file, line)) {
    try {
      _checkLine(line, INPUT);
    } catch (std::exception &e) {
      std::cout << "Error: " << e.what() << std::endl;
      continue;
    }
    date = line.substr(0, line.find('|'));
    value = line.substr(line.find('|') + 1);
    fval = std::stof(value.c_str());
    _btc(date, fval);
  }
}

// Functions
/**
 * @brief This function is used to load the database from the file into
 * _database map assuming proper format.
 */
void BitcoinExchange::_loadDatabase(void) {
  std::string filename = DATA_FILE;
  std::ifstream file(filename.c_str());
  std::string line;
  std::string date;
  std::string value;
  float fval;

  if (!file.is_open()) {
    throw DatabaseNotFoundException();
    return;
  }
  std::getline(file, line);
  if (!_checkHeader(line, DATABASE))
    throw BadDatabaseFormatException();
  else {
    while (std::getline(file, line)) {
      try {
        _checkLine(line, DATABASE);
      } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        throw BadDatabaseFormatException();
        break;
      }
    }
  }
}
