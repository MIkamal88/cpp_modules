/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:40:38 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/18 18:40:38 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void){
	std::cout << "Creating Zombie on the stack..." << std::endl;
	std::cout << "Calling randomChump..." << std::endl;

	randomChump("Randy the Stack Zombie");

	std::cout << std::endl;

	std::cout << "Creating Zombie on the heap..." << std::endl;
	Zombie *Felix = newZombie("Felix the Heap Zombie");

	std::cout << "Calling announce on Felix..." << std::endl;
	Felix->announce();

	std::cout << "Killing Felix the Heap Zombie..." << std::endl;
	delete Felix;
}
