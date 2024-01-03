/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:14:58 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/19 09:14:58 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	int n = 5;

  Zombie *horde = zombieHorde(n, "HORDE ZOMBIE");

  for (int i = 0; i < n; i++)
    horde[i].announce();
  std::cout << std::endl;
  delete[] horde;
  return (0);
}
