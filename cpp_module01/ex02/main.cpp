/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:28:14 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/19 12:28:14 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void) {
  std::string str = "HI THIS IS BRAIN";
  std::string *stringPTR = &str;
  std::string &stringREF = str;

	std::cout << "Memory address of string variable: " << &str << std::endl;
	std::cout << "Memory address held by stringPTR:  " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF:  " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "Value of string variable:      " << str << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
}
