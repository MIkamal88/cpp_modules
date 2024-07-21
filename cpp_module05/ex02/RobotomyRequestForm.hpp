/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 10:51:24 by m_kamal           #+#    #+#             */
/*   Updated: 2024/05/19 10:51:24 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form {
 private:
  std::string _target;

 public:
  // Constructors
  RobotomyRequestForm(void);
  RobotomyRequestForm(std::string target);
  RobotomyRequestForm(const RobotomyRequestForm &source);
  // Destructor
  virtual ~RobotomyRequestForm(void);
  // Operator
  RobotomyRequestForm &operator=(const RobotomyRequestForm &source);
  // Member functions
  void execute(Bureaucrat const &executor) const;
  std::string getTarget(void) const;
};

#endif
