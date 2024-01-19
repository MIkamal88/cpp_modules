/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 08:32:02 by m_kamal           #+#    #+#             */
/*   Updated: 2024/01/19 08:32:02 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
  // Constructors
  ScavTrap(void);
  ScavTrap(std::string &name);
  ScavTrap(ScavTrap const &src);
  // Destructor
  ~ScavTrap(void);
  // Copy assignment operator
  ScavTrap &operator=(ScavTrap const &other);
  // Member Functions
  void attack(std::string const &target);
  void guardGate(void);
};

#endif
