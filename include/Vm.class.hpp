/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vm.class.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <aleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:11:09 by aleblanc          #+#    #+#             */
/*   Updated: 2017/01/26 15:21:37 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_HPP
#define VM_HPP

#define "IOperand.hpp"

class Vm {

  public:
    Vm(void);
    ~Vm(void);
    Vm(Vm const & src);
    Vm &  operator=(Vm consr & src);

    void  push();
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

  private:

    std::list<IOperand const *>   _stack;

};

#endif
