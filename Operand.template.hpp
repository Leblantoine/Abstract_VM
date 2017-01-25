/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.template.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:45:53 by aleblanc          #+#    #+#             */
/*   Updated: 2017/01/25 16:10:36 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef OPERAND_TEMPLATE_HPP
#define OPERAND_TEMPLATE_HPP
#include "IOperand.hpp"

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
      (void)src;
      return this;
    }
    IOperand const * operator-( IOperand const & src ) const {
      (void)src;
      return this;
    }
    IOperand const * operator*( IOperand const & src ) const {
      (void)src;
      return this;
    }
    IOperand const * operator/( IOperand const & src ) const {
      (void)src;
      return this;
    }
    IOperand const * operator%( IOperand const & src ) const {
      (void)src;
      return this;
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
    // Exception

    IOperand const * createOperand(eOperandType type, std::string const & value) const {
      return (this->*_create[type])(value);
    }

  private:

    Operand<T>(eOperandType type, std::string const & value) : _type(type), _precision(0) {
      if (stold(value, 0) > std::numeric_limits<T>::max())
        throw Operand::OverflowException();
      else if (stold(value, 0) < std::numeric_limits<T>::min())
        throw Operand::UnderflowException();
      this->_str = std::to_string(static_cast<T>(stod(value, 0)));
      this->_value = static_cast<T>(stod(value, 0));
    }

    IOperand const * createInt8( std::string const & value ) const {
      std::cout << "create new Operand Int8 " << value << std::endl;
      return new Operand<T>(Int8, value);
    }
    IOperand const * createInt16( std::string const & value ) const {
      std::cout << "create new Operand Int16 " << value << std::endl;
      return new Operand<T>(Int16, value);
    }
    IOperand const * createInt32( std::string const & value ) const{
      std::cout << "create new Operand Int32 " << value << std::endl;
      return new Operand<T>(Int32, value);
    }
    IOperand const * createFloat( std::string const & value ) const {
      std::cout << "create new Operand Float " << value << std::endl;
      return new Operand<T>(Float, value);
    }
    IOperand const * createDouble( std::string const & value ) const {
      std::cout << "create new Operand Double " << value << std::endl;
      return new Operand<T>(Double, value);
    }

    T             _value;
    eOperandType  _type;
    int           _precision;
    std::string   _str;

    typedef IOperand const * (Operand::*FABRIC[5]) (std::string const & value) const;
    static FABRIC _create;
};

template<typename T>
typename Operand<T>::FABRIC Operand<T>::_create = {
  &Operand::createInt8,
  &Operand::createInt16,
  &Operand::createInt32,
  &Operand::createFloat,
  &Operand::createDouble,
};
#endif
