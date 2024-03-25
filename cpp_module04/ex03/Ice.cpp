/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:00:15 by m_kamal           #+#    #+#             */
/*   Updated: 2024/03/24 16:00:15 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// Constructors
Ice::Ice(void) : AMateria("ice") {
  std::cout << "Ice constructed!" << std::endl;
}

Ice::Ice(const Ice &source) : AMateria(source) {
  std::cout << "Ice copy constructed." << std::endl;
}

// Deconstructor
Ice::~Ice(void) { std::cout << "Ice deconstructed." << std::endl; }

// Operator Overload
Ice &Ice::operator=(const Ice &other) {
  if (this != &other)
    this->_type = other._type;
  return (*this);
}

// Member Functions
AMateria *Ice::clone(void) const { return (new Ice(*this)); }

void Ice::use(ICharacter &target) {
  std::cout << GREEN << "*shoots an ice bolt at " << target.getName() << " *"
            << RESET << std::endl;
}
