/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 08:49:13 by m_kamal           #+#    #+#             */
/*   Updated: 2024/01/25 08:49:13 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors
Cat::Cat(void) : Animal("Cat") {
  std::cout << "Cat default constructor called" << std::endl;
  this->_Brain = new Brain();
}

Cat::Cat(Cat const &src) : Animal(src) {
  if (this == &src)
    return;
  this->_type = src._type;
  this->_Brain = new Brain(*src._Brain);
  std::cout << "Cat copy constructor called" << std::endl;
}

// Destructor
Cat::~Cat(void) {
  delete this->_Brain;
  std::cout << "Cat destructor called" << std::endl;
}

// Copy Assignment Operator
Cat &Cat::operator=(const Cat &other) {
  if (this != &other) {
    this->_type = other._type;
    this->_Brain = new Brain(*other._Brain);
  }
  return (*this);
}

// Member functions
void Cat::makeSound(void) const { std::cout << "Cat says: Meow" << std::endl; }
