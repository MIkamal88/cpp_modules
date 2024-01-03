/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:24:26 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/18 12:24:26 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(void) {
  Phonebook book;
  std::string input = "";

  while (input.compare("EXIT")) {
    std::cout << "Enter command: " << std::flush;
    std::cin >> input;
    if (input.compare("ADD") == 0)
      book.add_contact();
    else if (input.compare("SEARCH") == 0) {
      book.print_contacts();
      book.search_contact();
    }
  }
}
