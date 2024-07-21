/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:26:46 by m_kamal           #+#    #+#             */
/*   Updated: 2024/05/19 16:26:46 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main(void) {
  Intern someRandomIntern;
  Form *rrf;

  try {
    rrf = someRandomIntern.makeform("robotomy request", "Bender");
    std::cout << *rrf << std::endl << std::endl;
    delete rrf;
    rrf = someRandomIntern.makeform("presidential pardon", "Bender");
    std::cout << *rrf << std::endl << std::endl;
    delete rrf;
    rrf = someRandomIntern.makeform("shrubbery creation", "Bender");
    std::cout << *rrf << std::endl << std::endl;
    delete rrf;
    rrf = someRandomIntern.makeform("shrubbery", "Bender");
    std::cout << *rrf << std::endl << std::endl;
    delete rrf;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return (0);
}
