/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:39:16 by m_kamal           #+#    #+#             */
/*   Updated: 2024/01/12 23:39:16 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors
Fixed::Fixed(void) : _rawBits(0) {
  // std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const int int_value) {
  // std::cout << "Int constructor called" << std::endl;
  this->_rawBits = int_value << Fixed::_fractional_bits;
}

Fixed::Fixed(const float float_value) {
  // std::cout << "Float constructor called" << std::endl;
  this->_rawBits = roundf(float_value * (1 << Fixed::_fractional_bits));
}

Fixed::Fixed(const Fixed &fixed) {
  // std::cout << "Copy constructor called" << std::endl;
  *this = fixed;
}

// Destructor
Fixed::~Fixed(void) {
  // std::cout << "Destructor called" << std::endl;
}

// Assignment operator overload
Fixed &Fixed::operator=(const Fixed &fixed) {
  // std::cout << "Copy assignment operator called" << std::endl;
  this->_rawBits = fixed.getRawBits();
  return (*this);
}

// Comparison operators overload
bool Fixed::operator>(const Fixed &fixed) const {
  return (this->_rawBits > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed &fixed) const {
  return (this->_rawBits < fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed) const {
  return (this->_rawBits >= fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed) const {
  return (this->_rawBits <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed) const {
  return (this->_rawBits == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixed) const {
  return (this->_rawBits != fixed.getRawBits());
}

// Arithmetic operators overload
// Instantiated new object to store result as directly doing Fixed(addition)
// disregards the fractional bits in the addition.
Fixed Fixed::operator+(const Fixed &fixed) const {
	Fixed result;

	result._rawBits = _rawBits + fixed._rawBits;
	return result;
}

Fixed Fixed::operator-(const Fixed &fixed) const {
	Fixed result;

	result._rawBits = _rawBits - fixed._rawBits;
	return result;
}

Fixed Fixed::operator*(const Fixed &fixed) const {
  Fixed result;

  result._rawBits = (_rawBits * fixed._rawBits) / (1 << _fractional_bits);
  return result;
}

Fixed Fixed::operator/(const Fixed &fixed) const {
  if (fixed.getRawBits() == 0) {
    std::cout << "Division by zero" << std::endl;
    return (0);
  }
	Fixed result;

	result._rawBits = (_rawBits * (1 << _fractional_bits)) / fixed._rawBits;
	return result;
}

// Increment and decrement operators overload
Fixed &Fixed::operator++(void) {
  this->_rawBits++;
  return (*this);
}

Fixed Fixed::operator++(int) {
  Fixed tmp(*this);
  operator++();
  return (tmp);
}

Fixed &Fixed::operator--(void) {
  this->_rawBits--;
  return (*this);
}

Fixed Fixed::operator--(int) {
  Fixed tmp(*this);
  operator--();
  return (tmp);
}

// Min and max functions
Fixed &Fixed::min(Fixed &a, Fixed &b) { return (a < b ? a : b); }

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) { return (a > b ? a : b); }

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  return (a > b ? a : b);
}

// Member functions
int Fixed::getRawBits(void) const {
  // std::cout << "getRawBits member function called" << std::endl;
  return (this->_rawBits);
}

void Fixed::setRawBits(int const raw) {
  // std::cout << "setRawBits member function called" << std::endl;
  this->_rawBits = raw;
}

float Fixed::toFloat(void) const {
  return ((float)this->_rawBits / (float)(1 << Fixed::_fractional_bits));
}

int Fixed::toInt(void) const {
  return (this->_rawBits >> Fixed::_fractional_bits);
}

// Non-member functions
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return (out);
}
