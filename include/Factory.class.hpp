/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <aleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 09:52:43 by aleblanc          #+#    #+#             */
/*   Updated: 2017/01/26 14:32:49 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTORY_CLASS_HPP
#define FACTORY_CLASS_HPP

#include "IOperand.hpp"

class Factory {

  public:

    Factory(void);
    ~Factory(void);
    Factory(Factory const & src);
    Factory & operator=(Factory const & src);
    IOperand const * createOperand( eOperandType type, std::string const & value ) const;

  private:

    IOperand const * createInt8( std::string const & value ) const;
    IOperand const * createInt16( std::string const & value ) const;
    IOperand const * createInt32( std::string const & value ) const;
    IOperand const * createFloat( std::string const & value ) const;
    IOperand const * createDouble( std::string const & value ) const;

    typedef IOperand const * (Factory::*FABRIC[5]) (std::string const & value) const;
    static FABRIC _create;
};

#endif
