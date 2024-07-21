/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:19:30 by m_kamal           #+#    #+#             */
/*   Updated: 2024/05/14 15:19:30 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
 private:
  static int const _max_grade = 1;
  static int const _min_grade = 150;
  std::string const _name;
  bool _signed;
  int const _sign_grade;
  int const _exec_grade;

 public:
  // Constructors and destructor
  Form(void);
  Form(std::string name, int sign_grade, int exec_grade);
  Form(const Form &source);
  virtual ~Form(void);
  // Assignment operator overload
  Form &operator=(const Form &source);
  // Member Functions
  std::string getName(void) const;
  bool getSign(void) const;
  int getSignGrade(void) const;
  int getExecGrade(void) const;
  void beSigned(Bureaucrat &bureaucrat);
  virtual void execute(Bureaucrat const &executor) const = 0;
  // Exceptions
  class GradeTooHighException : public std::exception {
   public:
    virtual const char *what() const throw() { return "Grade too high!"; }
  };

  class GradeTooLowException : public std::exception {
   public:
    virtual const char *what() const throw() { return "Grade too low!"; }
  };

  class FormNotSignedException : public std::exception {
   public:
    virtual const char *what() const throw() { return "Form not signed"; }
  };
};

// Operator << overload
std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
