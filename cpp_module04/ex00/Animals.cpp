/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animals.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 08:41:30 by m_kamal           #+#    #+#             */
/*   Updated: 2024/01/25 08:41:30 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animals.hpp"

// Constructors
Animal::Animal(void) : _type("") {
	std::cout << "Animal default constructor called" << std::endl;
}
Animal::Animal(std::string type) : _type(type) {
	std::cout << "Animal" << _type << " constructor called" << std::endl;
}
Animal::Animal(Animal const &src) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

// Destructor
Animal::~Animal(void) {
	std::cout << "Animal destructor called" << std::endl;
}

// Copy Assignment Operator
Animal &Animal::operator=(Animal const &other) {
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

// Member functions
std::string Animal::getType(void) const {
	return (this->_type);
}
void Animal::makeSound(void) const {
	std::cout << "Animal ";
	if (_type != "")
		std::cout << _type << " ";
	std::cout << "makes a sound" << std::endl;
}
