/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 10:51:01 by m_kamal           #+#    #+#             */
/*   Updated: 2024/05/19 10:51:01 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form {
 private:
  std::string _target;

 public:
  // Constructors
  ShrubberyCreationForm(void);
  ShrubberyCreationForm(std::string target);
  ShrubberyCreationForm(ShrubberyCreationForm const &src);
  // Destructor
  virtual ~ShrubberyCreationForm(void);
  // Operators
  ShrubberyCreationForm &operator=(ShrubberyCreationForm const &source);
  // Member functions
  std::string getTarget(void) const;
  void execute(Bureaucrat const &executor) const;
  // Exceptions
  class FileNotOpenedException : public std::exception {
   public:
    virtual const char *what() const throw() {
      return RED "Error: could not open file." RESET;
    }
  };
};

#endif
