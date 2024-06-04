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

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
  std::string frag = "Fraggy";
  std::string frag_cpy = "Fraggy_cpy";

  std::cout << RED << "Calling Constructors for " << frag << " and " << frag_cpy
            << RESET << std::endl;
  FragTrap fraggy(frag);
  FragTrap fraggy_cpy(frag_cpy);

  std::cout << RED << "Inherited Member Function Calls" << RESET << std::endl;
  fraggy.takeDamage(10);
  fraggy.beRepaired(10);

  std::cout << RED << "Member Function Calls" << RESET << std::endl;
  fraggy.attack("random enemy");
  fraggy.highFivesGuys();

  std::cout << RED << "Calling Copy Assignment Operator" << RESET << std::endl;
  FragTrap scavy2 = fraggy;
  scavy2.attack("another enemy");

  std::cout << RED << "Calling Copy Constructor" << RESET << std::endl;
  FragTrap scavy3(scavy2);
  scavy3.attack("one more enemy");

  std::cout << RED << "Calling Destructor" << RESET << std::endl;
}
