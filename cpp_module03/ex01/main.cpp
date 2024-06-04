/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:13:11 by m_kamal           #+#    #+#             */
/*   Updated: 2024/01/19 09:13:11 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void) {
  std::string scav = "Scav";
  std::string scav_cpy = "Scav_cpy";

  std::cout << RED << "Calling Constructors for " << scav << " and " << scav_cpy
            << RESET << std::endl;
  ScavTrap scavy(scav);
  ScavTrap scavy_cpy(scav_cpy);
	std::cout << std::endl;

  std::cout << RED << "Inherited Member Function Calls" << RESET << std::endl;
  scavy.takeDamage(10);
  scavy.beRepaired(10);
	std::cout << std::endl;

  std::cout << RED << "Member Function Calls" << RESET << std::endl;
  scavy.attack("random enemy");
  scavy.guardGate();
	std::cout << std::endl;

  std::cout << RED << "Calling Copy Assignment Operator" << RESET << std::endl;
  ScavTrap scavy2 = scavy;
  scavy2.attack("another enemy");
	std::cout << std::endl;

  std::cout << RED << "Calling Copy Constructor" << RESET << std::endl;
  ScavTrap scavy3(scavy2);
  scavy3.attack("one more enemy");
	std::cout << std::endl;

  std::cout << RED << "Calling Destructor" << RESET << std::endl;
}
