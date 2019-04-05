/**
 * \file Menu.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation de la classe Menu
 * \date 2018-12-03
 */

#include "../header/Menu.hpp"
#include "../header/Constantes.hpp"
#include "../header/Exception.hpp"
#include <fstream>
#include <sstream>

/**
 * \fn Menu::Menu()
 * \brief Constructeur par default de la classe Menu
 */
Menu::Menu()
{
    Constantes::getAllJson();
}

/**
 * \fn void Menu::displayWelcome(std::ostream &os) noexcept
 * \brief Methode d'affichage de l'ecran de bienvenue
 * \param &os Flux sur lequel on va afficher le message de bienvenue
 */

void Menu::displayWelcome(std::ostream &os) noexcept
{
    os << "Welcome to our game : CiviliZZation" << std::endl; 
}

/**
 * \fn std::vector<unsigned int> Menu::mapChoice() const
 * \brief Methode pour la selection des points de collecte par l'utilisateur
 * \return Vecteur d'entier contenant les differents point de collecte choisis par l'utilisateur
 */
std::vector<unsigned int> Menu::mapChoice() const
{
    unsigned int map;
    std::vector<unsigned int> map_vector;
    std::string line;
    std::getline(std::cin, line);
    std::istringstream is(line);
    while (is >> map)
    {
        if (map > Constantes::MAPS["collection_point_number"])
        {
            throw InvalidNumberOfMap(map, Constantes::MAPS["collection_point_number"]);
        }
        else
        {
            try
            {
                map_vector.push_back(map);
            }
            catch (const std::bad_alloc &e)
            {
                throw ;
            }
        }
    }

    return map_vector;
}

/**
 * \fn void Menu::displayAllMap(std::ostream &os) const
 * \brief Methode d'affichage de la liste des points de collecte
 * \param &os Flux sur lequel on va afficher la liste des points de collecte
 */
void Menu::displayAllMap(std::ostream &os) const
{

    std::string collection_point;
    unsigned int collection_point_number = Constantes::MAPS["collection_point_number"];
    system("clear");
    os << "Here you are all of our collection point:" << std::endl;

    for (unsigned i = 1; i <= collection_point_number; i++)
    {
        os << i << " : ";
        collection_point = "collection_point" + std::to_string(i);
        displayGroundType(os, Constantes::MAPS[collection_point]["type"]);
        os << "\t"
           << "[" << Constantes::MAPS[collection_point]["x"] << "," << Constantes::MAPS[collection_point]["y"] << "]\t RESSOURCES_NUMBER : " << Constantes::MAPS[collection_point]["ressource_number"] << std::endl;
    }
    os << "Where do you want to play ?" << std::endl;
}

/**
 * \fn std::vector<unsigned int> Menu::characterChoice() const
 * \brief Methode pour la selection des personnages par l'utilisateur
 * \return Vecteur d'entier contenant les differents personnages choisis par l'utilisateur
 */
std::vector<unsigned int> Menu::characterChoice() const
{
    unsigned int character;
    std::vector<unsigned int> character_vector;
    std::string line;
    std::getline(std::cin, line);
    std::istringstream is(line);
    while (is >> character)
    {
        if (character > Constantes::CHARACTERS["character_number"])
        {
            throw InvalidNumberOfCharacter(character, Constantes::CHARACTERS["character_number"]);
        }
        else
        {
            try
            {
                character_vector.push_back(character);
            }
            catch (const std::bad_alloc &e)
            {
                throw ;
            }
        }
    }

    return character_vector;
}

/**
 * \fn void Menu::displayAllCharacter(std::ostream &os) const
 * \brief Methode d'affichage de la liste des personnages
 * \param &os Flux sur lequel on va afficher la liste des points de collecte
 */
void Menu::displayAllCharacter(std::ostream &os) const
{
    std::string character;
    unsigned int character_number = Constantes::CHARACTERS["character_number"] ;
    system("clear");
    os << "Here you are all of our character :" << std::endl;
    for (unsigned int i = 1; i <= character_number; i++)
    {
        os << i << " : ";
        character = "character" + std::to_string(i);
        unsigned int character_sex = Constantes::CHARACTERS[character]["sex"];
        displaySex(os, character_sex);
        os << "\t" << Date(Constantes::CHARACTERS[character]["day"], Constantes::CHARACTERS[character]["month"], Constantes::CHARACTERS[character]["year"]).getAge(Date(1, 1, 60)) << " YEARS_OLD\tLIFE " << Constantes::CHARACTERS[character]["life"] << "\tTEAM " << Constantes::CHARACTERS[character]["team"] << "\t";
        if (Constantes::CHARACTERS[character]["sex"] == 0)
        {
            displayJob(os, Constantes::CHARACTERS[character]["job"]);
        }
        else
        {
            os << "\tBaby : " << Constantes::CHARACTERS[character]["baby"];
        }
        os << std::endl;
    }
    os << "Which Group of character you want to start with ?" << std::endl;
}


/**
 * \fn unsigned int Menu::configChoice() const noexcept
 * \brief Methode pour la selection de la configuration par l'utilisateur
 * \return Entier contenant la configuration de la simulation choisis par l'utilisateur
 */
unsigned int Menu::configChoice() const noexcept
{
    unsigned int config;
    do
    {
        std::cin >> config;
    } while (config > 2);
    return config;
}

/**
 * \fn void Menu::displayAllConfig(std::ostream &os) const
 * \brief Methode d'affichage de la liste des configurations de simulation
 * \param &os Flux sur lequel on va afficher la liste des configurations
 */
void Menu::displayAllConfig(std::ostream &os) const
{
    system("clear");
    os << "Here you are all the config" << std::endl;
    for (unsigned int i = 1; i <= Constantes::CONFIG_SIMU["maxConfig"]; i++)
    {
        os << std::endl
           << "Config " << i << " : " << std::endl;
        Constantes::displayConfiguration(i, os);
    }
    os << "Which config do you want to use" << std::endl;
}

/**
 * \fn void Menu::displayTurnChoice(std::ostream &os) noexcept
 * \brief Methode d'affichage du nombre de tour souhaite par l'utilisateur
 * \param &os Flux sur lequel on va afficher le message 
 */

void Menu::displayTurnChoice(std::ostream &os) const noexcept
{
    os << "How many turns do you want to show ? " << std::endl;
}

/**
 * \fn unsigned int Menu::turnChoice() const noexcept
 * \brief Methode pour la selection du nombre de tour par l'utilisateur
 * \return Entier contenant le nombre de tour choisis par l'utilisateur
 */
unsigned int Menu::turnChoice() const noexcept
{
    int turn;
    do
    {
        std::cin >> turn;
    } while (turn <= 0);
    return turn;
}

/**
 * \fn void Menu::displaySex(std::ostream &os, unsigned int sex)
 * \brief Methode d'affichage du sexe du personnage
 * \param &os Flux sur lequel on va afficher le message 
 * \param sex Sexe du personnage 
 */
void Menu::displaySex(std::ostream &os, unsigned int sex)
{
    switch (sex)
    {
    case 0:
        os << "MALE, ";
        break;

    case 1:
        os << "FEMALE, ";
        break;
    default:
        throw InvalidGender(sex);
    }
}

/**
 * \fn void Menu::displayGroundType(std::ostream &os, unsigned int ground_type)
 * \brief Methode d'affichage du type de terrain 
 * \param &os Flux sur lequel on va afficher le message 
 * \param ground_type Type de terrain
 */
void Menu::displayGroundType(std::ostream &os, unsigned int ground_type)
{
    switch (ground_type)
    {
    case 1:
        os << "QUARRY ";
        break;
    case 2:
        os << "FOREST ";
        break;
    case 3:
        os << "LAKE ";
        break;
    case 4:
        os << "FARM ";
        break;
    default:
        throw InvalidGroundType(ground_type);
        break;
    }
}

/**
 * \fn void Menu::displayJob(std::ostream &os, unsigned int job)
 * \brief Methode d'affichage de la specialite du personnage 
 * \param &os Flux sur lequel on va afficher le message 
 * \param job Specialite du personnage
 */
void Menu::displayJob(std::ostream &os, unsigned int job)
{
    os << "\tJOB : ";
    switch (job)
    {
    case 0:
        os << "NO JOB ";
        break;

    case 1:
        os << "QUARRY MAN ";
        break;

    case 2:
        os << "LUMBERJACK ";
        break;

    case 3:
        os << "FISHERMAN ";
        break;

    case 4:
        os << "FARMER ";
        break;
    default:
        throw InvalidJob(job);
    }
}
/**
 * \fn void Menu::displayAllDisplay(std::ostream &os)
 * \brief Methode d'affichage du deroulement de la simulation 
 * \param &os Flux sur lequel on va afficher le message 
 */
void Menu::displayAllDisplay(std::ostream &os) const noexcept
{
    os << "How do you want to display the simulation ?" << std::endl;
    os << "0 : Print all the movements" << std::endl;
    os << "1 : Print step by step by pressing ENTER" << std::endl;
    os << "2 : Never print " << std::endl;
}

/**
 * \fn unsigned int Menu::displayChoice() const noexcept
 * \brief Methode pour la selection de la methode d'affichage par l'utilisateur
 * \return Entier contenant le type d'affichage de la simulation choisis par l'utilisateur
 */
unsigned int Menu::displayChoice() const noexcept
{
    int choice;
    do
    {
        std::cin >> choice;
    } while ( (choice < 0) && (choice > 2) );
    return choice;
}

/**
 * \fn void Menu::displayAllStrategies(std::ostream &os)
 * \brief Methode d'affichage du deroulement de la simulation 
 * \param &os Flux sur lequel on va afficher le message 
 */
void Menu::displayAllStrategies(std::ostream &os) const noexcept
{
    os << "What will be the strategy of the characters" << std::endl;
    os << "0 : The character go to the closest collection point of his speciality" << std::endl;
    os << "1 : The character go to the closest collection point and the ressource will be the lowest of the townhall" << std::endl;
    os << "2 : The character go to the closest collection " << std::endl;
}

/**
 * \fn unsigned int Menu::strategyChoice() const noexcept
 * \brief Methode pour la selection de la methode d'affichage par l'utilisateur
 * \return Entier contenant le type d'affichage de la simulation choisis par l'utilisateur
 */
unsigned int Menu::strategyChoice() const noexcept
{
    int choice;
    do
    {
        std::cin >> choice;
    } while ( (choice < 0) && (choice > 2) );
    return choice;
}