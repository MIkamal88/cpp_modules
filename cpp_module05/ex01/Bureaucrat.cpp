/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:08:47 by m_kamal           #+#    #+#             */
/*   Updated: 2024/03/25 16:08:47 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// Constructors and destructor
Bureaucrat::Bureaucrat(void) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
  if (grade < _max_grade)
    throw Bureaucrat::Bureaucrat::GradeTooHighException();
  else if (grade > _min_grade)
    throw Bureaucrat::Bureaucrat::GradeTooLowException();
  else
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &source) { *this = source; }

Bureaucrat::~Bureaucrat(void) {}

// Operator overload
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &source) {
  if (this == &source)
    return (*this);
  _grade = source._grade;
  return (*this);
}

// Getters
std::string Bureaucrat::getName(void) const { return (_name); }

int Bureaucrat::getGrade(void) const { return (_grade); }

// Member Functions
void Bureaucrat::incrementGrade(void) {
  if (_grade - 1 < _max_grade)
    throw Bureaucrat::GradeTooHighException();
  else
    _grade--;
}

void Bureaucrat::decrementGrade(void) {
  if (_grade + 1 > _min_grade)
    throw Bureaucrat::GradeTooLowException();
  else
    _grade++;
}

// Operator << overload
std::ostream& operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}

// Sign Form
void Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		std::cout << _name << " signs " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << _name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
	}
}
