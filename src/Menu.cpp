#include "../header/Menu.hpp"
#include "../header/Constantes.hpp"
#include <fstream> /* TODO : constantes sur le nombre de map, character, config */
void Menu::displayWelcome(std::ostream &os) noexcept
{
    os << "Welcome to our game : CiviliZZation" << std::endl;
}
unsigned int Menu::displayMapChoice(std::ostream &os) noexcept
{
    int map;
    do
    {
        os << "Here you are all the map : " << std::endl;
        displayAllMap(os);
        os << "Where do you want to play ?" << std::endl;
        std::cin >> map;
        os << std::endl;
    } while ((map > 3) || (map <= 0));
    return map;
}

void displayAllMap(std::ostream &os)
{
    std::string file_name;
    for (unsigned int i = 1; i < 4; i++)
    {
        file_name = "./MAPS/Map" + std::to_string(i) + ".txt";
        displayMapFile(os, file_name);
    }
}

void displayMapFile(std::ostream &os, std::string file_name)
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
        std::cerr << "INVALID_FILE" << std::endl;
        std::cerr << file_name << std::endl;
        exit(EXIT_FAILURE);
    }
}

unsigned int Menu::displayCharacterChoice(std::ostream &os) noexcept
{
    int character;
    os << "Here you are all of our character :" << std::endl;
    do
    {
        displayAllCharacter(os);
        os << "Which Group of character you want to start with ?" << std::endl;
        std::cin >> character;
        os << std::endl;

    } while ((character > 4) || (character <= 0));
    return character;
}

void displayAllCharacter(std::ostream &os)
{
    std::string file_name;
    for (unsigned int i = 1; i < 4; i++)
    {
        file_name = "./CHARACTERS/Character" + std::to_string(i) + ".txt";
        displayCharacterFile(os, file_name);
    }
}

void displayCharacterFile(std::ostream &os, std::string file_name)
{
    std::ifstream file(file_name);
    std::string line;
    int character_number;
    if (!file.fail())
    {
        file >> character_number;
        os << "File's name : " << file_name << std::endl;
        os << "Number of character : " << character_number << std::endl;
        getline(file, line);
        while (character_number != 0)
        {
            getline(file, line);
            os << line << std::endl;
            character_number--;
        }
        os << std::endl;
    }
    else
    {
        std::cerr << "INVALID_FILE" << std::endl;
        exit(EXIT_FAILURE);
    }
}
unsigned int Menu::displayConfigChoice(std::ostream &os) noexcept
{
    int config;
    os << "Here you are all the config : "<< std::endl;
    do
    {
        displayAllConfig(os);
        os << "Which config do you want to use ?" << std::endl;
        std::cin >> config;
    } while ((config > 3) || (config <= 0));
    return config;
}

void displayAllConfig(std::ostream &os)
{
    for (unsigned int i = 1; i < 3; i++)
    {
        os << "Config " << i << " : " << std::endl;
        Constantes::openingConfiguration(i);
    }
}