/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vm.class.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <aleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:11:09 by aleblanc          #+#    #+#             */
/*   Updated: 2017/01/27 10:55:58 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_HPP
#define VM_HPP

#include <vector>
#include "IOperand.hpp"
#include "Instruction.class.hpp"

class Vm {

  public:
    Vm(void);
    ~Vm(void);
    Vm(Vm const & src);
    Vm &  operator=(Vm const & src);

    void storeInstruction(std::string line);

/*    void  push();
    void  pop();
    void  dump();
    void  assert();
    void  add();
    void  sub();
    void  mul();
    void  div();
    void  mod();
    void  print();
    void  exit();
*/
  private:

    std::vector<IOperand const *>     _stack;
    std::vector<Instruction const *>  _instruction;

};

#endif
