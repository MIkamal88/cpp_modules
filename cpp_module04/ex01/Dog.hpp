/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:18:30 by m_kamal           #+#    #+#             */
/*   Updated: 2024/01/25 09:18:30 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animals.hpp"

class Dog : public Animal {
public:
	// Constructors
	Dog(void);
	Dog(Dog const &src);
	// Destructor
	virtual ~Dog(void);

	// Copy Assignment Operator
	Dog &operator=(Dog const &rhs);

	// Member functions
	virtual void makeSound(void) const;
};

#endif
