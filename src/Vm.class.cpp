/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vm.class.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <aleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:11:25 by aleblanc          #+#    #+#             */
/*   Updated: 2017/01/27 10:55:33 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vm.class.hpp"

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

Vm & Vm::operator=(Vm const &) {
  return *this;
}

void    Vm::storeInstruction(std::string line) {
  this->_instruction.push_back(new Instruction::Instruction(line));
  std::cout << this->_instruction.back()->getAction() << std::endl;
}
