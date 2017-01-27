/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 09:20:15 by aleblanc          #+#    #+#             */
/*   Updated: 2017/01/27 10:55:37 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operand.template.hpp"
#include "Vm.class.hpp"
#include <fstream>

int main(int argc, char **argv) {

  try {
    Vm  vm = Vm();
    (void)argc;
    if (argc == 2) {
      std::string       line;
      std::ifstream     file(argv[1]);

      if (file.is_open()) {
        while (getline(file, line)) {
          vm.storeInstruction(line);
        }

        file.close();
      }


    }
    IOperand const *a;
    IOperand const *b;
    IOperand const *c;
    IOperand const *d;
    a = Factory::Factory().createOperand(Int8, "-526");
    b = Factory::Factory().createOperand(Double, "100.1");

    c = *b + *a;
    std::cout << c->toString() << std::endl;
    std::cout << c->getType() << std::endl;

    d = *a + *b;
    std::cout << d->toString() << std::endl;
    std::cout << d->getType() << std::endl;
  } catch (const Error & err) {
    std::cout << "ERROR: " << err.what() << std::endl;
  }
  return 0;
}
