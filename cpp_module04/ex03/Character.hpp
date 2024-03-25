/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:57:59 by m_kamal           #+#    #+#             */
/*   Updated: 2024/03/24 16:57:59 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
private:
  std::string _name;
  AMateria *_inventory[4];

public:
  // Constructors
  Character(void);
  Character(std::string const &name);
  Character(const Character &source);
  virtual ~Character(void);

  // Operator Overload
  Character &operator=(const Character &other);
  // Member Functions
  std::string const &getName(void) const;
  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);
};

#endif // !CHARACTER_HPP
