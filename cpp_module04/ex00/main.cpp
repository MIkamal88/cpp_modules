/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:37:49 by m_kamal           #+#    #+#             */
/*   Updated: 2024/01/19 10:37:49 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
  std::cout << YELLOW << "====================" << RESET << std::endl;
  std::cout << YELLOW << "Calling Animal Class" << RESET << std::endl;
  std::cout << YELLOW << "====================" << RESET << std::endl;
  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();
  std::cout << std::endl
            << YELLOW << "Calling Their Type and Sounds" << RESET << std::endl;
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound(); // will output the cat sound!
  j->makeSound();
  meta->makeSound();
  std::cout << YELLOW << "=======================" << RESET << std::endl;
  std::cout << YELLOW << "Destroying Animal Class" << RESET << std::endl;
  std::cout << YELLOW << "=======================" << RESET << std::endl;
  delete (meta);
  delete (j);
  delete (i);

	std::cout << YELLOW << "Calling WrongAnimal Class" << RESET << std::endl;
	std::cout << YELLOW << "=========================" << RESET << std::endl;
	const WrongAnimal *meta2 = new WrongAnimal();
	const WrongAnimal *j2 = new WrongCat();

	std::cout << std::endl
						<< YELLOW << "Calling Sounds" << RESET << std::endl;
	j2->makeSound();
	meta2->makeSound();

  std::cout << YELLOW << "=======================" << RESET << std::endl;
  std::cout << YELLOW << "Destroying Animal Class" << RESET << std::endl;
  std::cout << YELLOW << "=======================" << RESET << std::endl;
	delete(meta2);
	delete(j2);
  return (0);
}
