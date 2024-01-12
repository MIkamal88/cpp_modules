/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:17:19 by m_kamal           #+#    #+#             */
/*   Updated: 2024/01/12 23:17:19 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
		int								_fixed_point_value;
		static const int	_fractional_bits = 8;
public:
		// Constructors
		Fixed(void);
		Fixed(const int int_value);
		Fixed(const float float_value);
		Fixed(const Fixed &fixed);
		// Destructor
		~Fixed(void);
		// Assignment operator overload
		Fixed &operator=(const Fixed &fixed);
		// Member functions
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float	toFloat(void) const;
		int toInt(void) const;
};

// Non-member functions
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
