#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include <iostream>
class Exception : std::exception
{
  public:
    Exception();
    virtual ~Exception() throw();
    virtual const char *what() const throw();
};

class InvalidFile : std::invalid_argument
{
  private:
    std::string message_error;

  public:
    InvalidFile(std::string);
    virtual ~InvalidFile() throw();
    virtual const char *what() const throw();
};

class InvalidConfiguration : std::invalid_argument
{
  private:
    std::string message_error;

  public:
    InvalidConfiguration(unsigned int);
    virtual ~InvalidConfiguration() throw();
    virtual const char *what() const throw();
};

class OutOfRangeSuperior : std::out_of_range
{
  private:
    std::string message_error;

  public:
    OutOfRangeSuperior(const unsigned int, const unsigned int);
    virtual ~OutOfRangeSuperior() throw();
    virtual const char *what() const throw();
};

class BadAllocation : std::bad_alloc
{

  public:
    BadAllocation();
    virtual ~BadAllocation() throw();
    virtual const char *what() const throw();
};

class InvalidGender : std::invalid_argument
{
  private:
    std::string message_error;

  public:
    InvalidGender(const unsigned int);
    virtual ~InvalidGender() throw();
    virtual const char *what() const throw();
};
#endif
