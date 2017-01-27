/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.template.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:45:53 by aleblanc          #+#    #+#             */
/*   Updated: 2017/01/27 10:56:04 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef OPERAND_TEMPLATE_HPP
#define OPERAND_TEMPLATE_HPP

#include "IOperand.hpp"
#include "Factory.class.hpp"
#include "Error.class.hpp"
#include <math.h>


template< typename T >
class Operand : public IOperand {

  public:

    // Canonical form
    Operand<T>(void) {
      return;
    }

    ~Operand<T>(void) {
      return;
    }

    Operand<T>(Operand<T> const & src) {
      *this = src;
      return;
    }

    Operand<T> &  operator=(Operand<T> const & src) {
      if (this != &src) {
        this->_value = src.getValue;
        this->_type = src.getType;
        this->_precision = src.getPrecision;
        this->_str = src.toString;
      }
      return *this;
    }
    // Canonical form

    Operand<T>(eOperandType type, std::string const & value) : _type(type), _precision(0) {
      if (stold(value, NULL) > std::numeric_limits<T>::max())
        throw OverflowException();
      else if (stold(value, NULL) < std::numeric_limits<T>::lowest())
        throw UnderflowException();
      this->_str = std::to_string(static_cast<T>(stod(value, NULL)));
      this->_value = static_cast<T>(stod(value, NULL));
    }

    // Getter
    T             getValue(void) const {
      return this->_value;
    }

    int           getPrecision(void) const {
      return this->_precision;
    }

    eOperandType  getType(void) const {
      return this->_type;
    }

    std::string const & toString( void ) const {
      return this->_str;
    }
    // Getter

    // Operator
    IOperand const * operator+( IOperand const & src ) const {
      return Factory::Factory().createOperand((this->_type > src.getType()) ? this->_type : src.getType(),
          std::to_string(static_cast<double>(stod(this->_str, NULL)) + static_cast<double>(stod(src.toString(), NULL))));
    }
    IOperand const * operator-( IOperand const & src ) const {
      return Factory::Factory().createOperand((this->_type > src.getType()) ? this->_type : src.getType(),
          std::to_string(static_cast<double>(stod(this->_str, NULL)) - static_cast<double>(stod(src.toString(), NULL))));
    }

    IOperand const * operator*( IOperand const & src ) const {
      return Factory::Factory().createOperand((this->_type > src.getType()) ? this->_type : src.getType(),
          std::to_string(static_cast<double>(stod(this->_str, NULL)) * static_cast<double>(stod(src.toString(), NULL))));
    }
    IOperand const * operator/( IOperand const & src ) const {
      if (static_cast<T>(stod(src.toString(), NULL)) == 0 || this->_value == 0)
        throw byZeroException();
      return Factory::Factory().createOperand((this->_type > src.getType()) ? this->_type : src.getType(),
          std::to_string(static_cast<double>(stod(this->_str, NULL)) / static_cast<double>(stod(src.toString(), NULL))));
    }
    IOperand const * operator%( IOperand const & src ) const {
      if (static_cast<T>(stod(src.toString(), NULL)) == 0 || this->_value == 0)
        throw byZeroException();
      return Factory::Factory().createOperand((this->_type > src.getType()) ? this->_type : src.getType(),
          std::to_string(fmod(static_cast<double>(stod(this->_str, NULL)), static_cast<double>(stod(src.toString(), NULL)))));
    }
    // Operator

  private:

    T             _value;
    eOperandType  _type;
    int           _precision;
    std::string   _str;

};

#endif
