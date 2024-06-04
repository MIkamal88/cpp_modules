/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:01:13 by m_kamal           #+#    #+#             */
/*   Updated: 2024/01/17 14:01:13 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
#include <string>

// Color codes
const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";

class ClapTrap {
private:
  std::string _name;
  int _hit_points;
  int _energy_points;
  int _attack_damage;

public:
  // Constructors
  ClapTrap(void);
  ClapTrap(std::string &name);
  ClapTrap(const ClapTrap &source);
  // Destructor
  ~ClapTrap(void);
  // Operator overload
  ClapTrap &operator=(const ClapTrap &other);
  // Getters
  std::string getName(void);
  int getHitPoints(void);
  int getEnergyPoints(void);
  int getAttackDamage(void);
  // Setters
  void setName(std::string name);
  void setHitPoints(int hit_points);
  void setEnergyPoints(int energy_points);
  void setAttackDamage(int attack_damage);
  // Member Functions
  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

#endif
