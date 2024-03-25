/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 13:37:21 by m_kamal           #+#    #+#             */
/*   Updated: 2024/03/23 13:37:21 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";

class AMateria {
protected:
  std::string _type;

public:
  // Constructors
  AMateria(void);
  AMateria(std::string const &type);
  AMateria(const AMateria &source);
  // Destructor
  virtual ~AMateria(void);

  // Operator Overload
  AMateria &operator=(const AMateria &other);

  // Member Functions
  std::string const &getType() const; // Returns the materia type
  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target);
};

#endif
