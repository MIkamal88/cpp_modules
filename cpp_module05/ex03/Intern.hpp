/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:20:07 by m_kamal           #+#    #+#             */
/*   Updated: 2024/05/19 14:20:07 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"

enum FormType { SHRUBBERY_CREATION, ROBOTOMY_REQUEST, PRESIDENTIAL_PARDON };

class Intern {
private:
  std::string _formTypes[3];

public:
  // Constructors and Destructor
  Intern();
  ~Intern();
  // Member Functions
  Form *makeform(std::string formName, std::string target);
  // Exceptions
  class FormTypeNotFoundException : public std::exception {
    virtual const char *what() const throw() { return "Form type not found!"; }
  };
};

#endif
