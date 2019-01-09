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

class InvalidFile : Exception
{
  private:
    std::string file_name_error;

  public:
    InvalidFile(std::string);
    virtual ~InvalidFile() throw();
    virtual const char *what() const throw();
};

class InvalidConfiguration : Exception
{
  private:
    unsigned int config_error;

  public:
    InvalidConfiguration(unsigned int);
    virtual ~InvalidConfiguration() throw();
    virtual const char *what() const throw();
};

class OutOfRangeSuperior : Exception
{
  private:
    unsigned int range_error;
    unsigned int range_max;

  public:
    OutOfRangeSuperior(unsigned int, unsigned int);
    virtual ~OutOfRangeSuperior() throw();
    virtual const char *what() const throw();
};

#endif
