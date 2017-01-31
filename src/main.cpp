/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 09:20:15 by aleblanc          #+#    #+#             */
/*   Updated: 2017/01/31 16:25:00 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operand.template.hpp"
#include "Vm.class.hpp"
#include "Error.class.hpp"
#include <fstream>

int main(int argc, char **argv) {

  try {
    Vm            vm = Vm();
    std::string   line;
    std::ifstream file(argv[1]);

    if (argc == 2 && file.is_open()) {
      while (getline(file, line)) {
        vm.storeInstruction(line);
      }
      file.close();
    } else {
      while (getline(std::cin, line) && line != ";;") {
        vm.storeInstruction(line);
      }
    }
    if (vm.getExit())
      vm.executeInstruction();
    else
      throw noExitException();
  } catch (const Error & err) {
    std::cout << "ERROR: " << err.what() << std::endl;
  }
  return 0;
}
