/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instruction.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <aleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 08:40:51 by aleblanc          #+#    #+#             */
/*   Updated: 2017/02/07 13:05:32 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include "abstract.hpp"
#include <regex>

class Instruction {

  public:
    Instruction(void);
    ~Instruction(void);
    Instruction(Instruction const & src);
    Instruction &  operator=(Instruction const & src);

    Instruction(std::string line);

    std::string   getAction(void) const;
    eOperandType  getType(void) const;
    std::string   getValue(void) const;
    std::string   getError(void) const;

  private:

    void          storeInstruction(std::string line);
    std::string   _action;
    eOperandType  _type;
    std::string   _value;
    std::string   _error;

};

#endif
