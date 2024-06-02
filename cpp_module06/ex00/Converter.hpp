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

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <limits>

// Color Macros
# define RESET		"\e[m"
# define RED		"\e[31m"
# define GREEN		"\e[32m"
# define YELLOW		"\e[33m"
# define BLUE		"\e[34m"
# define MAGENTA	"\e[35m"
# define CYAN		"\e[36m"

enum e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
};

class Converter {
public:
  // Constructors and destructor
  Converter();
  Converter(Converter const &src);
  ~Converter();
  // Operator overloads
  Converter &operator=(Converter const &src);
  // Member functions
  static bool _isChar(const std::string &str);
  static bool _isInt(const std::string &str);
  static bool _isFloat(const std::string &str);
  static bool _isDouble(const std::string &str);
  static int _getType(const std::string &str);

  static void _toChar(const std::string &str);
  static void _toInt(const std::string &str);
  static void _toFloat(const std::string &str);
  static void _toDouble(const std::string &str);

  static void convert(const std::string &str);

  // Exceptions
  class InvalidConversionException : public std::exception {
    virtual const char *what() const throw() { return RED "Unknown type" RESET; }
  };
	class NonDisplayableException : public std::exception {
		virtual const char *what() const throw() { return RED "Non displayable" RESET; }
	};
};
