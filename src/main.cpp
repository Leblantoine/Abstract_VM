/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 09:20:15 by aleblanc          #+#    #+#             */
/*   Updated: 2017/01/31 09:04:12 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operand.template.hpp"
#include "Vm.class.hpp"
#include <fstream>

int main(int argc, char **argv) {

  try {
    Vm  vm = Vm();
    std::string       line;
    if (argc == 2) {
      std::ifstream     file(argv[1]);

      if (file.is_open()) {
        while (getline(file, line)) {
          vm.storeInstruction(line);
        }
        file.close();
      }
    } else {
      while (getline(std::cin, line) && line != ";;") {
        vm.storeInstruction(line);
      }
    }
    
    vm.executeInstruction();
    /*
    IOperand const *a;
    IOperand const *b;
    IOperand const *c;
    IOperand const *d;
    a = Factory::Factory().createOperand(Int16, "-526");
    b = Factory::Factory().createOperand(Double, "100.1");

    c = *b + *a;
    std::cout << c->toString() << std::endl;
    std::cout << c->getType() << std::endl;

    d = *a + *b;
    std::cout << d->toString() << std::endl;
    std::cout << d->getType() << std::endl;

  */
  } catch (const Error & err) {
    std::cout << "ERROR: " << err.what() << std::endl;
  }
  return 0;
}
