/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <aleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 09:52:32 by aleblanc          #+#    #+#             */
/*   Updated: 2017/01/31 16:23:18 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Factory.class.hpp"
#include "Operand.template.hpp"

Factory::FABRIC Factory::_create = {
  &Factory::createInt8,
  &Factory::createInt16,
  &Factory::createInt32,
  &Factory::createFloat,
  &Factory::createDouble,
};

// Canonical form
Factory::Factory(void) {
  return;
}

Factory::~Factory(void) {
  return;
}

Factory::Factory(Factory const & src) {
  *this = src;
  return;
}

Factory & Factory::operator=(Factory const &) {
  return *this;
}
// Canonical form

IOperand const * Factory::createOperand(eOperandType type, std::string const & value) const {
  return (this->*_create[type])(value);
}

IOperand const * Factory::createInt8( std::string const & value ) const {
  return new Operand<int8_t>(Int8, value);
}
IOperand const * Factory::createInt16( std::string const & value ) const {
  return new Operand<int16_t>(Int16, value);
}
IOperand const * Factory::createInt32( std::string const & value ) const{
  return new Operand<int32_t>(Int32, value);
}
IOperand const * Factory::createFloat( std::string const & value ) const {
  return new Operand<float>(Float, value);
}
IOperand const * Factory::createDouble( std::string const & value ) const {
  return new Operand<double>(Double, value);
}

