/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:28:44 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/20 09:28:44 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {
  std::cout << GREEN << "Harl is ready!" << RESET << std::endl;
}

Harl::~Harl(void) {
  std::cout << GREEN << "Harl is destroyed!" << RESET << std::endl;
}

void Harl::_debug(void) {
  std::cout
      << BLUE
      << "I love having extra bacon for my "
         "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
      << RESET << std::endl;
}

void Harl::_info(void) {
  std::cout
      << BLUE
      << "I cannot believe adding extra bacon costs more money. You didn’t put "
         "enough bacon in my burger! If you did, I wouldn’t be asking for more!"
      << RESET << std::endl;
}

void Harl::_warning(void) {
  std::cout
      << YELLOW
      << "I think I deserve to have some extra bacon for free. I’ve been "
         "coming for years whereas you started working here since last month."
      << RESET << std::endl;
}

void Harl::_error(void) {
  std::cout << ORANGE
            << "This is unacceptable! I want to speak to the manager now."
            << RESET << std::endl;
}

void Harl::complain(const std::string &level) {
  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  void (Harl::*methods[4])(void) = {&Harl::_debug, &Harl::_info,
                                    &Harl::_warning, &Harl::_error};

  for (int i = 0; i < 4; i++) {
    if (levels[i] == level) {
      (this->*methods[i])();
      return;
    }
  }
}
