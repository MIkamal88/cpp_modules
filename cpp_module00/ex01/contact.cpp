/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:09:29 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/18 09:09:29 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Contact::Contact() {}

Contact::~Contact() {}

std::string Contact::get_input(std::string str) {
  std::string input = "";
  bool check = false;

  while (!check) {
    std::cout << str << std::endl;
    std::getline(std::cin, input);
    if (std::cin.good() && !input.empty())
      check = true;
    else {
      std::cin.clear();
      while (std::cin.get() != '\n')
        continue;
      std::cout << "Please enter a valid input." << std::endl;
    }
  }
  return (input);
}

void Contact::init(void) {
  std::cin.ignore();
  this->first_name = get_input("First name: ");
  this->last_name = get_input("Last name: ");
  this->phone_number = get_input("Phone number: ");
  this->nickname = get_input("Nickname: ");
  this->darkest_secret = get_input("Darkest secret: ");
  std::cout << std::endl;
}

std::string Contact::print_len(std::string str) {
  if (str.length() >= 10)
    return (str.substr(0, 9) + ".");
  return (str);
}

void Contact::set_index(int i) { this->index = i; }

void Contact::view(int index) {
  if (this->first_name.empty() || this->last_name.empty() ||
      this->nickname.empty())
    return;
  std::cout << "|" << std::setw(10) << index << std::flush;
  std::cout << "|" << std::setw(10) << this->first_name << std::flush;
  std::cout << "|" << std::setw(10) << this->last_name << std::flush;
  std::cout << "|" << std::setw(10) << this->nickname << std::flush;
  std::cout << "|" << std::endl;
}

void Contact::expand(int index) {
  if (this->first_name.empty() || this->last_name.empty() ||
      this->nickname.empty())
    return;
	std::cout << "Contact #" << index << std::endl;
  std::cout << "First name: " << this->first_name << std::endl;
  std::cout << "Last name: " << this->last_name << std::endl;
  std::cout << "Nickname: " << this->nickname << std::endl;
}
