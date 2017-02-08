/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instruction.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <aleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 08:41:05 by aleblanc          #+#    #+#             */
/*   Updated: 2017/02/08 11:28:01 by aleblanc         ###   ########.fr       */
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

Instruction::Instruction(std::string line) : _type(Nop), _error("") {
  char * str = new char[line.size() + 1];
  std::copy(line.begin(), line.end(), str);
  str[line.size()] = '\0';

  if (line.empty())
    this->_error = "Empty line";
  else if (std::regex_match(line, std::regex("^(\\s*)?;(.*)$")))
    this->_action = "comment";
  else if (std::regex_match(line, std::regex("^(\\s*)?(pop|dump|add|sub|mul|div|mod|print|exit|cos|sin|tan|sqrt|pow)(\\s*)?(;.*)?$")))
    this->_action = std::strtok(str, " \t;");
  else if (!std::regex_match(line, std::regex("(.*)(push|assert)(.*)")))
    this->_error = "Unknow instruction";
  else if (std::regex_match(line, std::regex("^(\\s*)?(push|assert)(\\s+)(((int8|int16|int32)[(]-?[0-9]+[)])|((float|double)[(]-?[0-9]+(.?[0-9]+)?[)]))(\\s*)(;.*)?$")))
    storeInstruction(str);
  else
    this->_error = "Lexical";

  delete [] str;
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
  else if (line.find("double") != std::string::npos)
    this->_type = Double;

  char * str = new char[line.size() + 1];
  std::copy(line.begin(), line.end(), str);
  str[line.size()] = '\0';

  this->_action = std::strtok(str, " \t");
  this->_value = line.substr(line.find('(') + 1, line.find(')') - line.find('(') - 1);

  delete [] str;
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

std::string     Instruction::getError(void) const {
  return this->_error;
}
// Getter
