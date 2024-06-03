/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 08:25:57 by m_kamal           #+#    #+#             */
/*   Updated: 2024/01/12 08:25:57 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
  int _rawBits;
  static const int _fractional_bits = 8;

public:
  Fixed(void);
  Fixed(const Fixed &fixed);
  ~Fixed(void);

  Fixed &operator=(const Fixed &fixed);

  int getRawBits(void) const;
  void setRawBits(int const raw);
};

#endif
