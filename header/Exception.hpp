/**
 * \file Exception.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete contenant la liste des differentes Exception
 * \date 2018-12-03
 */


#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include "Date.hpp"
#include <exception>
#include <iostream>

/**
 * \class Date
 * \brief Exception par default
 */
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
    explicit InvalidFile(std::string&);
    virtual ~InvalidFile() throw();
    virtual const char *what() const throw();
};

class InvalidConfiguration : std::invalid_argument
{
  private:
    std::string message_error;

  public:
    explicit InvalidConfiguration(unsigned int);
    virtual ~InvalidConfiguration() throw();
    virtual const char *what() const throw();
};

class InvalidJob : std::invalid_argument
{
  private:
    std::string message_error;

  public:
    explicit InvalidJob(unsigned int);
    virtual ~InvalidJob() throw();
    virtual const char *what() const throw();
};

class OutOfRangeSuperior : std::out_of_range
{
  private:
    std::string message_error;

  public:
    OutOfRangeSuperior(const unsigned int, const unsigned int);
    void setValueOutOfRange(const unsigned int, const unsigned int);
    virtual ~OutOfRangeSuperior() throw();
    virtual const char *what() const throw();
};


class InvalidGender : std::invalid_argument
{
  private:
    std::string message_error;

  public:
    explicit InvalidGender(const unsigned int);
    virtual ~InvalidGender() throw();
    virtual const char *what() const throw();
};

class CurrentDateBeforeBirthException : std::invalid_argument
{
  private:
    std::string message_error;

  public:
    CurrentDateBeforeBirthException(const Date &, const Date &);
    virtual ~CurrentDateBeforeBirthException() throw();
    virtual const char *what() const throw();
};

class ConstructorDateException : std::invalid_argument
{
  private:
    std::string message_error;

  public:
    ConstructorDateException(const unsigned int,const unsigned int,const unsigned int);
    virtual ~ConstructorDateException() throw();
    virtual const char *what() const throw();
};

class InvalidGroundType : std::invalid_argument
{
  private:
    std::string message_error;

  public:
    explicit InvalidGroundType(const unsigned int);
    virtual ~InvalidGroundType() throw();
    virtual const char *what() const throw();
};

class InvalidGroundTypeReadingFile : std::invalid_argument
{
  private:
    std::string message_error;

  public:
    explicit InvalidGroundTypeReadingFile(const char);
    virtual ~InvalidGroundTypeReadingFile() throw();
    virtual const char *what() const throw();
};

class InvalidDirection : std::invalid_argument
{
  private:
    std::string message_error;

  public:
    InvalidDirection(const unsigned int, const unsigned int, const unsigned int, const unsigned int);
    void setValueDirectionException(const unsigned int, const unsigned int, const unsigned int, const unsigned int);
    virtual ~InvalidDirection() throw();
    virtual const char *what() const throw();
};

class InvalidNumberOfCharacter : std::invalid_argument
{
  private:
    std::string message_error;

  public:
    InvalidNumberOfCharacter(const unsigned int, const unsigned int);
    virtual ~InvalidNumberOfCharacter() throw();
    virtual const char *what() const throw();
};

class InvalidNumberOfMap : std::invalid_argument
{
  private:
    std::string message_error;

  public:
    InvalidNumberOfMap(const unsigned int, const unsigned int);
    virtual ~InvalidNumberOfMap() throw();
    virtual const char *what() const throw();
};

class InvalidKey : std::invalid_argument
{
  private:
    std::string message_error;

  public:
    InvalidKey(const unsigned int, const unsigned int);
    virtual ~InvalidKey() throw();
    virtual const char *what() const throw();
};

class InvalidTeam : std::invalid_argument
{
  private:
    std::string message_error;

  public:
    explicit InvalidTeam(const unsigned int);
    virtual ~InvalidTeam() throw();
    virtual const char *what() const throw();
};
class InvalidDisplayChoice : std::invalid_argument
{
  private:
    std::string message_error;

  public:
    explicit InvalidDisplayChoice(const unsigned int);
    virtual ~InvalidDisplayChoice() throw();
    virtual const char *what() const throw();
};


class NoRessourceAvailable : std::invalid_argument
{
  public:
    NoRessourceAvailable();
    virtual ~NoRessourceAvailable() throw();
    virtual const char *what() const throw();
};

class InvalidStrategy : std::invalid_argument
{
  private:
    std::string message_error;

  public:
    explicit InvalidStrategy(const unsigned int);
    virtual ~InvalidStrategy() throw();
    virtual const char *what() const throw();
};


#endif
