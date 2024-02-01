/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 08:47:55 by m_kamal           #+#    #+#             */
/*   Updated: 2024/01/25 08:47:55 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animals.hpp"

class Cat : public Animal {
public:
  // Constructors
  Cat(void);
  Cat(Cat const &src);
  // Destructor
  virtual ~Cat(void);

  // Copy Assignment Operator
  Cat &operator=(Cat const &rhs);

  // Member functions
  virtual void makeSound(void) const;
};

#endif
