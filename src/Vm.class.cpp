/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vm.class.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <aleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:11:25 by aleblanc          #+#    #+#             */
/*   Updated: 2017/02/01 12:43:35 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vm.class.hpp"

// Canonical form
Vm::Vm(void) : _exit(false), _line(0) {
  this->_map["pop"] = &Vm::pop;
  this->_map["dump"] = &Vm::dump;
  this->_map["add"] = &Vm::add;
  this->_map["sub"] = &Vm::sub;
  this->_map["mul"] = &Vm::mul;
  this->_map["div"] = &Vm::div;
  this->_map["mod"] = &Vm::mod;
  this->_map["print"] = &Vm::print;
  this->_map["exit"] = &Vm::print;
  // Bonus
  this->_map["sin"] = &Vm::sin;
  this->_map["cos"] = &Vm::cos;
  this->_map["tan"] = &Vm::tan;
  this->_map["sqrt"] = &Vm::sqrt;
  this->_map["pow"] = &Vm::pow;
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
    this->_cout = src.getCout();
    this->_line = src.getLine();
  }
  return *this;
}
// Canonical form

void    Vm::storeInstruction(std::string line) {
  this->_line += 1;
  this->_instruction.push_back(new Instruction::Instruction(line));
  if (this->_instruction.back()->getAction() == "exit") {
    this->_exit = true;
  }
}

void    Vm::executeInstruction(void) {
  this->_line = 0;
  for (unsigned int i = 0; i < this->_instruction.size(); i++) {
    this->_line += 1;
    if (this->_instruction.at(i)->getAction() == "push")
      Vm::push(this->_instruction.at(i));
    else if (this->_instruction.at(i)->getAction() == "assert")
      Vm::assert(this->_instruction.at(i));
    else if (this->_instruction.at(i)->getAction() == "comment") {}
    else if (this->_instruction.at(i)->getAction() == "exit") {
      std::cout << this->_cout;
      break;
    }
    else
      (this->*_map[this->_instruction.at(i)->getAction()])();
  }
}

void    Vm::push(Instruction const * src) {
  this->_stack.push_back(Factory::Factory().createOperand(src->getType(), src->getValue()));
}

void    Vm::assert(Instruction const * src) {
  if (this->_stack.size() == 0)
    throw emptyStackException();
  else if (src->getType() != this->_stack.back()->getType()
      || std::to_string(static_cast<double>(stod(src->getValue(), NULL))) != this->_stack.back()->toString())
    throw assertException();
}

void    Vm::pop(void) {
  if (this->_stack.size() != 0)
    this->_stack.pop_back();
  else
    throw emptyStackException();
}

void    Vm::dump(void) {
  if (this->_stack.size() > 0) {
    for (int i = this->_stack.size() - 1 ; i >= 0 ; i--) {
      this->_cout = this->_cout + this->_stack.at(i)->toString() + "\n";
    }
  }
}

void    Vm::add(void) {
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
  if (this->_stack.back()->getType() == Int8) {
    char ch = static_cast<int8_t>(stod(this->_stack.back()->toString()));
    this->_cout = this->_cout + ch + "\n";
  }
  else
    throw noPrintableException();
}

void    Vm::cos(void) {
  if (this->_stack.size() >= 1) {
    IOperand const * i = this->_stack.rbegin()[0];
    this->_stack.pop_back();
    this->_stack.push_back(Factory::Factory().createOperand(i->getType(), std::to_string(std::cos(stod(i->toString())))));
  }
  else
    throw emptyStackException();
}

void    Vm::sin(void) {
  if (this->_stack.size() >= 1) {
    IOperand const * i = this->_stack.rbegin()[0];
    this->_stack.pop_back();
    this->_stack.push_back(Factory::Factory().createOperand(i->getType(), std::to_string(std::sin(stod(i->toString())))));
  }
  else
    throw emptyStackException();
}

void    Vm::tan(void) {
  if (this->_stack.size() >= 1) {
    IOperand const * i = this->_stack.rbegin()[0];
    this->_stack.pop_back();
    this->_stack.push_back(Factory::Factory().createOperand(i->getType(), std::to_string(std::tan(stod(i->toString())))));
  }
  else
    throw emptyStackException();
}

void    Vm::sqrt(void) {
  if (this->_stack.size() >= 1) {
    IOperand const * i = this->_stack.rbegin()[0];
    this->_stack.pop_back();
    this->_stack.push_back(Factory::Factory().createOperand(i->getType(), std::to_string(std::sqrt(stod(i->toString())))));
  }
  else
    throw emptyStackException();
}

void    Vm::pow(void) {
  if (this->_stack.size() >= 2) {
    IOperand const * i = this->_stack.rbegin()[0];
    IOperand const * j = this->_stack.rbegin()[1];
    this->_stack.pop_back();
    this->_stack.pop_back();
    this->_stack.push_back(Factory::Factory().createOperand((i->getType() > j->getType()) ? i->getType() : j->getType(),
          std::to_string(std::pow(stod(j->toString()), stod(i->toString())))));
  }
  else
    throw toSmallException();
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

std::string                       Vm::getCout(void) const {
  return this->_cout;
}

unsigned int                      Vm::getLine(void) const {
  return this->_line;
}
// Getter
