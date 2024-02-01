/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:07:24 by m_kamal           #+#    #+#             */
/*   Updated: 2024/02/01 09:07:24 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
  // Constructors
  WrongCat(void);
  WrongCat(std::string type);
  WrongCat(WrongCat const &other);
  // Destructor
  ~WrongCat(void);

  // Copy Assignment Operator
  WrongCat &operator=(WrongCat const &other);
};

#endif
