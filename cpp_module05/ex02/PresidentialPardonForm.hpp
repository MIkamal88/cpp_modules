/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardionForm.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 10:51:52 by m_kamal           #+#    #+#             */
/*   Updated: 2024/05/19 10:51:52 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {
 private:
  std::string _target;

 public:
  // Constructors
  PresidentialPardonForm(void);
  PresidentialPardonForm(std::string target);
  PresidentialPardonForm(const PresidentialPardonForm &source);
  // Destructor
  virtual ~PresidentialPardonForm(void);
  // Operators
  PresidentialPardonForm &operator=(const PresidentialPardonForm &source);
  // Member functions
  std::string getTarget(void) const;
  void execute(Bureaucrat const &executor) const;
};

#endif
