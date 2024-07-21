/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:08:36 by m_kamal           #+#    #+#             */
/*   Updated: 2024/03/25 16:08:36 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
  try {
    Bureaucrat b1("Bureaucrat 1", 1);

    std::cout << b1 << std::endl;
    b1.incrementGrade();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    Bureaucrat b2("Bureaucrat 1", 150);

    std::cout << b2 << std::endl;
    b2.decrementGrade();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
