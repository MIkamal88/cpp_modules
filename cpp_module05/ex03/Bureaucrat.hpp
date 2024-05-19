/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:08:55 by m_kamal           #+#    #+#             */
/*   Updated: 2024/03/25 16:08:55 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <ostream>

class Form;

class Bureaucrat {
private:
  std::string const _name;
  static int const _max_grade = 1;
  static int const _min_grade = 150;
  int _grade;

public:
  // Constructors and deconstructors
  Bureaucrat(void);
  Bureaucrat(std::string name, int grade);
  Bureaucrat(const Bureaucrat &source);
  ~Bureaucrat(void);

  // Assignment operator overload
  Bureaucrat &operator=(const Bureaucrat &source);

  // Getters
  std::string getName(void) const;
  int getGrade(void) const;

  // Member Functions
  void incrementGrade(void);
  void decrementGrade(void);
  void signForm(Form &form);
	void executeForm(Form const &form) const;

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade too high!"; }
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade too low!"; }
  };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
