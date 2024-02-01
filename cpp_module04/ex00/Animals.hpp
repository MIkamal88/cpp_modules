/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animals.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:38:01 by m_kamal           #+#    #+#             */
/*   Updated: 2024/01/19 10:38:01 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMALS_HPP
#define ANIMALS_HPP

#include <iostream>

// Color codes
const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";

class Animal {
	 protected:
		std::string _type;

	 public:
		// Constructors
		Animal(void);
		Animal(std::string type);
		Animal(Animal const &src);
		// Destructor
		virtual ~Animal(void);

		// Copy Assignment Operator
		Animal &operator=(Animal const &rhs);

		// Member functions
		std::string getType(void) const;
		virtual void makeSound(void) const;
};

#endif
