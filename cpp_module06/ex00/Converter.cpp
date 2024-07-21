/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:08:27 by m_kamal           #+#    #+#             */
/*   Updated: 2024/05/21 20:08:27 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

// Constructors and destructor
Converter::Converter() {}

Converter::Converter(Converter const &src) {
  *this = src;
}

Converter::~Converter() {}

// Operator overloads
Converter &Converter::operator=(Converter const &src) {
  if (this == &src)
    return (*this);
  *this = src;
  return (*this);
}

//-------------------
// Checking Functions
//-------------------
static bool _isChar(const std::string &str) {
  if (str.length() == 1 && std::isalpha(str[0]) && std::isprint(str[0]) &&
      !std::isdigit(str[0]))
    return true;
  return false;
}

static bool _isInt(const std::string &str) {
  size_t len = str.length();
  long nb;

  if (len == 1 && std::isdigit(str[0]))
    return true;
  for (size_t i = 0; i < len; i++) {
    if (i == 0 && (str[i] == '+' || str[i] == '-'))
      i++;
    if (!std::isdigit(str[i]))
      return false;
  }
  nb = std::strtol(str.c_str(), NULL, 10);
  if (nb > MAX_INT || nb < MIN_INT)
    return false;
  return true;
}

static bool _isFloat(const std::string &str) {
  size_t i = 0;
  size_t len = str.length();
  double nb;
  bool dot = false;

  if (str[len - 1] != 'f')
    return false;
  for (; i < len - 1; i++) {
    if (str[i] == '.' && !dot)
      dot = true;
    else if (!std::isdigit(str[i]))
      return false;
  }
  if (!dot)
    return false;
  nb = std::strtod(str.c_str(), NULL);
  if (nb > MAX_FLOAT || nb < MIN_FLOAT)
    return false;
  return true;
}

static bool _isDouble(const std::string &str) {
  size_t i = 0;
  size_t len = str.length();
  double nb;
  bool dot = false;

  if (len == 1 && std::isdigit(str[0]))
    return true;
  for (; i < len; i++) {
    if (str[i] == '.' && !dot)
      dot = true;
    else if (!std::isdigit(str[i]))
      return false;
  }
  if (!dot)
    return false;
  nb = std::strtod(str.c_str(), NULL);
  if (nb > MAX_DBL || nb < MIN_DBL)
    return false;
  return true;
}

int Converter::_getType(const std::string &str) {
  if (_isChar(str))
    return CHAR;
  if (_isInt(str))
    return INT;
  if (_isFloat(str))
    return FLOAT;
  if (_isDouble(str))
    return DOUBLE;
  throw InvalidConversionException();
}

// Member functions
//---------------------
// Conversion Functions
//---------------------
static bool isInfinity(const std::string &str) {
  size_t len = str.length();
  std::string str_cpy(len, ' ');
  std::string infinity[8] = {"inff", "-inff", "+inff", "nanf",
                             "inf",  "-inf",  "+inf",  "nan"};

  for (size_t i = 0; i < len; i++)
    str_cpy[i] = tolower(str[i]);

  for (size_t i = 0; i < 8; i++) {
    if (str_cpy == infinity[i]) {
      std::cout << BLUE << "Char: " << RESET << "Impossible" << std::endl;
      std::cout << YELLOW << "Int: " << RESET << "Impossible" << std::endl;
      std::cout << MAGENTA << "Float: " << RESET
                << strtof(str_cpy.c_str(), NULL) << "f" << std::endl;
      std::cout << CYAN << "Double: " << RESET << strtod(str_cpy.c_str(), NULL)
                << std::endl;
      return true;
    }
  }
  return false;
}

void Converter::printChar(const std::string &str, int &type) {
  if (str.length() == 1 && isprint(str[0]) && !isdigit(str[0]))
    std::cout << BLUE << "Char: " << RESET << "'" << str[0] << "'" << std::endl;
  else if (type == INT || type == FLOAT || type == DOUBLE) {
    long int num = strtod(str.c_str(), NULL);
    if (num > 0 && num <= std::numeric_limits<unsigned char>::max()) {
      if (isprint(num))
        std::cout << BLUE << "Char: " << RESET << "'" << static_cast<char>(num)
                  << "'" << std::endl;
      else
        std::cout << BLUE << "Char: " << RESET << "Non displayable"
                  << std::endl;
    }
  } else
    std::cout << BLUE << "Char: " << RESET << "Impossible" << std::endl;
}

void Converter::printInt(const std::string &str, int &type) {
  double num = 0;

  if (type == CHAR)
    num = str[0];
  else if (type == INT)
    num = std::strtol(str.c_str(), NULL, 10);
  else
    num = std::strtod(str.c_str(), NULL);

  if (num > MAX_INT || num < MIN_INT)
    std::cout << YELLOW << "Int: " << RESET << "Impossible" << std::endl;
  else
    std::cout << YELLOW << "Int: " << RESET << static_cast<int>(num)
              << std::endl;
}

void Converter::printDecimal(const std::string &str, int &type) {
  double num = 0;

  if (type == CHAR)
    num = str[0];
  else if (type == INT || type == FLOAT || type == DOUBLE)
    num = strtod(str.c_str(), NULL);

  if (num > MAX_FLOAT || num < MIN_FLOAT)
    std::cout << MAGENTA << "Float: " << RESET << "Impossible" << std::endl;
  else
    std::cout << MAGENTA << "Float: " << RESET << static_cast<float>(num) << "f"
              << std::endl;

  if (num > MAX_DBL || num < MIN_DBL)
    std::cout << CYAN << "Double: " << RESET << "Impossible" << std::endl;
  else
    std::cout << CYAN << "Double: " << RESET << static_cast<double>(num)
              << std::endl;
}

//---------------------
// Converting Function
//---------------------
void Converter::convert(const std::string &str) {
  if (isInfinity(str))
    return;
  try {
    int type = _getType(str);

    printChar(str, type);
    printInt(str, type);
    printDecimal(str, type);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
