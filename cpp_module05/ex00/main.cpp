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
    // b1.decrementGrade();
  } catch (Bureaucrat::GradeTooHighException &e) {
    std::cout << e.what() << std::endl;
  } catch (Bureaucrat::GradeTooLowException &e) {
    std::cout << e.what() << std::endl;
  }
}
