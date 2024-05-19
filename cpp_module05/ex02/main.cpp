/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:08:42 by m_kamal           #+#    #+#             */
/*   Updated: 2024/05/19 12:08:42 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  try {
    Bureaucrat b1("B1", 2);
    ShrubberyCreationForm f1("Shrubbery");
    RobotomyRequestForm f2("Robotomy");
    PresidentialPardonForm f3("Pardon");

    std::cout << "------------------ Form 1 (Shrubbery) ------------------"
              << std::endl;
    b1.signForm(f1);
    b1.executeForm(f1);
    std::cout << "------------------ Form 1 (Robotomy) ------------------"
              << std::endl;
    b1.signForm(f2);
    b1.executeForm(f2);
    b1.executeForm(f2);
    b1.executeForm(f2);
    b1.executeForm(f2);
    std::cout << "------------------ Form 1 (Pardon) ------------------"
              << std::endl;
    b1.signForm(f3);
    b1.executeForm(f3);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}
