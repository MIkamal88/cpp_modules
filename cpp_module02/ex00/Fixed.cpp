/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 08:26:06 by m_kamal           #+#    #+#             */
/*   Updated: 2024/01/12 08:26:06 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &fixed) {
  std::cout << "Copy constructor called" << std::endl;
  *this = fixed;
}

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }

Fixed &Fixed::operator=(Fixed const &fixed) {
  std::cout << "Copy assignment operator called" << std::endl;
  this->_rawBits = fixed.getRawBits();
  return (*this);
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return (this->_rawBits);
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  this->_rawBits = raw;
}
