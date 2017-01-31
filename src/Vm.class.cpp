/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vm.class.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <aleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:11:25 by aleblanc          #+#    #+#             */
/*   Updated: 2017/01/31 09:18:43 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vm.class.hpp"

// Canonical form
Vm::Vm(void) {
  return;
}

Vm::~Vm(void) {
  return;
}

Vm::Vm(Vm const & src) {
  *this = src;
  return;
}

Vm & Vm::operator=(Vm const & src) {
  if (this != &src) {
    this->_stack = src.getStack();
    this->_instruction = src.getInstruction();
    this->_exit = src.getExit();
  }
  return *this;
}
// Canonical form

void    Vm::storeInstruction(std::string line) {
  this->_instruction.push_back(new Instruction::Instruction(line));
  if (this->_instruction.back()->getAction() == "exit") {
    this->_exit = true;
  }
}

void    Vm::executeInstruction(void) {
 for (unsigned int i = 0; i < this->_instruction.size(); i++) {}

    std::cout << this->_instruction.at(2)->getAction() << std::endl;
    std::cout << this->_instruction.at(0)->getAction() << std::endl;
    std::cout << this->_instruction.at(1)->getAction() << std::endl;
    std::cout << this->_instruction.at(2)->getAction() << std::endl;
    std::cout << this->_instruction.at(3)->getAction() << std::endl;
    std::cout << this->_instruction.at(4)->getAction() << std::endl;
//  while (!this->_instruction.empty()) {
//  }
}

// Getter
std::vector<IOperand const *>     Vm::getStack(void) const{
  return this->_stack;
}

std::vector<Instruction const *>  Vm::getInstruction(void) const {
  return this->_instruction;
}

bool                              Vm::getExit(void) const {
  return this->_exit;
}
// Getter
