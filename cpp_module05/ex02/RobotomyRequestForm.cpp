/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 10:51:36 by m_kamal           #+#    #+#             */
/*   Updated: 2024/05/19 10:51:36 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

// Constructors
RobotomyRequestForm::RobotomyRequestForm(void)
    : Form("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : Form("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &source)
    : Form(source), _target(source._target) {}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm(void) {}

// Operator
RobotomyRequestForm &RobotomyRequestForm::operator=(
    const RobotomyRequestForm &source) {
  if (this == &source)
    return (*this);
  _target = source._target;
  return (*this);
}

// Member functions
std::string RobotomyRequestForm::getTarget(void) const {
  return (_target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  if (!this->getSign())
    throw Form::FormNotSignedException();
  if (executor.getGrade() > this->getExecGrade())
    throw Form::GradeTooLowException();
  std::cout << "*drilling noises* ";
  if (rand() % 2)
    std::cout << _target << " has been robotomized successfully." << std::endl;
  else
    std::cout << _target << " robotomization failed." << std::endl;
}
