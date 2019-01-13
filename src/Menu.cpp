#include "../header/Menu.hpp"
#include "../header/Constantes.hpp"
#include "../header/Exception.hpp"
#include <fstream>
#include <sstream>
Menu::Menu()
{
    openningCharacters();
    openningMaps();
}

void Menu::openningMaps()
{
    //std::string file_name_map = "MAP/Maps.json";
    //std::ifstream file_map(file_name_map);
    //if (!file_map.fail())
    //{
    //    file_map >> json_map;
    //    file_map.close();
    //}
    //else
    //{
    //    throw InvalidFile(file_name_map);
    //}
}

void Menu::openningCharacters()
{
    std::string file_name_character = "CHARACTERS/Charaters.json";
    std::ifstream file_character(file_name_character);

    if (!file_character.fail())
    {
        file_character >> json_characters;
        file_character.close();
    }
    else
    {
        throw InvalidFile(file_name_character);
    }
}
void Menu::displayWelcome(std::ostream &os) noexcept
{
    os << "Welcome to our game : CiviliZZation" << std::endl;
}
unsigned int Menu::mapChoice() const noexcept
{
    unsigned int map;
    do
    {
        std::cin >> map;
    } while ((map > Constantes::MAP_NUMBER) || (map < 1));
    return map;
}

void Menu::displayAllMap(std::ostream &os) const
{
    std::string file_name;
    os << "Here you are all the map : " << std::endl;

    for (unsigned int i = 1; i <= Constantes::MAP_NUMBER; i++)
    {
        file_name = "./MAPS/Map" + std::to_string(i) + ".txt";
        displayMapFile(os, file_name);
    }
    os << "Where do you want to play ?" << std::endl;
}

void Menu::displayMapFile(std::ostream &os, std::string file_name) const
{
    std::ifstream file(file_name);
    std::string line;
    int row_number, column_number;
    if (!file.fail())
    {
        file >> row_number >> column_number;
        os << "File's name : " << file_name << std::endl;
        os << "Number of row : " << row_number << std::endl;
        os << "Number of column : " << column_number << std::endl;
        os << "Number of square :" << row_number * column_number << std::endl;
        getline(file, line);
        while (row_number != 0)
        {
            getline(file, line);
            os << line << std::endl;
            row_number--;
        }
        os << std::endl;
    }
    else
    {
        throw InvalidFile(file_name);
    }
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
        if (character > json_characters["character_number"])
        {
            throw InvalidNumberOfCharacter(character, json_characters["character_number"]);
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
    unsigned int character_number = json_characters["character_number"];
    os << "Here you are all of our character :" << std::endl;
    for (unsigned int i = 1; i <= character_number; i++)
    {
        os << i << " : ";
        character = "character" + std::to_string(i);
        displaySex(os, json_characters[character]["sex"]);
        os << "\t" << Date(json_characters[character]["day"], json_characters[character]["month"], json_characters[character]["year"]).getAge(Date(1, 1, 60)) << " YEARS_OLD ";
        os << " ";
        if (json_characters[character]["sex"] == 0)
        {
            displayJob(os, json_characters[character]["job"]);
        }
        else
        {
            os << "\tBaby : " << json_characters[character]["baby"];
        }
        os << std::endl;
    }
    os << "Which Group of character you want to start with ?" << std::endl;
}

unsigned int Menu::configChoice() const noexcept
{
    unsigned int config ;
    do
    {
        std::cin >> config ;
    }while (config < Constantes::CONFIG_NUMBER) ;
    return config ;
}
void Menu::displayAllConfig(std::ostream &os) const
{
    os << "Here you are all the config" << std::endl;
    for (unsigned int i = 1; i <= Constantes::CONFIG_NUMBER; i++)
    {
        os << std::endl
           << "Config " << i << " : " << std::endl;
        Constantes::openingConfiguration(i);
        Constantes::displayConstantes(os);
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