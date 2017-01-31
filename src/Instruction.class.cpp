/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instruction.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <aleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 08:41:05 by aleblanc          #+#    #+#             */
/*   Updated: 2017/01/31 08:51:30 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Instruction.class.hpp"
#include "Error.class.hpp"

// Canonical form
Instruction::Instruction(void) {
  return;
}

Instruction::~Instruction(void) {
  return;
}

Instruction::Instruction(Instruction const & src) {
  *this = src;
  return;
}

Instruction & Instruction::operator=(Instruction const &) {
  return *this;
}
// Canonical form

Instruction::Instruction(std::string line) : _type(Nop) {
  if (line == "pop" || line == "dump" || line== "add" ||
      line == "sub" || line == "mul" || line == "div" ||
      line == "mod" || line == "print" || line == "exit")
    this->_action = line;
  else if (line.at(0) == ';') {}
  else if (!std::regex_match(line, std::regex("(.*)(push|assert)(.*)")))
    throw unknowException();
  else if (std::regex_match(line, std::regex("^(push|assert) (((int8|int16|int32)[(]-?[0-9]+[)])|((float|double)[(]-?[0-9]+(.?[0-9]+)?[)]))$")))
    storeInstruction(line);
  else
    throw lexicalException();
  return;
}

void    Instruction::storeInstruction(std::string line) {

  if (line.find("int8") != std::string::npos)
    this->_type = Int8;
  else if (line.find("int16") != std::string::npos)
    this->_type = Int16;
  else if (line.find("int32") != std::string::npos)
    this->_type = Int32;
  else if (line.find("float") != std::string::npos)
    this->_type = Float;
  else
    this->_type = Double;

  this->_action = line.substr(0, line.find(' '));
  this->_value = line.substr(line.find('(') + 1, line.find(')') - line.find('(') - 1);
}

// Getter
std::string     Instruction::getAction(void) const {
  return this->_action;
}

eOperandType    Instruction::getType(void) const {
  return this->_type;
}

std::string     Instruction::getValue(void) const {
  return this->_value;
}
// Getter
