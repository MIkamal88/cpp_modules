/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:55:34 by m_kamal           #+#    #+#             */
/*   Updated: 2024/03/24 16:55:34 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "ICharacter.hpp"

// Constructors
Character::Character(void) {
	_name = "Randy";
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "A default character named 'Randy' constructed!" << std::endl;
}

Character::Character(std::string const &name) {
	_name = name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "A character named " << _name << " constructed!" << std::endl;
}

// Deep Copy
Character::Character(const Character &source) {
	_name = source._name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = source._inventory[i]->clone();
	std::cout << "Character " << _name << " copy constructed!" << std::endl;
}

// Deconstructor
Character::~Character(void) {
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
	std::cout << "Character " << _name << " deconstructed!" << std::endl;
}

// Operator Overload
Character &Character::operator=(const Character &other) {
	if (this != &other) {
		_name = other._name;
		for (int i = 0; i < 4; i++)
			if (_inventory[i])
				delete _inventory[i];
		for (int i = 0; i < 4; i++)
			if (!_inventory[i])
				_inventory[i] = other._inventory[i]->clone();
	}
	return (*this);
}

// Member Functions
std::string const &Character::getName(void) const {
	return (_name);
}

void Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++)
		if (!_inventory[i]) {
			_inventory[i] = m;
			return ;
		}
	return ;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3 || !_inventory[idx])
		return ;
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx > 3 || !_inventory[idx])
		return ;
	_inventory[idx]->use(target);
}
