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
#include "Brain.hpp"

class Cat : public Animal {
private:
  Brain *_Brain;

public:
  // Constructors
  Cat(void);
  Cat(Cat const &src);
  // Destructor
  virtual ~Cat(void);

  // Copy Assignment Operator
  Cat &operator=(const Cat &rhs);

  // Member functions
  virtual void makeSound(void) const;
};

#endif
