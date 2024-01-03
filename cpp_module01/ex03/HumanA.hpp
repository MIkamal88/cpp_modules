/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:45:30 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/19 12:45:30 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP

#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
private:
  std::string _name;
  Weapon &_weapon;

public:
  HumanA(const std::string name, Weapon &weapon);
  ~HumanA();
  void attack();
};

#endif
