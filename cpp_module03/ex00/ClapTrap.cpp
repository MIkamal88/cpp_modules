/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:01:19 by m_kamal           #+#    #+#             */
/*   Updated: 2024/01/17 14:01:19 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap(void)
    : _name("Default"), _hit_points(10), _energy_points(10), _attack_damage(0) {
  std::cout << GREEN << "ClapTrap Default constructor called" << RESET
            << std::endl;
}

ClapTrap::ClapTrap(std::string &name)
    : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
  std::cout << GREEN << "ClapTrap " << _name << " constructor called" << RESET
            << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &source) {
  *this = source;
  std::cout << GREEN << "ClapTrap " << _name << " constructor called" << RESET
            << std::endl;
}

// Destructor
ClapTrap::~ClapTrap(void) {
  std::cout << GREEN << "ClapTrap " << _name << " destructor called" << RESET
            << std::endl;
}

// Getters
std::string ClapTrap::getName(void) { return (this->_name); }

int ClapTrap::getHitPoints(void) { return (this->_hit_points); }

int ClapTrap::getEnergyPoints(void) { return (this->_energy_points); }

int ClapTrap::getAttackDamage(void) { return (this->_attack_damage); }

// Setters
void ClapTrap::setName(std::string name) { this->_name = name; }

void ClapTrap::setHitPoints(int hit_points) { this->_hit_points = hit_points; }

void ClapTrap::setEnergyPoints(int energy_points) {
  this->_energy_points = energy_points;
}

void ClapTrap::setAttackDamage(int attack_damage) {
  this->_attack_damage = attack_damage;
}

// Member Functions
void ClapTrap::attack(const std::string &target) {
  if (!_hit_points) {
    std::cout << YELLOW << "ClapTrap " << _name << " is dead and can't attack!"
              << RESET << std::endl;
    return;
  }
  if (!_energy_points) {
    std::cout << YELLOW << "ClapTrap " << _name
              << " has no energy and can't attack!" << RESET << std::endl;
    return;
  }
  std::cout << YELLOW << "ClapTrap " << _name << " attacks " << target
            << ", causing " << _attack_damage << " points of damage!" << RESET
            << std::endl;
  _energy_points--;
  return;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (!_hit_points) {
    std::cout << YELLOW << "ClapTrap " << _name << " is already dead!" << RESET
              << std::endl;
    return;
  }
  if (amount > (unsigned int)_hit_points) {
    std::cout << YELLOW << "ClapTrap " << _name << " takes " << _hit_points
              << " points of damage!" << RESET << std::endl;
    _hit_points = 0;
    return;
  }
  std::cout << YELLOW << "ClapTrap " << _name << " takes " << amount
            << " points of damage!" << RESET << std::endl;
  _hit_points -= amount;
  return;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (!_hit_points) {
    std::cout << "ClapTrap " << _name << " is dead and cannot be repaired!"
              << std::endl;
    return;
  }
  if (!_energy_points) {
    std::cout << "ClapTrap " << _name
              << " doesn't have enough energy to be repaired!" << std::endl;
    return;
  }
  _hit_points += amount;
  std::cout << "ClapTrap " << _name << " is repaired by " << amount
            << " points!" << std::endl;
  _energy_points -= 1;
  return;
}
