#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <exception>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <string>

#define DATA_FILE "./data.csv"

// Color Macros
#define RESET "\e[m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"

// Error Macros
#define DBNOTFOUND                                                     \
  "Error reading Database File. Make sure there is a `data.csv` file " \
  "present at the root of the repository with the correct permissions."
#define DBFORMAT                                                            \
  "Bad format in Database file. Please, make sure your database is a .csv " \
  "with two columns: `date,exchange_rate`"
#define DBDATA                                                            \
  "Bad data in Database file. Please, make sure your database is filled " \
  "correctly"
#define INPUTNOTFOUND                                                    \
  "Error reading input file. Make sure your input file exists with the " \
  "right permissions."

#define INPUTFORMAT                                                       \
  "Bad format in input file. Please, make sure your input file is a .txt" \
  "with two columns: `date,exchange_rate`"

enum input_type { DATABASE, INPUT };

// Static Class - Non Instantiable
class BitcoinExchange {
 private:
  BitcoinExchange(BitcoinExchange const &src);
  BitcoinExchange &operator=(BitcoinExchange const &src);

  std::map<std::string, float> _database;
  std::string _minDate;
  std::string _maxDate;

  void _loadDatabase(void);
  void _btc(std::string date, float value);
  bool _checkHeader(std::string line, input_type type);
  void _checkLine(std::string line, input_type type);
  bool _checkDate(std::string value, input_type type);
  bool _checkValue(std::string value, input_type type);
  void _trimCell(std::string &cell);

 public:
  BitcoinExchange(void);
  ~BitcoinExchange(void);

  void readInput(std::string filename);

  // Exception Classes
  class DatabaseLoadException : public std::exception {
   public:
    DatabaseLoadException(std::string err) : _error_message(err){};
    virtual ~DatabaseLoadException(void) throw(){};
    virtual const char *what() const throw() {
      return (_error_message.c_str());
    }

   private:
    std::string _error_message;
  };
  class DatabaseNotFoundException : public std::exception {
    virtual const char *what() const throw() { return (DBNOTFOUND); };
  };
  class BadDatabaseFormatException : public std::exception {
    virtual const char *what() const throw() { return (DBFORMAT); };
  };
  class BadDatabaseDataException : public std::exception {
    virtual const char *what() const throw() { return (DBDATA); };
  };
  class InputNotFoundException : public std::exception {
    virtual const char *what() const throw() { return (INPUTNOTFOUND); };
  };
  class BadInputFormatException : public std::exception {
    virtual const char *what() const throw() { return (INPUTFORMAT); };
  };
  class BadInputDataException : public std::exception {
   public:
    BadInputDataException(std::string line)
        : _error_message("Invalid Input => " + line){};
    virtual ~BadInputDataException(void) throw(){};
    virtual const char *what() const throw() {
      return (_error_message.c_str());
    }

   private:
    std::string _error_message;
  };
  class BadDateException : public std::exception {
   public:
    BadDateException(std::string date)
        : _error_message("Invalid date => " + date){};
    virtual ~BadDateException(void) throw(){};
    virtual const char *what() const throw() {
      return (_error_message.c_str());
    };

   private:
    std::string _error_message;
  };
  class NegativeValueException : public std::exception {
    virtual const char *what() const throw() { return "Negative value"; }
  };
  class TooLargeValueException : public std::exception {
    virtual const char *what() const throw() { return "Too large value"; };
  };
};
#endif
