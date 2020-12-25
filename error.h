#ifndef ERROR_H_
#define ERROR_H_
#include <iostream>
#include <exception>
#include <string>
#include "config.h"

class BadRequest : public std::exception {
public:
    const char* what() const throw() { return BAD_REQUEST; }
};

class PermissionDenied : public std::exception {
public:
    const char* what() const throw() { return PERMISSION_DENIED; }
};

class NotFound : public std::exception {
public:
    const char* what() const throw() { return NOT_FOUND; }
};

#endif