/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:31:38 by aleblanc          #+#    #+#             */
/*   Updated: 2017/01/26 14:32:52 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_HPP
#define IOPERAND_HPP

#include "abstract.hpp"

class IOperand {

  public:

  virtual int           getPrecision( void ) const = 0; // Precision of the type of the instance
  virtual eOperandType  getType( void ) const = 0; // Type of the instance

  virtual IOperand const * operator+( IOperand const & src ) const = 0; // Sum
  virtual IOperand const * operator-( IOperand const & src ) const = 0; // Difference
  virtual IOperand const * operator*( IOperand const & src ) const = 0; // Product
  virtual IOperand const * operator/( IOperand const & src ) const = 0; // Quotient
  virtual IOperand const * operator%( IOperand const & src ) const = 0; // Modulo

  virtual std::string const & toString( void ) const = 0; // String representation of the instance

  virtual ~IOperand( void ) {}

};

#endif
