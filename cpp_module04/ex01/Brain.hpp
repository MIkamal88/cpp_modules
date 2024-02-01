/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:26:42 by m_kamal           #+#    #+#             */
/*   Updated: 2024/02/01 09:26:42 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "iostream"

class Brain {
private:
  std::string ideas[100];

public:
  // Constructors
  Brain();
  Brain(Brain const &src);
  // Destructor
  ~Brain();
  // Operators
  Brain &operator=(Brain const &rhs);
  // Member functions
  std::string *getIdea(void);
};

#endif
