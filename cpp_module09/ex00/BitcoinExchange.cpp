#include "BitcoinExchange.hpp"

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
    fval = std::atof(value.c_str());
    _btc(date, fval);
  }
}

// Functions

/**
 * @brief This function calculates the value of BTC for a given date and value
 It will search in the _database map for a given date, if not found it will
 search for the last date. BTC value = exchange_rate * given value
 *
 * @param std::string date The date to look for.
 * @param fval The float value of 1 coin
 */
void BitcoinExchange::_btc(std::string date, float value) {
  std::map<std::string, float>::iterator it = _database.find(date);
  std::string last_date;
  float last_value;

  if (it != _database.end()) {
    std::cout << date << " => " << value << " = " << value * it->second
              << std::endl;
    return;
  }
  for (it = _database.begin(); it != _database.end(); it++) {
    if (it->first > date)
      break;
    last_date = it->first;
    last_value = it->second;
  }
  std::cout << date << " => " << value << " = " << value * last_value
            << std::endl;
}

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
      date = line.substr(0, line.find(','));
      value = line.substr(line.find(',') + 1);
      fval = std::atof(value.c_str());
      _database[date] = fval;
    }
  }
  file.close();
  return;
}

/**
 * @brief This function trims the string, removing any leading or trailing
 * spaces.
 *
 * @param string The line to be trimmed
 */
void BitcoinExchange::_trimWS(std::string &cell) {
  size_t start = cell.find_first_not_of(" \t");
  size_t end = cell.find_last_not_of(" \t");

  // If the string was all spaces or tabs, it is set to empty string
  if (start == std::string::npos)
    cell = "";
  else
    cell = cell.substr(start, end - start + 1);
}

/**
 * @brief This function is used to check the header of the file
 *
 * @param header The line to be checked
 * @param type The type of the file
 *
 * @return boolean whether the header is correct or not
 */
bool BitcoinExchange::_checkHeader(std::string header, input_type type) {
  char delimiter;
  std::string col1 = "date";
  std::string col2;

  if (type == DATABASE) {
    col2 = "exchange_rate";
    delimiter = ',';
  } else {
    col2 = "value";
    delimiter = '|';
  }

  // Check if columns are seperated by the right character
  if (std::count(header.begin(), header.end(), delimiter) != 1)
    return false;

  std::string header1 = header.substr(0, header.find(delimiter));
  std::string header2 = header.substr(header.find(delimiter) + 1);
  _trimWS(header1);
  _trimWS(header2);
  if (header1 == col1 && header2 == col2)
    return true;
  return false;
}

/**
 * @brief This function checks if the line has the correct format for the given
 file type.
 If type is DATABASE, the line has two columns seperated by a ','
 If type is INPUT, the line has two columns seperated by a '|'
 Both types are checked for correct date and value formats.
 Dates must be in YYYY-MM-DD and value must be positive integer or float

 * @param header The line to be checked
 * @param type The type of the file (DATABASE or INPUT)
 */
void BitcoinExchange::_checkLine(std::string line, input_type type) {
  char delimiter;
  if (type == DATABASE)
    delimiter = ',';
  else
    delimiter = '|';

  int delimiter_count = std::count(line.begin(), line.end(), delimiter);
  if (delimiter_count != 1) {
    throw BadInputDataException(line);
    return;
  }

  std::string date = line.substr(0, line.find(delimiter));
  std::string value = line.substr(line.find(delimiter) + 1);
  _trimWS(date);
  _trimWS(value);
  if (!date.length() || !value.length())
    throw BadInputDataException(line);
  if (!_checkDate(date, type))
    throw BadInputDataException(line);
  else if (!_checkValue(value, type)) {
    if (std::atof(value.c_str()) < 0)
      throw NegativeValueException();
    else if (std::atof(value.c_str()) > 1000)
      throw TooLargeValueException();
    else
      throw BadInputDataException(line);
  }
}

/**
 * @brief This function checks if the date has the correct format for the given
 file type.
 Dates must be in YYYY-MM-DD and value must be positive integer or float

 * @param date The date string to be checked
 * @param type The type of the file (DATABASE or INPUT)
 *
 * @return boolean whether the date is correct or not
 */
static bool isLeapYear(int year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::_checkDate(std::string date, input_type type) {
  if (date.length() != 10)
    return false;
  for (int i = 0; i < 10; i++) {
    if (i == 4 || i == 7) {
      if (date[i] != '-')
        return false;
    } else if (!std::isdigit(date[i]))
      return false;
  }
  if (type == INPUT && date < _minDate)
    return false;
  int year = std::atoi(date.substr(0, 4).c_str());
  int month = std::atoi(date.substr(5, 2).c_str());
  int day = std::atoi(date.substr(8, 2).c_str());
  if (day < 1)
    return false;
  switch (month) {
    case 2:
      if (isLeapYear(year) && day > 29)
        return false;
      if (!isLeapYear(year) && day > 28)
        return false;
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      if (day > 30)
        return false;
      break;
    default:
      if (day > 31)
        return false;
  }
  return true;
}

/**
 * @brief This function checks if the value is a positive float or integer

 * @param value The value string to be checked
 * @param type The type of the file (DATABASE or INPUT)
 *
 * @return boolean whether the value is correct or not
 */
bool BitcoinExchange::_checkValue(std::string value, input_type type) {
  bool dot = false;

  for (size_t i = 0; i < value.length(); i++) {
    if (value[i] == '.') {
      if (dot)
        return false;
      dot = true;
    } else if (!std::isdigit(value[i]))
      return false;
  }
  if (type == INPUT && std::atof(value.c_str()) > 1000)
    return false;
  if (type == INPUT && std::atof(value.c_str()) < 0)
    return false;
  return true;
}
