/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:45:55 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/19 12:45:55 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP

#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
private:
  std::string _name;
  Weapon *_weapon;

public:
  HumanB(const std::string name);
  ~HumanB();
  void attack(void);
	void setWeapon(Weapon &weapon);
};

#endif
