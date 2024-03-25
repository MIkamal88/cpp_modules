/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:36:54 by m_kamal           #+#    #+#             */
/*   Updated: 2024/03/21 16:36:54 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animals.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
	std::cout << YELLOW << "** Creating a Dog **" << RESET << std::endl;
	const Dog *j = new Dog();

	std::cout << YELLOW << "** Creating a Cat**" << RESET << std::endl;
	const Cat *k = new Cat();

	std::cout << YELLOW << "** Shut them up, they're annoying **" << RESET << std::endl;
	j->makeSound();
	k->makeSound();

	std::cout << YELLOW << "** Making Wannabes **" << RESET << std::endl;
  Dog *copy_dog = new Dog(*((Dog *)j));
  Cat *copy_cat = new Cat(*((Cat *)j));

	std::cout << RED << "** Destroying Animal Copies **" << RESET << std::endl;
  delete copy_dog;
  delete copy_cat;

	std::cout << YELLOW << "** Making Shallow Copies **" << RESET << std::endl;
	copy_dog = (Dog *)j;
	copy_cat = (Cat *)k;
	copy_dog->makeSound();
	copy_cat->makeSound();

	std::cout << RED << "** Destroying Animals **" << RESET << std::endl;
	delete j;
	delete k;
}
/* #include "typeinfo" */
/* 	std::cout << "Memory address of Dog: " << static_cast<void*>(j) << std::endl; */
