/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <aleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 10:23:50 by aleblanc          #+#    #+#             */
/*   Updated: 2017/01/27 10:55:53 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Error.class.hpp"

// OverflowException
OverflowException::OverflowException(void) { return; }
OverflowException::OverflowException(OverflowException const & src) { *this = src; return; }
OverflowException::~OverflowException(void) throw() { return; }
OverflowException &   OverflowException::operator=(OverflowException const &) { return *this; }
const char *          OverflowException::what() const throw() { return ("Value overflow"); }

// UnderflowException
UnderflowException::UnderflowException(void) { return; }
UnderflowException::UnderflowException(UnderflowException const & src) { *this = src; return; }
UnderflowException::~UnderflowException(void) throw() { return; }
UnderflowException &  UnderflowException::operator=(UnderflowException const &) { return *this; }
const char *          UnderflowException::what() const throw() { return ("Value underflow"); }

// byZeroException
byZeroException::byZeroException(void) { return; }
byZeroException::byZeroException(byZeroException const & src) { *this = src; return; }
byZeroException::~byZeroException(void) throw() { return; }
byZeroException &     byZeroException::operator=(byZeroException const &) { return *this; }
const char *          byZeroException::what() const throw() { return ("Division / modulo by 0"); }

// unknowInstructionException
unknowException::unknowException(void) { return; }
unknowException::unknowException(unknowException const & src) { *this = src; return; }
unknowException::~unknowException(void) throw() { return; }
unknowException &     unknowException::operator=(unknowException const &) { return *this; }
const char *          unknowException::what() const throw() { return ("Unknow instruction"); }

// lexicalException
lexicalException::lexicalException(void) { return; }
lexicalException::lexicalException(lexicalException const & src) { *this = src; return; }
lexicalException::~lexicalException(void) throw() { return; }
lexicalException &    lexicalException::operator=(lexicalException const &) { return *this; }
const char *          lexicalException::what() const throw() { return ("Lexical"); }
