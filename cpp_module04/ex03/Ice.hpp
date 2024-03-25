/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:24:11 by m_kamal           #+#    #+#             */
/*   Updated: 2024/03/24 16:24:11 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cure_HPP
#define Cure_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
public:
  // Constructors
  Ice(void);
  Ice(const Ice &source);
  // Destructor
  virtual ~Ice(void);
  // Operator Overload
  Ice &operator=(const Ice &other);

  // Member Functions
  AMateria *clone(void) const;
  void use(ICharacter &target);
};

#endif
