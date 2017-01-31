/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <aleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 10:23:35 by aleblanc          #+#    #+#             */
/*   Updated: 2017/01/31 14:05:16 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_CLASS_HPP
#define ERROR_CLASS_HPP

#include "abstract.hpp"

class Error : std::exception {
  public:
    virtual const char * what() const throw() = 0;
};

class OverflowException : public Error {
  public:
    OverflowException(void);
    OverflowException(OverflowException const & src);
    ~OverflowException(void) throw();
    OverflowException & operator=(OverflowException const &);
    virtual const char * what() const throw();
};

class UnderflowException : public Error {
  public:
    UnderflowException(void);
    UnderflowException(UnderflowException const & src);
    ~UnderflowException(void) throw();
    UnderflowException & operator=(UnderflowException const &);
    virtual const char * what() const throw();
};

class byZeroException : public Error {
  public:
    byZeroException(void);
    byZeroException(byZeroException const & src);
    ~byZeroException(void) throw();
    byZeroException & operator=(byZeroException const &);
    virtual const char * what() const throw();
};

class unknowException : public Error {
  public:
    unknowException(void);
    unknowException(unknowException const & src);
    ~unknowException(void) throw();
    unknowException & operator=(unknowException const &);
    virtual const char * what() const throw();
};

class lexicalException : public Error {
  public:
    lexicalException(void);
    lexicalException(lexicalException const & src);
    ~lexicalException(void) throw();
    lexicalException & operator=(lexicalException const &);
    virtual const char * what() const throw();
};

class assertException : public Error {
  public:
    assertException(void);
    assertException(assertException const & src);
    ~assertException(void) throw();
    assertException & operator=(assertException const &);
    virtual const char * what() const throw();
};

class emptyException : public Error {
  public:
    emptyException(void);
    emptyException(emptyException const & src);
    ~emptyException(void) throw();
    emptyException & operator=(emptyException const &);
    virtual const char * what() const throw();
};

class toSmallException : public Error {
  public:
    toSmallException(void);
    toSmallException(toSmallException const & src);
    ~toSmallException(void) throw();
    toSmallException & operator=(toSmallException const &);
    virtual const char * what() const throw();
};

class noPrintableException : public Error {
  public:
    noPrintableException(void);
    noPrintableException(noPrintableException const & src);
    ~noPrintableException(void) throw();
    noPrintableException & operator=(noPrintableException const &);
    virtual const char * what() const throw();
};


#endif
