/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 08:48:41 by m_kamal           #+#    #+#             */
/*   Updated: 2024/01/19 08:48:41 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap(void) : ClapTrap() {
  _hit_points = 100;
  _energy_points = 50;
  _attack_damage = 20;
  std::cout << YELLOW << "ScavTrap Default constructor called" << RESET
            << std::endl;
}

ScavTrap::ScavTrap(std::string &name) : ClapTrap(name) {
  _hit_points = 100;
  _energy_points = 50;
  _attack_damage = 20;
  std::cout << YELLOW << "ScavTrap " << this->_name << " constructor called"
            << RESET << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src) {
  *this = src;
  std::cout << YELLOW << "ScavTrap " << this->_name
            << " copy constructor called" << RESET << std::endl;
}

ScavTrap::~ScavTrap(void) {
  std::cout << YELLOW << "ScavTrap " << this->_name << " destructor called"
            << RESET << std::endl;
}

// Copy assignment operator
ScavTrap &ScavTrap::operator=(ScavTrap const &other) {
  if (this != &other) {
    this->_name = other._name;
    this->_hit_points = other._hit_points;
    this->_energy_points = other._energy_points;
    this->_attack_damage = other._attack_damage;
  }
  return (*this);
}

// Member Functions
void ScavTrap::attack(std::string const &target) {
  std::cout << YELLOW << "ScavTrap " << this->_name << " attacks " << target
            << ", causing " << this->_attack_damage << " points of damage!"
            << RESET << std::endl;
}

void ScavTrap::guardGate(void) {
  std::cout << YELLOW << "ScavTrap " << this->_name
            << " has entered in Gate keeper mode" << RESET << std::endl;
}
