#include "../header/Menu.hpp"
#include "../header/Constantes.hpp"
#include "../header/Exception.hpp"
#include <fstream>
#include <sstream>
Menu::Menu()
{
    Constantes::getAllJson() ;
}


void Menu::displayWelcome(std::ostream &os) noexcept
{
    os << "Welcome to our game : CiviliZZation" << std::endl;
}
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
                throw e;
            }
        }
    }

    return map_vector;
}

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
        displayGroundType(os,Constantes::MAPS[collection_point]["type"]);
        os << "\t" << "[" << Constantes::MAPS[collection_point]["x"] << "," << Constantes::MAPS[collection_point]["y"] << "]\t RESSOURCES_NUMBER : " << Constantes::MAPS[collection_point]["ressource_number"] << std::endl;
    }
    os << "Where do you want to play ?" << std::endl;
}

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
                throw e;
            }
        }
    }

    return character_vector;
}

void Menu::displayAllCharacter(std::ostream &os) const
{
    std::string character;
    unsigned int character_number = Constantes::CHARACTERS["character_number"],
                 character_sex;
                 
    system("clear");
    os << "Here you are all of our character :" << std::endl;
    for (unsigned int i = 1; i <= character_number; i++)
    {
        os << i << " : ";
        character = "character" + std::to_string(i);
        character_sex = Constantes::CHARACTERS[character]["sex"];
        displaySex(os, character_sex);
        os << "\t" << Date(Constantes::CHARACTERS[character]["day"], Constantes::CHARACTERS[character]["month"], Constantes::CHARACTERS[character]["year"]).getAge(Date(1, 1, 60)) << " YEARS_OLD\tLIFE "  << Constantes::CHARACTERS[character]["life"] << "\tTEAM " << Constantes::CHARACTERS[character]["team"] << "\t";
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

unsigned int Menu::configChoice() const noexcept
{
    unsigned int config;
    do
    {
        std::cin >> config;
    } while (config >2);
    return config;
}
void Menu::displayAllConfig(std::ostream &os) const
{
    system("clear");
    os << "Here you are all the config" << std::endl;
    for (unsigned int i = 1; i <= Constantes::CONFIG_SIMU["maxConfig"] ; i++) 
    {
        os << std::endl
           << "Config " << i << " : " << std::endl;
        Constantes::displayConfiguration(i, os);
    }
    os << "Which config do you want to use" << std::endl;
}

void Menu::displayTurnChoice(std::ostream &os) const noexcept
{
    os << "How many turns do you want to show ? " << std::endl;
}
unsigned int Menu::turnChoice() const noexcept
{
    int turn;
    do
    {
        std::cin >> turn;
    } while (turn <= 0);
    return turn;
}
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