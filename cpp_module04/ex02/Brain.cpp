/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:50:36 by m_kamal           #+#    #+#             */
/*   Updated: 2024/03/21 15:50:36 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Constructors
Brain::Brain(void) { std::cout << "Brain Constructed." << std::endl; }

Brain::Brain(const Brain &src) { *this = src; }

// Destructor
Brain::~Brain(void) { std::cout << "Brain destroyed." << std::endl; }

// Copy Assignment Operator
Brain &Brain::operator=(const Brain &other) {
  if (this != &other)
    for (int i = 0; i < 100; i++)
      this->ideas[i] = other.ideas[i];
  return *this;
}
