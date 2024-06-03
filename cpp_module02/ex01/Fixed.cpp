/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:17:23 by m_kamal           #+#    #+#             */
/*   Updated: 2024/01/12 23:17:23 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors
Fixed::Fixed(void) : _rawBits(0) {
  std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const int int_value) {
  std::cout << GREEN << "Int constructor called" << RESET << std::endl;
  // Shifting the int_value by 8bits to the left to convert it to fixed point
  // format
  this->_rawBits = int_value << _fractional_bits;
}

Fixed::Fixed(const float float_value) {
  std::cout << GREEN << "Float constructor called" << RESET << std::endl;
  // Shifting the float_value by 8bits to the left to convert it to fixed point
  // format
  this->_rawBits = roundf(float_value * (1 << _fractional_bits));
}

Fixed::Fixed(const Fixed &fixed) {
  std::cout << GREEN << "Copy constructor called" << RESET << std::endl;
  *this = fixed;
}

// Destructor
Fixed::~Fixed(void) {
  std::cout << RED << "Destructor called" << RESET << std::endl;
}

// Assignment operator overload
Fixed &Fixed::operator=(const Fixed &fixed) {
  std::cout << GREEN << "Copy assignment operator called" << RESET << std::endl;
  this->_rawBits = fixed.getRawBits();
  return (*this);
}

// Member functions
int Fixed::getRawBits(void) const {
  std::cout << YELLOW << "getRawBits member function called" << RESET
            << std::endl;
  return (this->_rawBits);
}

void Fixed::setRawBits(int const raw) {
  std::cout << YELLOW << "setRawBits member function called" << RESET
            << std::endl;
  this->_rawBits = raw;
}

float Fixed::toFloat(void) const {
  return (this->_rawBits / (float)(1 << _fractional_bits));
}

int Fixed::toInt(void) const { return (this->_rawBits >> _fractional_bits); }

// Non-member functions
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return (out);
}
