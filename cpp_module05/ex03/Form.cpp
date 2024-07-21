/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:28:42 by m_kamal           #+#    #+#             */
/*   Updated: 2024/05/14 15:28:42 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructors and destructor
Form::Form(void)
    : _name("Default"), _signed(false), _sign_grade(1), _exec_grade(1) {}

Form::Form(std::string name, int sign_grade, int exec_grade)
    : _name(name),
      _signed(false),
      _sign_grade(sign_grade),
      _exec_grade(exec_grade) {
  if (sign_grade < _max_grade || exec_grade < _max_grade)
    throw Form::GradeTooHighException();
  else if (sign_grade > _min_grade || exec_grade > _min_grade)
    throw Form::GradeTooLowException();
  else
    _signed = false;
}

Form::Form(const Form &source)
    : _name(source._name),
      _signed(source._signed),
      _sign_grade(source._sign_grade),
      _exec_grade(source._exec_grade) {
  *this = source;
}

Form::~Form(void) {}

// Operator overload
Form &Form::operator=(const Form &source) {
  if (this == &source)
    return (*this);
  _signed = source._signed;
  return (*this);
}

// Getters
std::string Form::getName(void) const {
  return (_name);
}

bool Form::getSign(void) const {
  return (_signed);
}

int Form::getSignGrade(void) const {
  return (_sign_grade);
}

int Form::getExecGrade(void) const {
  return (_exec_grade);
}

// Member Functions
void Form::beSigned(Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > _sign_grade)
    throw Form::GradeTooLowException();
  else
    _signed = true;
}

// Operator << overload
std::ostream &operator<<(std::ostream &os, const Form &form) {
  os << form.getName() << ", form grade to sign " << form.getSignGrade()
     << ", form grade to execute " << form.getExecGrade() << ".";
  return (os);
}
