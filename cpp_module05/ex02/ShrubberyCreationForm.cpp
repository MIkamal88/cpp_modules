/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 10:51:12 by m_kamal           #+#    #+#             */
/*   Updated: 2024/05/19 10:51:12 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "fstream"

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm(void)
    : Form("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : Form("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
    : Form(src), _target(src._target) {}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

// Operators
ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    ShrubberyCreationForm const &source) {
  if (this == &source)
    return (*this);
  _target = source._target;
  return (*this);
}

// Member functions
std::string ShrubberyCreationForm::getTarget(void) const {
  return (_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  if (!this->getSign())
    throw Form::FormNotSignedException();
  if (executor.getGrade() > this->getExecGrade())
    throw Form::GradeTooLowException();
  std::ofstream outfile;
  outfile.open((_target + "_shrubbery").c_str());
  if (!outfile.is_open())
    throw FileNotOpenedException();
  outfile << "      /\\      " << std::endl;
  outfile << "     /\\*\\     " << std::endl;
  outfile << "    /\\O\\*\\    " << std::endl;
  outfile << "   /*/\\/\\/\\   " << std::endl;
  outfile << "  /\\O\\/\\*\\/\\  " << std::endl;
  outfile << " /\\*\\/\\*\\/\\/\\ " << std::endl;
  outfile << "/\\O\\/\\/*/\\/O/\\" << std::endl;
  outfile << "      ||      " << std::endl;
  outfile << "      ||      " << std::endl;
  outfile << "      ||      " << std::endl;
  outfile.close();

  std::cout << "Shrubbery has been created by " << executor.getName() << "."
            << std::endl;
}
