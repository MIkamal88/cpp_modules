/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:18:52 by m_kamal           #+#    #+#             */
/*   Updated: 2024/01/25 09:18:52 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors
Dog::Dog(void) : Animal("Dog") {
  _Brain = new Brain();
  std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const &src) : Animal(src) {
  if (this == &src)
    return;
  this->_type = src._type;
  this->_Brain = new Brain(*src._Brain);
  std::cout << "Dog copy constructor called" << std::endl;
}

// Destructor
Dog::~Dog(void) {
  delete this->_Brain;
  std::cout << "Dog destructor called" << std::endl;
}

// Copy Assignment Operator
Dog &Dog::operator=(Dog const &other) {
  if (this != &other) {
    this->_type = other._type;
    this->_Brain = new Brain(*other._Brain);
  }
  return (*this);
}

// Member functions
void Dog::makeSound(void) const { std::cout << "Dog says: Woof" << std::endl; }
