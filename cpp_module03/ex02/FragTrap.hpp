/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:24:24 by m_kamal           #+#    #+#             */
/*   Updated: 2024/01/19 10:24:24 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap {
public:
	// Constructors
	FragTrap(void);
	FragTrap(std::string &name);
	FragTrap(FragTrap const &src);
	// Destructor
	~FragTrap(void);

	// Copy assignment operator
	FragTrap &operator=(FragTrap const &other);

	// Member Functions
	void highFivesGuys(void);
};

#endif
