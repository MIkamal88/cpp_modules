/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:41:05 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/18 18:41:05 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP

#define ZOMBIE_HPP

#include <iomanip>
#include <iostream>
#include <string>

class Zombie {
private:
  std::string name;

public:
  Zombie(std::string name);
  ~Zombie();
  void announce(void);
  Zombie *newZombie(std::string name);
  void randomChump(std::string name);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif
