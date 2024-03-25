/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:40:46 by m_kamal           #+#    #+#             */
/*   Updated: 2024/03/24 16:40:46 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// Constructors
Cure::Cure(void) : AMateria("cure") {
  std::cout << "Cure constructed!" << std::endl;
}

Cure::Cure(const Cure &source) : AMateria(source) {
  std::cout << "Cure copy constructed." << std::endl;
}

// Deconstructor
Cure::~Cure(void) { std::cout << "Cure deconstructed." << std::endl; }

// Operator Overload
Cure &Cure::operator=(const Cure &other) {
  if (this != &other)
    this->_type = other._type;
  return (*this);
}

// Member Functions
AMateria *Cure::clone(void) const { return (new Cure(*this)); }

void Cure::use(ICharacter &target) {
  std::cout << GREEN << "* heals " << target.getName() << "'s wounds *"
            << RESET << std::endl;
}
