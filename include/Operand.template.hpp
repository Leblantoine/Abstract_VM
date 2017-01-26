/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.template.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:45:53 by aleblanc          #+#    #+#             */
/*   Updated: 2017/01/26 14:32:55 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef OPERAND_TEMPLATE_HPP
#define OPERAND_TEMPLATE_HPP

#include "IOperand.hpp"
#include "Factory.class.hpp"
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

    // Exception
    class OverflowException : public std::exception {
      public:
        OverflowException(void) { return; }
        OverflowException(OverflowException const & src) { *this = src; return; }
        ~OverflowException(void) throw() { return; }
        OverflowException & operator=(OverflowException const &) { return *this; }
        virtual const char * what() const throw() { return ("Value overflow"); }
    };

    class UnderflowException : public std::exception {
      public:
        UnderflowException(void) { return; }
        UnderflowException(UnderflowException const & src) { *this = src; return; }
        ~UnderflowException(void) throw() { return; }
        UnderflowException & operator=(UnderflowException const &) { return *this; }
        virtual const char * what() const throw() { return ("Value underflow"); }
    };

    class byZeroException : public std::exception {
      public:
        byZeroException(void) { return; }
        byZeroException(byZeroException const & src) { *this = src; return; }
        ~byZeroException(void) throw() { return; }
        byZeroException & operator=(byZeroException const &) { return *this; }
        virtual const char * what() const throw() { return ("Division / modulo by 0"); }
    };
    // Exception

  private:

    T             _value;
    eOperandType  _type;
    int           _precision;
    std::string   _str;

};

#endif
