/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:01:06 by m_kamal           #+#    #+#             */
/*   Updated: 2024/01/17 14:01:06 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
  std::string hero_name = "HERO";
  std::string villain_name = "VILLIAN";

  std::cout << RED << "Calling Constructors for " << hero_name << " and "
            << villain_name << RESET << std::endl;
  ClapTrap hero(hero_name);
  ClapTrap villain(villain_name);

  std::cout << RED << "Member Function Calls" << RESET << std::endl;
  std::cout << RED << "42 Arena is happy to announce our 2 contestants: "
            << hero.getName() << " and " << villain.getName() << RESET
            << std::endl;

  std::cout << RED << villain.getName()
            << " starts the battle with a nasty attack on " << hero.getName()
            << RESET << std::endl;
  villain.attack(hero.getName());
  hero.takeDamage(villain.getAttackDamage());

  std::cout << RED << hero.getName() << " is not happy and attacks back "
            << villain.getName() << RESET << std::endl;
  hero.attack(villain.getName());
  villain.takeDamage(hero.getAttackDamage());

  std::cout << RED << "Looks like " << hero.getName()
            << " is not done and trying to repair himself" << RESET
            << std::endl;
  hero.beRepaired(5);

  std::cout << RED << villain.getName()
            << " takes this opportunity to land a series of attacks on "
            << hero.getName() << RESET << std::endl;
  for (int i = 0; i < 5; i++) {
    villain.attack(hero.getName());
    hero.takeDamage(villain.getAttackDamage());
  }

  std::cout << RED << villain.getName()
            << " looks exhausted and has no energy to attack" << RESET
            << std::endl;
  std::cout << RED << hero.getName()
            << " finds an opening and lands a killing blow on "
            << villain.getName() << RESET << std::endl;
  hero.attack(villain.getName());
  std::cout << RED << hero.getName() << " is the winner of this battle" << RESET
            << std::endl;

  std::cout << RED << "Calling Destructors for " << hero.getName() << " and "
            << villain.getName() << RESET << std::endl;
  return (0);
}
