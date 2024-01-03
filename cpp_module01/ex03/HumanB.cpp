/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:45:48 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/19 12:45:48 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string name) : _name(name), _weapon(NULL) { return; }

HumanB::~HumanB() { return; }

void HumanB::setWeapon(Weapon &weapon) { _weapon = &weapon; }

void HumanB::attack(void) {
  if (this->_weapon && this->_weapon->getType() != "")
    std::cout << this->_name << " attacks with their "
              << this->_weapon->getType() << std::endl;
  else
    std::cout << _name << " has no weapon." << std::endl;
}
