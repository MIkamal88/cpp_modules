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

Converter::Converter(Converter const &src) { *this = src; }

Converter::~Converter() {}

// Operator overloads
Converter &Converter::operator=(Converter const &src) {
  if (this == &src)
    return (*this);
  *this = src;
  return (*this);
}

// Member functions
// Converting Functions
void Converter::convert(const std::string &str) {
  try {
    int type = _getType(str);
    switch (type) {
    case CHAR:
      _toChar(str);
      break;
    case INT:
      _toInt(str);
      break;
    case FLOAT:
      _toFloat(str);
      break;
    case DOUBLE:
      _toDouble(str);
      break;
    default:
      throw InvalidConversionException();
      break;
    }
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

// Checking Functions
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

bool Converter::_isChar(const std::string &str) {
  try {
    if (str.length() == 1 && std::isalpha(str[0]) && std::isprint(str[0]) &&
        !std::isdigit(str[0]))
      return true;
    else {
			std::cout << BLUE << "Char: " << RESET;
      throw NonDisplayableException();
		}
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
	return false;
}

bool Converter::_isInt(const std::string &str) {
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
  if (nb > std::numeric_limits<int>::max() ||
      nb < std::numeric_limits<int>::min())
    return false;
  return true;
}

// numeric_limits(lowest) is c++11
bool Converter::_isFloat(const std::string &str) {
  size_t i = 0;
  size_t len = str.length();
  double nb;
  bool dot = false;

  if (str.substr(i, len) == "nanf" || str.substr(i, len) == "+inff" ||
      str.substr(i, len) == "-inff" || str.substr(i, len) == "inff")
    return true;
  if (i == 0 && (str[i] == '+' || str[i] == '-'))
    i++;
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
  if (nb > std::numeric_limits<float>::max() ||
      nb < -std::numeric_limits<float>::max())
    return false;
  return true;
}

bool Converter::_isDouble(const std::string &str) {
  size_t i = 0;
  size_t len = str.length();
  double nb;
  bool dot = false;

  if (str.substr(i, len) == "nan" || str.substr(i, len) == "+inf" ||
      str.substr(i, len) == "-inf" || str.substr(i, len) == "inf")
    return true;
  if (i == 0 && (str[i] == '+' || str[i] == '-'))
    i++;
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
  if (nb > std::numeric_limits<double>::max() ||
      nb < -std::numeric_limits<double>::max())
    return false;
  return true;
}

// Conversion Functions
// nan and inf are not implemented
void Converter::_toChar(const std::string &str) {
  char c = str[0];

  std::cout << BLUE << "Char: " << RESET;
  if (std::isprint(c))
    std::cout << c << std::endl;
  else
    throw NonDisplayableException();
}

void Converter::_toInt(const std::string &str) {
  int i = std::atoi(str.c_str());

  std::cout << GREEN << "Int: " << RESET << i << std::endl;
}

void Converter::_toFloat(const std::string &str) {
  if (str.compare("nanf") == 0 || str.compare("+inff") == 0 ||
      str.compare("-inff") == 0 || str.compare("inff") == 0)
    std::cout << YELLOW << "Float: " << RESET << str << std::endl;
  else {
    float f = std::atof(str.c_str());
    std::cout << YELLOW << "Float: " << RESET << f << "f" << std::endl;
  }
}

void Converter::_toDouble(const std::string &str) {
  if (str.compare("nan") == 0 || str.compare("+inf") == 0 ||
      str.compare("-inf") == 0 || str.compare("inf") == 0)
    std::cout << MAGENTA << "Double: " << RESET << str << std::endl;
  else {
    double d = std::strtod(str.c_str(), NULL);
    std::cout << MAGENTA << "Double: " << RESET << d << std::endl;
  }
}
