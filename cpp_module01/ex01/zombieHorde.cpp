/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:15:17 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/19 09:15:17 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int n, std::string name) {
  Zombie *horde = new Zombie[n];

  for (int i = 0; i < n; i++)
		horde[i].set_name(name);

	std::cout << std::endl;
  std::cout << name << " created..." << std::endl;
	std::cout << std::endl;
  return (horde);
}
