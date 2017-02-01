/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 09:20:15 by aleblanc          #+#    #+#             */
/*   Updated: 2017/02/01 12:43:20 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operand.template.hpp"
#include "Vm.class.hpp"
#include "Error.class.hpp"
#include <fstream>

int main(int argc, char **argv) {

  Vm            vm = Vm();
  std::string   line;
  std::ifstream file(argv[1]);

  try {

    if (argc == 2 && file)
      while (getline(file, line))
        vm.storeInstruction(line);
    else if (argc == 1)
      while (getline(std::cin, line) && line != ";;")
        vm.storeInstruction(line);
    else
      throw noValidFileException();

    if (vm.getExit())
      vm.executeInstruction();
    else
      throw noExitException();
  } catch (const Error & err) {
    std::cout <<"Line: " << vm.getLine() << " ERROR: " << err.what() << std::endl;
  }
  return 0;
}
