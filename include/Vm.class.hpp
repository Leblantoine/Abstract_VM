/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vm.class.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <aleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:11:09 by aleblanc          #+#    #+#             */
/*   Updated: 2017/02/01 12:42:21 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_HPP
#define VM_HPP

#include <vector>
#include <map>
#include <cmath>
#include "IOperand.hpp"
#include "Operand.template.hpp"
#include "Instruction.class.hpp"
#include "Factory.class.hpp"
#include "Error.class.hpp"

class Vm {

  public:
    Vm(void);
    ~Vm(void);
    Vm(Vm const & src);
    Vm &  operator=(Vm const & src);

    void    storeInstruction(std::string line);
    void    executeInstruction(void);

    std::vector<IOperand const *>     getStack(void) const;
    std::vector<Instruction const *>  getInstruction(void) const;
    bool                              getExit(void) const;
    std::string                       getCout(void) const;
    unsigned int                      getLine(void) const;

    void  push(Instruction const * src);
    void  pop(void);
    void  dump(void);
    void  assert(Instruction const * src);
    void  add(void);
    void  sub(void);
    void  mul(void);
    void  div(void);
    void  mod(void);
    void  print(void);
    // Bonus
    void  cos(void);
    void  sin(void);
    void  tan(void);
    void  sqrt(void);
    void  pow(void);

  private:

    std::vector<IOperand const *>     _stack;
    std::vector<Instruction const *>  _instruction;
    bool                              _exit;
    std::string                       _cout;
    unsigned int                      _line;

    typedef       void (Vm::*ACTION)(void);
    typedef       std::map<std::string, ACTION> actionMap;
    actionMap     _map;

};

#endif
