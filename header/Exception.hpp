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
 * \class Exception
 * \brief Exception par default 
 */
class Exception : std::exception
{
  public:
    Exception();
    virtual ~Exception() throw();
    virtual const char *what() const throw();
};


/**
 * \class InvalidFile
 * \brief Exception se declanchant lorsque le fichier a ouvrir n'existe pas
 */
class InvalidFile : std::invalid_argument
{
  private:
    std::string message_error;

  public:
    explicit InvalidFile(std::string&);
    virtual ~InvalidFile() throw();
    virtual const char *what() const throw();
};

/**
 * \class InvalidConfiguration
 * \brief Exception se declanchant lorsque la configuration n'existe pas 
 */
class InvalidConfiguration : std::invalid_argument
{
  private:
    std::string message_error;

  public:
    explicit InvalidConfiguration(unsigned int);
    virtual ~InvalidConfiguration() throw();
    virtual const char *what() const throw();
};

/**
 * \class InvalidJob
 * \brief Exception se declanchant lorsque la specialite du personnage n'existe pas
 */
class InvalidJob : std::invalid_argument
{
  private:
    std::string message_error;

  public:
    explicit InvalidJob(unsigned int);
    virtual ~InvalidJob() throw();
    virtual const char *what() const throw();
};

/**
 * \class OutOfRangeSuperior
 * \brief Exception se declanchant lorsque l'index d'un element du tableau n'est pas contenu dans ce dernier
 */
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

/**
 * \class InvalidGender
 * \brief Exception se declanchant lorsque le sexe d'un personnage est different de masculin ou feminin
 */
class InvalidGender : std::invalid_argument
{
  private:
    std::string message_error;

  public:
    explicit InvalidGender(const unsigned int);
    virtual ~InvalidGender() throw();
    virtual const char *what() const throw();
};

/**
 * \class CurrentDateBeforeBirthException
 * \brief Exception se declanchant lorsque la date de naissance d'un personnage est apres la date actuelle de la simulation
 */
class CurrentDateBeforeBirthException : std::invalid_argument
{
  private:
    std::string message_error;

  public:
    CurrentDateBeforeBirthException(const Date &, const Date &);
    virtual ~CurrentDateBeforeBirthException() throw();
    virtual const char *what() const throw();
};

/**
 * \class ConstructorDateException
 * \brief Exception se declanchant lorsque la construction du date est impossible car non valide
 */
class ConstructorDateException : std::invalid_argument
{
  private:
    std::string message_error;

  public:
    ConstructorDateException(const unsigned int,const unsigned int,const unsigned int);
    virtual ~ConstructorDateException() throw();
    virtual const char *what() const throw();
};

/**
 * \class InvalidGroundType
 * \brief Exception se declanchant lorsque le type de terrain est invalide
 */
class InvalidGroundType : std::invalid_argument
{
  private:
    std::string message_error;

  public:
    explicit InvalidGroundType(const unsigned int);
    virtual ~InvalidGroundType() throw();
    virtual const char *what() const throw();
};

/**
 * \class InvalidGroundTypeReadingFile
 * \brief Exception se declanchant lorsque le type de terrain est invalide lors de la lecture dans le json
 */
class InvalidGroundTypeReadingFile : std::invalid_argument
{
  private:
    std::string message_error;

  public:
    explicit InvalidGroundTypeReadingFile(const char);
    virtual ~InvalidGroundTypeReadingFile() throw();
    virtual const char *what() const throw();
};

/**
 * \class InvalidDirection
 * \brief Exception se declanchant lorsque la direction d'un personnage est hors de la carte
 */
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

/**
 * \class InvalidNumberOfCharacter
 * \brief Exception se declanchant lorsque l'utilisateur rentre un personnage qui n'existe pas 
 */
class InvalidNumberOfCharacter : std::invalid_argument
{
  private:
    std::string message_error;

  public:
    InvalidNumberOfCharacter(const unsigned int, const unsigned int);
    virtual ~InvalidNumberOfCharacter() throw();
    virtual const char *what() const throw();
};

/**
 * \class InvalidNumberOfMap
 * \brief Exception se declanchant lorsque l'utilisateur rentre un point de collecte qui n'existe pas
 */
class InvalidNumberOfMap : std::invalid_argument
{
  private:
    std::string message_error;

  public:
    InvalidNumberOfMap(const unsigned int, const unsigned int);
    virtual ~InvalidNumberOfMap() throw();
    virtual const char *what() const throw();
};

/**
 * \class InvalidKey
 * \brief Exception se declanchant lorsque un personnage ou un point de collecte ne se trouve pas dans un json
 */
class InvalidKey : std::invalid_argument
{
  private:
    std::string message_error;

  public:
    InvalidKey(const unsigned int, const unsigned int);
    virtual ~InvalidKey() throw();
    virtual const char *what() const throw();
};

/**
 * \class InvalidTeam
 * \brief Exception se declanchant lorsque l'identifiant de l'equipe est invalide
 */
class InvalidTeam : std::invalid_argument
{
  private:
    std::string message_error;

  public:
    explicit InvalidTeam(const unsigned int);
    virtual ~InvalidTeam() throw();
    virtual const char *what() const throw();
};

/**
 * \class InvalidDisplayChoice
 * \brief Exception se declanchant lorsque le choix d'affichage n'est pas correcte
 */
class InvalidDisplayChoice : std::invalid_argument
{
  private:
    std::string message_error;

  public:
    explicit InvalidDisplayChoice(const unsigned int);
    virtual ~InvalidDisplayChoice() throw();
    virtual const char *what() const throw();
};

/**
 * \class NoRessourceAvailable
 * \brief Exception se declanchant lorsque le nombre de ressource sur les points de collecte est insuffisant
 */
class NoRessourceAvailable : std::invalid_argument
{
  public:
    NoRessourceAvailable();
    virtual ~NoRessourceAvailable() throw();
    virtual const char *what() const throw();
};

/**
 * \class InvalidStrategy
 * \brief Exception se declanchant lorsque l'identifiant de la strategie est invalide
 */
class InvalidStrategy : std::invalid_argument
{
  private:
    std::string message_error;

  public:
    explicit InvalidStrategy(const unsigned int);
    virtual ~InvalidStrategy() throw();
    virtual const char *what() const throw();
};

/**
 * \class InvalidColumnNumber
 * \brief Exception se declanchant lorsque le nombre de colonne est inferieur a 0
 */
class InvalidColumnNumber : std::invalid_argument
{
  private:
    std::string message_error;

  public:
    explicit InvalidColumnNumber(const unsigned int);
    virtual ~InvalidColumnNumber() throw();
    virtual const char *what() const throw();
};
#endif
