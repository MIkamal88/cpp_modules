/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:20:10 by m_kamal           #+#    #+#             */
/*   Updated: 2024/05/19 14:20:10 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
  _formTypes[0] = "shrubbery creation";
  _formTypes[1] = "robotomy request";
  _formTypes[2] = "presidential pardon";
}

Intern::~Intern() {}

Form *Intern::makeform(std::string formName, std::string target) {
  Form *form = NULL;
  int form_type = -1;

  while (++form_type < 3)
    if (formName == _formTypes[form_type])
      break;

  switch (form_type) {
  case SHRUBBERY_CREATION:
    form = new ShrubberyCreationForm(target);
    break;
  case ROBOTOMY_REQUEST:
    form = new RobotomyRequestForm(target);
    break;
  case PRESIDENTIAL_PARDON:
    form = new PresidentialPardonForm(target);
    break;
  default:
    throw Intern::FormTypeNotFoundException();
    return (NULL);
  }
  std::cout << "Intern creates " << formName << "." << std::endl;
  return (form);
}
