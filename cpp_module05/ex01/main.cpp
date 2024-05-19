/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:52:01 by m_kamal           #+#    #+#             */
/*   Updated: 2024/05/12 15:52:01 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	// Creating Bureaucrats
  std::cout << "Creating a Bureaucrat with a grade of 1" << std::endl;
  Bureaucrat b1("Bureaucrat 1", 1);
  std::cout << b1 << std::endl;

  std::cout << "Creating a Bureaucrat with a grade of 150" << std::endl;
  Bureaucrat b2("Bureaucrat 2", 150);
  std::cout << b2 << std::endl;

	// Creating Forms
	std::cout << "-------------------------------------------------------------" << std::endl;
  std::cout << "Creating a Form with a sign grade of 1 and an exec grade of 1"
            << std::endl;
  Form f1("Form 1", 1, 1);
  std::cout << f1 << std::endl;

	std::cout << "--------------"<< std::endl;
  std::cout
      << "Creating a Form with a sign grade of 150 and an exec grade of 150"
      << std::endl;
  Form f2("Form 2", 150, 150);
  std::cout << f2 << std::endl;

	std::cout << "--------------"<< std::endl;
  std::cout
      << "Trying to create a Form with a sign grade of 0 and an exec grade of 1"
      << std::endl;
  try {
    Form f3("Form 3", 0, 1);
    std::cout << f3 << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

	std::cout << "--------------"<< std::endl;
  std::cout
      << "Trying to create a Form with a sign grade of 151 and an exec grade of 1"
      << std::endl;
  try {
    Form f4("Form 4", 151, 1);
    std::cout << f4 << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

	// Signing Forms
	std::cout << "-------------------------------------------------------------" << std::endl;
	std::cout << "Signing Form 1 with Bureaucrat 1" << std::endl;
	b1.signForm(f1);
	std::cout << f1 << std::endl;

	std::cout << "--------------"<< std::endl;
	std::cout << "Signing Form 1 with Bureaucrat 2" << std::endl;
	b2.signForm(f1);
	std::cout << f1 << std::endl;

	std::cout << "--------------------------------"<< std::endl;
	std::cout << "Signing Form 2 with Bureaucrat 1" << std::endl;
	b1.signForm(f2);
	std::cout << f2 << std::endl;

	std::cout << "--------------"<< std::endl;
	std::cout << "Signing Form 2 with Bureaucrat 2" << std::endl;
	b2.signForm(f2);
	std::cout << f2 << std::endl;

	return (0);
}
