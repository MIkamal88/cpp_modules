/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:26:45 by m_kamal           #+#    #+#             */
/*   Updated: 2024/01/19 10:26:45 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap(void) : ClapTrap() {
  _hit_points = 100;
  _energy_points = 100;
  _attack_damage = 30;
  std::cout << YELLOW << "FragTrap Default constructed" << RESET << std::endl;
}

FragTrap::FragTrap(std::string &name) : ClapTrap(name) {
  _hit_points = 100;
  _energy_points = 100;
  _attack_damage = 30;
  std::cout << YELLOW << "FragTrap " << this->_name << " constructed" << RESET
            << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src) {
  *this = src;
  std::cout << YELLOW << "FragTrap " << this->_name << " copy constructed"
            << RESET << std::endl;
}

// Destructor
FragTrap::~FragTrap(void) {
  std::cout << YELLOW << "FragTrap " << this->_name << " destroyed" << RESET
            << std::endl;
}

// Copy assignment operator
FragTrap &FragTrap::operator=(FragTrap const &other) {
  if (this != &other) {
    this->_name = other._name;
    this->_hit_points = other._hit_points;
    this->_energy_points = other._energy_points;
    this->_attack_damage = other._attack_damage;
  }
  return (*this);
}

// Member Functions
void FragTrap::highFivesGuys(void) {
  std::cout << YELLOW << "FragTrap " << this->_name << " says: \"High five!\""
            << RESET << std::endl;
}
