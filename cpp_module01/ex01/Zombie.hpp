/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:15:04 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/19 09:15:04 by m_kamal          ###   ########.fr       */
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
	Zombie(void);
  ~Zombie();
  void set_name(std::string name);
	std::string get_name(void);
  void announce(void);
};

Zombie *zombieHorde(int n, std::string name);

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";

#endif
