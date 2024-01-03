/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:45:17 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/19 12:45:17 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP

#define WEAPON_HPP

#include <iomanip>
#include <iostream>
#include <string>

class Weapon {
private:
  std::string _type;

public:
  Weapon(std::string type);
  ~Weapon();
  void setType(const std::string type);
  const std::string &getType(void);
};

#endif
