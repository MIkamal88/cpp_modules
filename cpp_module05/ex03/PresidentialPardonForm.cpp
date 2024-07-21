/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 10:52:04 by m_kamal           #+#    #+#             */
/*   Updated: 2024/05/19 10:52:04 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm(void)
    : Form("PresidentialPardonForm", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : Form("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &src)
    : Form(src), _target(src._target) {}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm(void) {}

// Operators
PresidentialPardonForm &PresidentialPardonForm::operator=(
    const PresidentialPardonForm &source) {
  if (this == &source)
    return (*this);
  _target = source._target;
  return (*this);
}

// Member functions
std::string PresidentialPardonForm::getTarget(void) const {
  return _target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  if (!this->getSign())
    throw Form::FormNotSignedException();
  if (executor.getGrade() > this->getExecGrade())
    throw Form::GradeTooLowException();
  std::cout << _target << " has been pardoned by Zafod Beeblebrox."
            << std::endl;
}
