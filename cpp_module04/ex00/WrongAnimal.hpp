/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:36:52 by m_kamal           #+#    #+#             */
/*   Updated: 2024/01/25 09:36:52 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "Animals.hpp"

class WrongAnimal {
protected:
  std::string _type;

public:
  // Constructors
  WrongAnimal(void);
  WrongAnimal(std::string type);
  WrongAnimal(WrongAnimal const &src);
  // Destructor
  virtual ~WrongAnimal(void);

  // Copy Assignment Operator
  WrongAnimal &operator=(WrongAnimal const &rhs);

  // Member functions
  std::string getType(void) const;
  virtual void makeSound(void) const;
};

#endif
