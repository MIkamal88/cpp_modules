/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:28:57 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/20 09:28:57 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iterator>

int main(void) {
  std::string input;
  Harl harl;

  do {
    std::cout << "Enter a level [DEBUG, INFO, WARNING, ERROR] or EXIT : ";
		std::cout << std::endl;
		if (!(std::cin >> input))
			break;
    harl.complain(input);
  } while (input.compare("EXIT"));
}
