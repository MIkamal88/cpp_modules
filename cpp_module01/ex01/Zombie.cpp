/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:15:09 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/19 09:15:09 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
  std::cout << GREEN << "Normie Zombie created..." << RESET << std::endl;
}

void Zombie::set_name(std::string name) {
  if (name.empty())
    name = "Normie";
  else
    this->name = name;
}

Zombie::~Zombie() {
  std::cout << RED << this->name << " is dead..." << RESET
            << std::endl;
}

void Zombie::announce(void) {
  std::cout << YELLOW << this->name << ": BraiiiiiiinnnzzzZ" << RESET
            << std::endl;
}

std::string Zombie::get_name(void) { return (this->name); }
