/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <aleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 10:23:50 by aleblanc          #+#    #+#             */
/*   Updated: 2017/01/31 14:06:08 by aleblanc         ###   ########.fr       */
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

// assertException
assertException::assertException(void) { return; }
assertException::assertException(assertException const & src) { *this = src; return; }
assertException::~assertException(void) throw() { return; }
assertException &     assertException::operator=(assertException const &) { return *this; }
const char *          assertException::what() const throw() { return ("from 'assert' instruction: The values are not the same"); }

// emptyException
emptyException::emptyException(void) { return; }
emptyException::emptyException(emptyException const & src) { *this = src; return; }
emptyException::~emptyException(void) throw() { return; }
emptyException &      emptyException::operator=(emptyException const &) { return *this; }
const char *          emptyException::what() const throw() { return ("from 'pop' instruction: Empty stack"); }

// toSmallException
toSmallException::toSmallException(void) { return; }
toSmallException::toSmallException(toSmallException const & src) { *this = src; return; }
toSmallException::~toSmallException(void) throw() { return; }
toSmallException &    toSmallException::operator=(toSmallException const &) { return *this; }
const char *          toSmallException::what() const throw() { return ("Not enought object in the stack"); }

// noPrintableException
noPrintableException::noPrintableException(void) { return; }
noPrintableException::noPrintableException(noPrintableException const & src) { *this = src; return; }
noPrintableException::~noPrintableException(void) throw() { return; }
noPrintableException & noPrintableException::operator=(noPrintableException const &) { return *this; }
const char *          noPrintableException::what() const throw() { return ("Object in top of the stack is not a Int8 type"); }


