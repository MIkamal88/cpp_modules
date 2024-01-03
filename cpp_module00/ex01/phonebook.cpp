/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:52:45 by m_kamal           #+#    #+#             */
/*   Updated: 2023/11/22 16:52:45 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook() {}
Phonebook::~Phonebook() {}

void Phonebook::add_contact(void) {
  static int i;

  this->contact[i % 8].init();
  this->contact[i % 8].set_index(i % 8);
  i++;
}

int Phonebook::read_input(void) {
  int input = -1;
  bool check = false;

  while (!check) {
    std::cout << "Enter index: " << std::endl;
    std::cin >> input;
    if (std::cin.good() && input >= 0 && input <= 8)
      check = true;
    else {
      std::cin.clear();
      while (std::cin.get() != '\n')
        continue;
      std::cout << "Invalid index, Please Enter a valid index." << std::endl;
    }
  }
  return (input);
}

void Phonebook::print_contacts(void) {
  for (int i = 0; i < 8; i++) {
    this->contact[i].view(i);
  }
  std::cout << std::endl;
}

void Phonebook::search_contact(void) {
  int i = this->read_input();
  this->contact[i].expand(i);
}
