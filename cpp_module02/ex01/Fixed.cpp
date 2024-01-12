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
Fixed::Fixed(void) : _fixed_point_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int int_value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_point_value = int_value << Fixed::_fractional_bits;
}

Fixed::Fixed(const float float_value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_point_value = roundf(float_value * (1 << Fixed::_fractional_bits));
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

// Destructor
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

// Assignment operator overload
Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed_point_value = fixed.getRawBits();
	return (*this);
}

// Member functions
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed_point_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixed_point_value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_fixed_point_value / (float)(1 << Fixed::_fractional_bits));
}

int Fixed::toInt(void) const
{
	return (this->_fixed_point_value >> Fixed::_fractional_bits);
}

// Non-member functions
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
