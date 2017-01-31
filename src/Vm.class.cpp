/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vm.class.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <aleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:11:25 by aleblanc          #+#    #+#             */
/*   Updated: 2017/01/31 14:06:21 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vm.class.hpp"

// Canonical form
Vm::Vm(void) {
  this->_map["pop"] = &Vm::pop;
  this->_map["dump"] = &Vm::dump;
  this->_map["add"] = &Vm::add;
  this->_map["sub"] = &Vm::sub;
  this->_map["mul"] = &Vm::mul;
  this->_map["div"] = &Vm::div;
  this->_map["mod"] = &Vm::mod;
  this->_map["print"] = &Vm::print;
  this->_map["exit"] = &Vm::exit;
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
  for (unsigned int i = 0; i < this->_instruction.size(); i++) {
    if (this->_instruction.at(i)->getAction() == "push")
      Vm::push(this->_instruction.at(i));
    else if (this->_instruction.at(i)->getAction() == "assert")
      Vm::assert(this->_instruction.at(i));
    else if (this->_instruction.at(i)->getAction() == "comment") {}
    else
      (this->*_map[this->_instruction.at(i)->getAction()])();
  }
}

void    Vm::push(Instruction const * src) {
  std::cout << "In PUSH" << std::endl;
  this->_stack.push_back(Factory::Factory().createOperand(src->getType(), src->getValue()));
}

void    Vm::assert(Instruction const * src) {
  std::cout << "In ASSERT" << std::endl;
  if (src->getType() != this->_stack.back()->getType()
      || std::to_string(static_cast<double>(stod(src->getValue(), NULL))) != this->_stack.back()->toString())
    throw assertException();
}

void    Vm::pop(void) {
  std::cout << "In POP" << std::endl;
  if (this->_stack.size() != 0)
    this->_stack.pop_back();
  else
    throw emptyException();
}

void    Vm::dump(void) {
  std::cout << "In DUMP" << std::endl;
  for (int i = this->_stack.size() - 1 ; i >= 0 ; i--) {
    // THIS IS NECESSARY TO PUT OUT STRING IN A VARIABLE ???
    std::cout << this->_stack.at(i)->toString() << std::endl;
  }
}

void    Vm::add(void) {
  std::cout << "In ADD" << std::endl;
  if (this->_stack.size() >= 2) {
    IOperand const * i = this->_stack.rbegin()[0];
    IOperand const * j = this->_stack.rbegin()[1];
    this->_stack.pop_back();
    this->_stack.pop_back();
    this->_stack.push_back(*i + *j);
  }
  else
    throw toSmallException();
}

void    Vm::sub(void) {
  std::cout << "In SUB" << std::endl;
  if (this->_stack.size() >= 2) {
    IOperand const * i = this->_stack.rbegin()[0];
    IOperand const * j = this->_stack.rbegin()[1];
    this->_stack.pop_back();
    this->_stack.pop_back();
    this->_stack.push_back(*j - *i);
  }
  else
    throw toSmallException();
}

void    Vm::mul(void) {
  std::cout << "In MUL" << std::endl;
  if (this->_stack.size() >= 2) {
    IOperand const * i = this->_stack.rbegin()[0];
    IOperand const * j = this->_stack.rbegin()[1];
    this->_stack.pop_back();
    this->_stack.pop_back();
    this->_stack.push_back(*i * *j);
  }
  else
    throw toSmallException();
}

void    Vm::div(void) {
  std::cout << "In DIV" << std::endl;
  if (this->_stack.size() >= 2) {
    IOperand const * i = this->_stack.rbegin()[0];
    IOperand const * j = this->_stack.rbegin()[1];
    this->_stack.pop_back();
    this->_stack.pop_back();
    this->_stack.push_back(*j / *i);
  }
  else
    throw toSmallException();
}

void    Vm::mod(void) {
  std::cout << "In MOD" << std::endl;
  if (this->_stack.size() >= 2) {
    IOperand const * i = this->_stack.rbegin()[0];
    IOperand const * j = this->_stack.rbegin()[1];
    this->_stack.pop_back();
    this->_stack.pop_back();
    this->_stack.push_back(*j % *i);
  }
  else
    throw toSmallException();
}

void    Vm::print(void) {
  std::cout << "In PRINT" << std::endl;
  if (this->_stack.back()->getType() == Int8)
    std::cout <<  "Int8" << std::endl;
  else
    throw noPrintableException();
}

void    Vm::exit(void) {
  std::cout << "In EXIT" << std::endl;
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
