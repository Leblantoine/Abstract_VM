/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 09:20:15 by aleblanc          #+#    #+#             */
/*   Updated: 2017/01/26 14:33:01 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operand.template.hpp"

int main(void) {

  IOperand const *a;
  IOperand const *b;
  IOperand const *c;
  IOperand const *d;
  try {
    a = Factory::Factory().createOperand(Int16, "526");
    b = Factory::Factory().createOperand(Double, "100.1");

    c = *b + *a;
    std::cout << c->toString() << std::endl;
    std::cout << c->getType() << std::endl;

    d = *a + *b;
    std::cout << d->toString() << std::endl;
    std::cout << d->getType() << std::endl;
  } catch (const std::exception & err) {
    std::cout << "ERROR: " << err.what() << std::endl;
  }
  return 0;
}
