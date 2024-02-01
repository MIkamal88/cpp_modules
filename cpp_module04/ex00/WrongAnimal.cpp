/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 08:46:49 by m_kamal           #+#    #+#             */
/*   Updated: 2024/02/01 08:46:49 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Constructors
WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal Default constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "WrongAnimal Default constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(WrongAnimal const &other)
{
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
	*this = other;
}

// Destructor
WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

// Copy Assignment Operator
WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

// Member Functions
std::string WrongAnimal::getType(void) const
{
	return (this->_type);
}
void WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal ";
	if (_type != "")
		std::cout << _type << " ";
	std::cout << "makes a sound" << std::endl;
}
