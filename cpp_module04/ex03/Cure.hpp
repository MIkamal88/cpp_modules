/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:40:49 by m_kamal           #+#    #+#             */
/*   Updated: 2024/03/24 16:40:49 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
public:
  // Constructors
  Cure(void);
  Cure(const Cure &source);
  // Destructor
  virtual ~Cure(void);
  // Operator Overload
  Cure &operator=(const Cure &other);

  // Member Functions
  AMateria *clone(void) const;
  void use(ICharacter &target);
};

#endif
