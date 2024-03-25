/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:36:54 by m_kamal           #+#    #+#             */
/*   Updated: 2024/03/24 13:36:54 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Constructors
AMateria::AMateria(void) {
	_type = "Default";
	std::cout << "Default AMateria Constructed." << std::endl;
}

AMateria::AMateria(std::string const &type) {
	_type = type;
	std::cout << "AMateria of type " << _type << " is constructed." << std::endl;
}

AMateria::AMateria(const AMateria &source) {
	*this = source;
	std::cout << "AMateria of type " << _type << " is copy constructed." << std::endl;
}

//Deconstructors
AMateria::~AMateria() {
	std::cout << "AMateria Deconstructed." << std::endl;
}

// Operator Overload
AMateria &AMateria::operator=(AMateria const &other) {
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

// Member Functions
std::string const &AMateria::getType(void) const {
	return (this->_type);
}

void AMateria::use(ICharacter& target) {
	std::cout << GREEN << "* " << _type << " uses its powers at " << target.getName() << " *" << RESET << std::endl;
}

