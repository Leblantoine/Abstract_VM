/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <aleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 10:23:50 by aleblanc          #+#    #+#             */
/*   Updated: 2017/02/07 12:56:53 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Error.class.hpp"

// filecException
fileException::fileException(std::string const &str) : _error(str) {
  return;
}

fileException::fileException(void) { return; }
fileException::fileException(fileException const & src) { *this = src; return; }
fileException::~fileException(void) throw() { return; }
fileException &  fileException::operator=(fileException const &) { return *this; }

const char *     fileException::what() const throw() {
  return this->_error.c_str();
}

// execException
execException::execException(std::string const &str) : _error(str) {
  return;
}

execException::execException(std::string const &str, int line) {
  this->_error = "\nLine " + std::to_string(line) + ", ERROR: " + str;
  return;
}

execException::execException(void) { return; }
execException::execException(execException const & src) { *this = src; return; }
execException::~execException(void) throw() { return; }
execException &  execException::operator=(execException const &) { return *this; }

const char *     execException::what() const throw() {
  return this->_error.c_str();
}
