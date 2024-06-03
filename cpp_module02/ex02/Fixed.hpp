/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:39:20 by m_kamal           #+#    #+#             */
/*   Updated: 2024/01/12 23:39:20 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

const std::string RESET = "\033[0m";
const std::string RED = "\033[1;31m";
const std::string GREEN = "\033[1;32m";
const std::string YELLOW = "\033[1;33m";
const std::string BLUE = "\033[1;34m";
const std::string WHITE = "\033[1;37m";
const std::string ORANGE = "\033[1;38;5;202m";

class Fixed {
private:
  int _rawBits;
  static const int _fractional_bits = 8;

public:
  // Constructors
  Fixed(void);
  Fixed(const int int_value);
  Fixed(const float float_value);
  Fixed(const Fixed &fixed);
  // Destructor
  ~Fixed(void);
  // Assignment operator overload
  Fixed &operator=(const Fixed &fixed);

  // Comparison operators overload
  bool operator>(const Fixed &fixed) const;
  bool operator<(const Fixed &fixed) const;
  bool operator>=(const Fixed &fixed) const;
  bool operator<=(const Fixed &fixed) const;
  bool operator==(const Fixed &fixed) const;
  bool operator!=(const Fixed &fixed) const;

  // Arithmetic operators overload
  Fixed operator+(const Fixed &fixed) const;
  Fixed operator-(const Fixed &fixed) const;
  Fixed operator*(const Fixed &fixed) const;
  Fixed operator/(const Fixed &fixed) const;

  // Increment and decrement operators overload
  Fixed &operator++(void);
  Fixed operator++(int);
  Fixed &operator--(void);
  Fixed operator--(int);

  // Min and max functions
  static Fixed &min(Fixed &a, Fixed &b);
  static const Fixed &min(const Fixed &a, const Fixed &b);
  static Fixed &max(Fixed &a, Fixed &b);
  static const Fixed &max(const Fixed &a, const Fixed &b);

  // Member functions
  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;
};

// Non-member functions
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
