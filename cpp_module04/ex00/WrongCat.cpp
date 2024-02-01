/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:07:34 by m_kamal           #+#    #+#             */
/*   Updated: 2024/02/01 09:07:34 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Constructors
WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat Default constructor called" << std::endl;
}
WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	std::cout << "WrongCat Default constructor called" << std::endl;
}
WrongCat::WrongCat(WrongCat const &other) : WrongAnimal(other)
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
	*this = other;
}

// Destructor
WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

// Copy Assignment Operator
WrongCat &WrongCat::operator=(WrongCat const &other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

