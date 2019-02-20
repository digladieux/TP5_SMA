/**
 * \file Exception.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation de la classe Exception
 * \date 2018-12-03
 */
#include "../header/Exception.hpp"
#include "../header/Constantes.hpp"
#include <iostream>

/**
 * \fn Exception::Exception() 
 * \brief Constructeur par default de la classe Exception
 */
Exception::Exception() {}

/**
 * \fn Exception::~Exception() throw() 
 * \brief Desctructeur de la classe Exception
 */
Exception::~Exception() throw() {}

/**
 * \fn const char *Exception::what() const throw() 
 * \brief Surchage de la methode what pour l'affichage du message d'erreur
 */
const char *Exception::what() const throw()
{
    return "General Exception";
}

/**
 * \fn InvalidFile::InvalidFile(std::string file)
 * \brief Constructeur de la classe InvalidFile
 * \param file Nom du fichier qui est incorrecte
 */
InvalidFile::InvalidFile(std::string& file) : std::invalid_argument(""), message_error("YOUR_FILE_DOES_NOT_EXIST : " + file)
{
    std::cerr << what() << std::endl;
}

/**
 * \fn InvalidFile::~InvalidFile() throw() 
 * \brief Desctructeur de la classe InvalidFile
 */
InvalidFile::~InvalidFile() throw() {}

/**
 * \fn const char *InvalidFile::what() const throw() 
 * \brief Surchage de la methode what pour l'affichage du message d'erreur
 */
const char *InvalidFile::what() const throw()
{
    return message_error.c_str();
}

/**
 * \fn InvalidConfiguration::InvalidConfiguration(std::string config)
 * \brief Constructeur de la classe InvalidConfiguration
 * \param config Numero de la config qui n'existe pas
 */
InvalidConfiguration::InvalidConfiguration(unsigned int config) : std::invalid_argument(""), message_error("MAX_CONFIGURATION : " + std::to_string((unsigned int) Constantes::CONFIG_SIMU["maxConfig"]) + "\nYOUR_CHOICE : " + std::to_string(config))
{
    std::cerr << what() << std::endl;
}

/**
 * \fn InvalidConfiguration::~InvalidConfiguration() throw() 
 * \brief Desctructeur de la classe InvalidConfiguration
 */
InvalidConfiguration::~InvalidConfiguration() throw() {}

/**
 * \fn const char *InvalidConfiguration::what() const throw() 
 * \brief Surchage de la methode what pour l'affichage du message d'erreur
 */
const char *InvalidConfiguration::what() const throw()
{
    return message_error.c_str();
}

/**
 * \fn InvalidJob::InvalidJob(std::string job_error)
 * \brief Constructeur de la classe InvalidJob
 * \param job_error Numero de la specialite qui n'existe pas
 */
InvalidJob::InvalidJob(unsigned int job_error) : std::invalid_argument(""), message_error("JOB_MAX_EXPECTED : 4\nHERE : " + std::to_string(job_error))
{
    std::cerr << what() << std::endl;
}

/**
 * \fn InvalidJob::~InvalidJob() throw() 
 * \brief Desctructeur de la classe InvalidJob
 */
InvalidJob::~InvalidJob() throw() {}

/**
 * \fn const char *InvalidJob::what() const throw() 
 * \brief Surchage de la methode what pour l'affichage du message d'erreur
 */
const char *InvalidJob::what() const throw()
{
    return message_error.c_str();
}

/**
 * \fn OutOfRangeSuperior::OutOfRangeSuperior(const unsigned int range_maximum, const unsigned int range_out) 
 * \brief Constructeur de la classe OutOfRangeSuperior
 * \param range_maximum Borne Maximale 
 * \param range_out Indice hors des bornes
 */
OutOfRangeSuperior::OutOfRangeSuperior(const unsigned int range_maximum, const unsigned int range_out) : std::out_of_range("")
{
    setValueOutOfRange(range_out, range_maximum);
    std::cerr << what() << std::endl;
}

/**
 * \fn OutOfRangeSuperior::~OutOfRangeSuperior() throw() 
 * \brief Desctructeur de la classe OutOfRangeSuperior
 */
OutOfRangeSuperior::~OutOfRangeSuperior() throw() {}

/**
 * \fn const char *OutOfRangeSuperior::what() const throw() 
 * \brief Surchage de la methode what pour l'affichage du message d'erreur
 */
const char *OutOfRangeSuperior::what() const throw()
{
    return message_error.c_str();
}

/**
 * \fn void OutOfRangeSuperior::setValueOutOfRange(const unsigned int range_out, const unsigned int range_maximum)
 * \brief Methode pour affecter au message d'erreur des valeurs
 */
void OutOfRangeSuperior::setValueOutOfRange(const unsigned int range_out, const unsigned int range_maximum)
{
    message_error = "MAX_RANGE_EXPECTED : " + std::to_string(range_out) + "\nYOUR_RANGE : " + std::to_string(range_maximum);
}

/**
 * \fn InvalidGender::InvalidGender(std::string gender_error)
 * \brief Constructeur de la classe InvalidGender
 * \param gender_error Numero du sexe qui n'existe pas
 */
InvalidGender::InvalidGender(const unsigned int gender_error) : std::invalid_argument(""), message_error("GENDER_EXPECTED_0_1, HERE : " + std::to_string(gender_error))
{
    std::cerr << what() << std::endl;
}

/**
 * \fn InvalidGender::~InvalidGender() throw() 
 * \brief Desctructeur de la classe InvalidGender
 */
InvalidGender::~InvalidGender() throw() {}

/**
 * \fn const char *InvalidGender::what() const throw() 
 * \brief Surchage de la methode what pour l'affichage du message d'erreur
 */
const char *InvalidGender::what() const throw()
{
    return message_error.c_str();
}

/**
 * \fn CurrentDateBeforeBirthException::CurrentDateBeforeBirthException(const Date &current_date, const Date &date_of_birth)
 * \brief Constructeur de la classe CurrentDateBeforeBirthException
 * \param &current_date Date Actuelle
 * \param &date_of_birth Date de naissance se situant apres la date actuelle
 */
CurrentDateBeforeBirthException::CurrentDateBeforeBirthException(const Date &current_date, const Date &date_of_birth) : std::invalid_argument(""), message_error("CURRENT_DATE : " + current_date.to_string() + "DATE_OF_BIRTH : " + date_of_birth.to_string())
{
    std::cerr << what() << std::endl;
}

/**
 * \fn CurrentDateBeforeBirthException::~CurrentDateBeforeBirthException() throw() 
 * \brief Desctructeur de la classe CurrentDateBeforeBirthException
 */
CurrentDateBeforeBirthException::~CurrentDateBeforeBirthException() throw() {}

/**
 * \fn const char *CurrentDateBeforeBirthException::what() const throw() 
 * \brief Surchage de la methode what pour l'affichage du message d'erreur
 */
const char *CurrentDateBeforeBirthException::what() const throw()
{
    return message_error.c_str();
}

/**
 * \fn ConstructorDateException::ConstructorDateException(const unsigned int day, const unsigned int month, const unsigned int year)
 * \brief Constructeur de la classe ConstructorDateException. On affiche pas le message d'erreur car cette erreur est genere lors d'u
 * \param day Jour Actuelle
 * \param month Mois Actuelle
 * \param year Annee Actuelle
 */
ConstructorDateException::ConstructorDateException(const unsigned int day, const unsigned int month, const unsigned int year) : std::invalid_argument(""), message_error("DATE_INVALID : " + std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year)){}

/**
 * \fn CurrentDateBeforeBirthException::~CurrentDateBeforeBirthException() throw() 
 * \brief Desctructeur de la classe CurrentDateBeforeBirthException
 */
ConstructorDateException::~ConstructorDateException() throw() {}

/**
 * \fn const char *CurrentDateBeforeBirthException::what() const throw() 
 * \brief Surchage de la methode what pour l'affichage du message d'erreur
 */
const char *ConstructorDateException::what() const throw()
{
    return message_error.c_str();
}

/**
 * \fn InvalidGroundType::InvalidGroundType(std::string ground_type_error)
 * \brief Constructeur de la classe InvalidGroundType
 * \param ground_type_error Numero du type de terrain qui n'existe pas
 */
InvalidGroundType::InvalidGroundType(unsigned int ground_type_error) : std::invalid_argument(""), message_error("GROUND_TYPE_MAX_EXPECTED : 4\nHERE : " + std::to_string(ground_type_error))
{
    std::cerr << what() << std::endl;
}

/**
 * \fn InvalidGroundType::~InvalidGroundType() throw() 
 * \brief Desctructeur de la classe InvalidGroundType
 */
InvalidGroundType::~InvalidGroundType() throw() {}

/**
 * \fn const char *InvalidGroundType::what() const throw() 
 * \brief Surchage de la methode what pour l'affichage du message d'erreur
 */
const char *InvalidGroundType::what() const throw()
{
    return message_error.c_str();
}

/**
 * \fn InvalidGroundTypeReadingFile::InvalidGroundTypeReadingFile(std::string ground_type_error)
 * \brief Constructeur de la classe InvalidGroundTypeReadingFile
 * \param ground_type_error Numero du type de terrain qui n'existe pas
 */
InvalidGroundTypeReadingFile::InvalidGroundTypeReadingFile(char ground_type_error) : std::invalid_argument(""), message_error("GROUND_TYPE_MUST_BE : ., T, F, f, L, Q\nHERE : " + std::to_string(ground_type_error))
{
    std::cerr << what() << std::endl;
}

/**
 * \fn InvalidGroundTypeReadingFile::~InvalidGroundTypeReadingFile() throw() 
 * \brief Desctructeur de la classe InvalidGroundTypeReadingFile
 */
InvalidGroundTypeReadingFile::~InvalidGroundTypeReadingFile() throw() {}

/**
 * \fn const char *InvalidGroundTypeReadingFile::what() const throw() 
 * \brief Surchage de la methode what pour l'affichage du message d'erreur
 */
const char *InvalidGroundTypeReadingFile::what() const throw()
{
    return message_error.c_str();
}
/**
 * \fn InvalidDirection::InvalidDirection(const unsigned int x, const unsigned int y, const unsigned int row_number, const unsigned int column_number)
 * \brief Constructeur de la classe InvalidDirection
 * \param x Point de Coordonne x ou le personnage doit aller
 * \param y Point de Coordonne y ou le personnage doit aller
 * \param row_number Le x Maximum que le personnage peut aller
 * \param column_number Le y Maximum que le personnage peut aller
 */
InvalidDirection::InvalidDirection(const unsigned int x, const unsigned int y, const unsigned int row_number, const unsigned int column_number) : std::invalid_argument("")
{
    setValueDirectionException(x, y, row_number, column_number);
}

/**
 * \fn InvalidDirection::~InvalidDirection() throw() 
 * \brief Desctructeur de la classe InvalidDirection
 */
InvalidDirection::~InvalidDirection() throw() {}

/**
 * \fn const char *InvalidDirection::what() const throw() 
 * \brief Surchage de la methode what pour l'affichage du message d'erreur
 */
const char *InvalidDirection::what() const throw()
{
    return message_error.c_str();
}

/**
 * \fn void InvalidDirection::setValueDirectionException(const unsigned int x, const unsigned int y, const unsigned int row_number, const unsigned int column_number)
 * \brief Setteur sur les valeurs de direction
 * \param x Point de Coordonne x ou le personnage doit aller
 * \param y Point de Coordonne y ou le personnage doit aller
 * \param row_number Le x Maximum que le personnage peut aller
 * \param column_number Le y Maximum que le personnage peut aller
 */
void InvalidDirection::setValueDirectionException(const unsigned int x, const unsigned int y, const unsigned int row_number, const unsigned int column_number)
{
    message_error = "MAP : [" + std::to_string(row_number) + "][" + std::to_string(column_number) + "]\nHERE_DIRECTION : [" + std::to_string(x) + "][" + std::to_string(y) + "]\n";
}

/**
 * \fn InvalidNumberOfCharacter::InvalidNumberOfCharacter(const unsigned int index_out, const unsigned int index_max) 
 * \brief Constructeur de la classe InvalidNumberOfCharacter
 * \param index_out Indice hors des bornes 
 * \param index_max Indice Maximale
 */
InvalidNumberOfCharacter::InvalidNumberOfCharacter(const unsigned int index_out, const unsigned int index_max) : std::invalid_argument(""), message_error("MAXIMUM_EXPECTED : " + std::to_string(index_max) + "\nHERE : " + std::to_string(index_out)) 
{
        std::cerr << what() << std::endl;
}

/**
 * \fn InvalidNumberOfCharacter::~InvalidNumberOfCharacter() throw() 
 * \brief Desctructeur de la classe InvalidNumberOfCharacter
 */
InvalidNumberOfCharacter::~InvalidNumberOfCharacter() throw() {}

/**
 * \fn const char *InvalidNumberOfCharacter::what() const throw() 
 * \brief Surchage de la methode what pour l'affichage du message d'erreur
 */
const char *InvalidNumberOfCharacter::what() const throw()
{
    return message_error.c_str();
}

/**
 * \fn InvalidNumberOfMap::InvalidNumberOfMap(const unsigned int index_out, const unsigned int index_max) 
 * \brief Constructeur de la classe InvalidNumberOfMap
 * \param index_out Indice hors des bornes 
 * \param index_max Indice Maximale
 */
InvalidNumberOfMap::InvalidNumberOfMap(const unsigned int index_out, const unsigned int index_max) : std::invalid_argument(""), message_error("MAXIMUM_EXPECTED : " + std::to_string(index_max) + "\nHERE : " + std::to_string(index_out)) 
{
        std::cerr << what() << std::endl;
}

/**
 * \fn InvalidNumberOfMap::~InvalidNumberOfMap() throw() 
 * \brief Desctructeur de la classe InvalidNumberOfMap
 */
InvalidNumberOfMap::~InvalidNumberOfMap() throw() {}

/**
 * \fn const char *InvalidNumberOfMap::what() const throw() 
 * \brief Surchage de la methode what pour l'affichage du message d'erreur
 */
const char *InvalidNumberOfMap::what() const throw()
{
    return message_error.c_str();
}

/**
 * \fn InvalidKey::InvalidKey(const unsigned int index_out, const unsigned int index_max) 
 * \brief Constructeur de la classe InvalidKey
 * \param index_out Indice hors des bornes 
 * \param index_max Indice Maximale
 */
InvalidKey::InvalidKey(const unsigned int index_out, const unsigned int index_max) : std::invalid_argument(""), message_error("INVALID_KEY_MAXIMUM_EXPECTED : " + std::to_string(index_max) + "\nHERE : " + std::to_string(index_out)) 
{
        std::cerr << what() << std::endl;

}

/**
 * \fn InvalidKey::~InvalidKey() throw() 
 * \brief Desctructeur de la classe InvalidKey
 */
InvalidKey::~InvalidKey() throw() {}

/**
 * \fn const char *InvalidKey::what() const throw() 
 * \brief Surchage de la methode what pour l'affichage du message d'erreur
 */
const char *InvalidKey::what() const throw()
{
    return message_error.c_str();
}

/**
 * \fn InvalidTeam::InvalidTeam(const unsigned int index_out, const unsigned int index_max) 
 * \brief Constructeur de la classe InvalidTeam
 * \param index_out Indice hors des bornes 
 */
InvalidTeam::InvalidTeam(const unsigned int index_out) : std::invalid_argument(""), message_error("MAXIMUM_TEAM_EXPECTED : 1\nHERE : " + std::to_string(index_out)) 
{
        std::cerr << what() << std::endl;

}

/**
 * \fn InvalidTeam::~InvalidTeam() throw() 
 * \brief Desctructeur de la classe InvalidTeam
 */
InvalidTeam::~InvalidTeam() throw() {}

/**
 * \fn const char *InvalidTeam::what() const throw() 
 * \brief Surchage de la methode what pour l'affichage du message d'erreur
 */
const char *InvalidTeam::what() const throw()
{
    return message_error.c_str();
}

/**
 * \fn InvalidDisplayChoice::InvalidDisplayChoice(const unsigned int index_out) 
 * \brief Constructeur de la classe InvalidDisplayChoice
 * \param index_out Indice hors des bornes 
 */
InvalidDisplayChoice::InvalidDisplayChoice(const unsigned int index_out) : std::invalid_argument(""), message_error("MAXIMUM_DISPLAY_CHOICE_EXPECTED : 2\nHERE : " + std::to_string(index_out)) 
{
        std::cerr << what() << std::endl;

}

/**
 * \fn InvalidDisplayChoice::~InvalidDisplayChoice() throw() 
 * \brief Desctructeur de la classe InvalidDisplayChoice
 */
InvalidDisplayChoice::~InvalidDisplayChoice() throw() {}

/**
 * \fn const char *InvalidDisplayChoice::what() const throw() 
 * \brief Surchage de la methode what pour l'affichage du message d'erreur
 */
const char *InvalidDisplayChoice::what() const throw()
{
    return message_error.c_str();
}

/**
 * \fn NoRessourceAvailable::NoRessourceAvailable() 
 * \brief Constructeur de la classe NoRessourceAvailable
 */
NoRessourceAvailable::NoRessourceAvailable() : std::invalid_argument("")
{
        std::cerr << what() << std::endl;

}

/**
 * \fn NoRessourceAvailable::~NoRessourceAvailable() throw() 
 * \brief Desctructeur de la classe NoRessourceAvailable
 */
NoRessourceAvailable::~NoRessourceAvailable() throw() {}

/**
 * \fn const char *NoRessourceAvailable::what() const throw() 
 * \brief Surchage de la methode what pour l'affichage du message d'erreur
 */
const char *NoRessourceAvailable::what() const throw()
{
    return "NO_RESSOURCE_AVAILABLE" ;
}

/**
 * \fn InvalidStrategy::InvalidStrategy(const unsigned int index_out) 
 * \brief Constructeur de la classe InvalidStrategy
 * \param index_out Indice hors des bornes 
 */
InvalidStrategy::InvalidStrategy(const unsigned int index_out) : std::invalid_argument(""), message_error("MAXIMUM_STRATEGY_INDEX_EXCEPTED : 2\nHERE : " + std::to_string(index_out)) 
{
        std::cerr << what() << std::endl;

}

/**
 * \fn InvalidStrategy::~InvalidStrategy() throw() 
 * \brief Desctructeur de la classe InvalidStrategy
 */
InvalidStrategy::~InvalidStrategy() throw() {}

/**
 * \fn const char *InvalidStrategy::what() const throw() 
 * \brief Surchage de la methode what pour l'affichage du message d'erreur
 */
const char *InvalidStrategy::what() const throw()
{
    return message_error.c_str();
}

/**
 * \fn InvalidColumnNumber::InvalidColumnNumber(const unsigned int index_out) 
 * \brief Constructeur de la classe InvalidColumnNumber
 * \param index_out Indice hors des bornes 
 */
InvalidColumnNumber::InvalidColumnNumber(const unsigned int index_out) : std::invalid_argument(""), message_error("OUT_OF_RANGE_COLUMN_NUMBER\nHERE : " + std::to_string(index_out)) 
{
        std::cerr << what() << std::endl;

}

/**
 * \fn InvalidColumnNumber::~InvalidColumnNumber() throw() 
 * \brief Desctructeur de la classe InvalidColumnNumber
 */
InvalidColumnNumber::~InvalidColumnNumber() throw() {}

/**
 * \fn const char *InvalidColumnNumber::what() const throw() 
 * \brief Surchage de la methode what pour l'affichage du message d'erreur
 */
const char *InvalidColumnNumber::what() const throw()
{
    return message_error.c_str();
}
