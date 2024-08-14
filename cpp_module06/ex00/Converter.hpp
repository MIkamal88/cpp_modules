/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:08:44 by m_kamal           #+#    #+#             */
/*   Updated: 2024/05/21 20:08:44 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <cstdlib>
#include <iostream>
#include <limits>

// Max Numbers
#define MAX_INT std::numeric_limits<int>::max()
#define MIN_INT std::numeric_limits<int>::min()
#define MAX_FLOAT std::numeric_limits<float>::max()
#define MIN_FLOAT std::numeric_limits<float>::min()
#define MAX_DBL std::numeric_limits<double>::max()
#define MIN_DBL std::numeric_limits<double>::min()

// Color Macros
#define RESET "\e[m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define MAGENTA "\e[35m"
#define CYAN "\e[36m"

enum e_type {
  CHAR,
  INT,
  FLOAT,
  DOUBLE,
};

class Converter {
 private:
  // Private Constructors and destructor - Static Class (non-instantiable)
  Converter();
  Converter(Converter const &src);
  ~Converter();
  // Operator overloads
  Converter &operator=(Converter const &src);
  // Member functions
  static int _getType(const std::string &str);
  static void printInt(const std::string &str, int &type);
  static void printChar(const std::string &str, int &type);
  static void printDecimal(const std::string &str, int &type);

public:
  static void convert(const std::string &str);

  // Exceptions
  class InvalidConversionException : public std::exception {
    virtual const char *what() const throw() {
      return RED "Unknown type" RESET;
    }
  };
  class NonDisplayableException : public std::exception {
    virtual const char *what() const throw() {
      return RED "Non displayable" RESET;
    }
  };
};
