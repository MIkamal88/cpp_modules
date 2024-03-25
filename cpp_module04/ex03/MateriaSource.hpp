/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:35:13 by m_kamal           #+#    #+#             */
/*   Updated: 2024/03/25 10:35:13 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria *_inventory[4];
	public:
		// Constructors
		MateriaSource(void);
		MateriaSource(const MateriaSource &source);
		virtual ~MateriaSource(void);

		// Operator overload
		MateriaSource &operator=(const MateriaSource &other);

		// Member Functions
		void learnMateria(AMateria *);
		AMateria *createMateria(std::string const &type);
};
#endif // !MATERIASOURCE_HPP
