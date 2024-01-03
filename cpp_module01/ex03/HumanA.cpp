/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:45:36 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/19 12:45:36 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
    : _name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack(void) {
  if (this->_weapon.getType() != "")
    std::cout << _name << " attacks with their " << this->_weapon.getType()
              << std::endl;
  else
    std::cout << _name << " has no weapon." << std::endl;
}
