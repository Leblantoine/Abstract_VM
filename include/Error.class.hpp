/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <aleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 10:23:35 by aleblanc          #+#    #+#             */
/*   Updated: 2017/02/07 12:56:28 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_CLASS_HPP
#define ERROR_CLASS_HPP

#include "abstract.hpp"

class fileException : public std::exception {

  public:
    fileException(std::string const &str);
    fileException(fileException const & src);
    ~fileException(void) throw();
    fileException & operator=(fileException const &);
    virtual const char * what(void) const throw();

  private:
    fileException(void);
    std::string   _error;
};

class execException : public std::exception {

  public:
    execException(std::string const &str);
    execException(std::string const &str, int line);
    execException(execException const & src);
    ~execException(void) throw();
    execException & operator=(execException const &);
    virtual const char * what(void) const throw();

  private:
    execException(void);
    std::string   _error;
};

#endif
