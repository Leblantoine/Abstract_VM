/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 09:20:15 by aleblanc          #+#    #+#             */
/*   Updated: 2017/01/25 16:10:33 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operand.template.hpp"

int main(void) {

  IOperand const *a;
  IOperand const *b;
  try {
    a = Operand<int8_t>::Operand().createOperand(Int8, "28");
    b = Operand<float>::Operand().createOperand(Float, "129382");
  } catch (const std::exception & err) {
    std::cout << "ERROR: " << err.what() << std::endl;
  }
  return 0;
}
