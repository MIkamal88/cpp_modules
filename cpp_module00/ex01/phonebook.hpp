/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:39:16 by m_kamal           #+#    #+#             */
/*   Updated: 2023/11/22 17:39:16 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP

#define PHONEBOOK_HPP

#include <iomanip>
#include <iostream>
#include <string>

class Contact {
private:
  int index;
  std::string first_name;
  std::string last_name;
  std::string phone_number;
  std::string nickname;
  std::string darkest_secret;
  std::string print_len(std::string str);
  std::string get_input(std::string str);

public:
  Contact();
  ~Contact();
  void init(void);
  void view(int index);
	void expand(int index);
  void set_index(int i);
};

class Phonebook {
private:
  Contact contact[8];
  int read_input(void);

public:
	Phonebook();
	~Phonebook();
  void add_contact(void);
  void print_contacts(void);
  void search_contact(void);
};

#endif
