/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:45:23 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/19 12:45:23 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) { this->setType(type); }

Weapon::~Weapon() {}

const std::string &Weapon::getType(void) { return this->_type; }

void Weapon::setType(std::string type) { this->_type = type; }
