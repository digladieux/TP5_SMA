#include "../header/Grid.hpp"
#include "../header/TownHall.hpp"
#include "../header/Lake.hpp"
#include "../header/Farm.hpp"
#include "../header/Forest.hpp"
#include "../header/Color.hpp"
#include "../header/Quarry.hpp"
#include "../header/FemaleCharacter.hpp"

#include <fstream>
#include <string>
#include <array>
#include <iostream>

Grid::Grid(std::string file_name_map) : ground_with_character(0)
{

    std::ifstream file_map("INSTANCES/" + file_name_map);
    std::vector<Character *> vector_character;
    // unsigned int *character_per_town = nullptr;

    Ground::resetGroundNumber();
    unsigned int
        character_number,
        town_hall_number;

    if (file_map.fail())
    {
        std::cerr << "INVALID_FILE" << std::endl;
        exit(EXIT_FAILURE);
    }
    file_map >> character_number >> town_hall_number;

    unsigned int *character_per_town = new unsigned int[town_hall_number];
    try
    {
        vector_character.resize(character_number);
        for (unsigned int i = 0; i < town_hall_number; i++)
        {
            character_per_town[i] = 0;
        }
    }

    catch (const std::bad_alloc &e)
    {
        throw e;
    }

    /*! CHARACTER */
    initialisationCharacter(file_map, character_per_town, vector_character, character_number);

    /*! MAP */
    initialisationMap(file_map, character_per_town,vector_character);
    delete[] character_per_town;
    file_map.close();
}

void Grid::initialisationMap(std::ifstream &file_map, unsigned int *character_per_town, std::vector<Character *> &vector_character)
{
    unsigned int counter = 0;
    file_map >> row_number >> column_number;
    char type_ground;
    Ground *ground;
    ground_grid = new Ground **[row_number]();

    for (unsigned int i = 0; i < row_number; i++)
    {
        ground_grid[i] = new Ground *[column_number]();

        for (unsigned int j = 0; j < column_number; j++)
        {
            file_map >> type_ground;
            ground = initGround(type_ground);
            ground_grid[i][j] = ground;

            /*! Ajout des personnages dans la ville */
            if ((ground->getGroundType() != GROUND_TYPE::LAND) && (ground->getGroundType() != GROUND_TYPE::TOWN_HALL))
            {
                push_backGround(ground_with_collection_point, ground);
            }
            if (ground->getGroundType() == GROUND_TYPE::TOWN_HALL)
            {
                push_backGround(ground_with_character, ground);
                for (unsigned int k = 0; k < character_per_town[counter]; k++)
                {
                    addCharacterToGround(vector_character, ground, i, j);
                }
                counter++;
            }
        }
    }
}
void Grid::initialisationCharacter(std::ifstream &file, unsigned int *character_per_town, std::vector<Character *> &vector_character, unsigned int character_number)
{
    Character *character = nullptr;
    JOB job;
    unsigned int
        file_job,
        type_character,
        town_hall_number,
        day,
        month,
        year;
    for (unsigned int i = 0; i < character_number; i++)
    {
        file >> type_character >> town_hall_number >> day >> month >> year;
        switch (type_character)
        {
        case 0:
            file >> file_job;
            job = choiceJob(file_job);
            character = new MaleCharacter(job, Date(day, month, year));
            break;
        case 1:
            character = new FemaleCharacter(Date(day, month, year));
            break;
        default:

            std::cerr << "INVALID_GENDER" << std::endl;
            exit(EXIT_FAILURE);
        }
        character_per_town[town_hall_number]++;
        vector_character[i] = character;
    }
}

void Grid::addCharacterToGround(std::vector<Character *> &vector_character, Ground *ground, unsigned int i, unsigned int j)
{
    Character *character;
    character = vector_character[0];
    character->setCharacterTeam(ground->getGroundId());
    if (character->getCharacterGender() == SEX::MALE)
    {
        ((MaleCharacter *)character)->setDirection(ground->getGroundId(), column_number);
    }
    ground_grid[i][j]->addCharacter(character);
    vector_character.erase(vector_character.begin());
}
Grid::Grid(const Grid &map) : row_number(map.row_number), column_number(map.column_number)
{
    Ground *ground = nullptr;
    Ground *map_ground = nullptr;
    ground_with_character.clear();
    ground_with_collection_point.clear();
    ground_grid = new Ground **[row_number]();
    for (unsigned int i = 0; i < row_number; i++)
    {
        ground_grid[i] = new Ground *[column_number]();

        for (unsigned int j = 0; j < column_number; j++)
        {
            map_ground = map.ground_grid[i][j];
            switch (map_ground->getGroundType())
            {
            case GROUND_TYPE::FARM:
                ground = new Farm(*(Farm *)map_ground);
                break;
            case GROUND_TYPE::FOREST:
                ground = new Forest(*(Forest *)map_ground);
                break;
            case GROUND_TYPE::LAKE:
                ground = new Lake(*(Lake *)map_ground);
                break;
            case GROUND_TYPE::QUARRY:
                ground = new Quarry(*(Quarry *)map_ground);
                break;
            case GROUND_TYPE::TOWN_HALL:
                ground = new TownHall(*(TownHall *)map_ground);
                break;
            default:
                ground = new Ground(*map_ground);
                break;
            }
            ground_grid[i][j] = ground;
            if ((ground->getGroundType() != GROUND_TYPE::LAND) && (ground->getGroundType() != GROUND_TYPE::TOWN_HALL))
            {
                push_backGround(ground_with_collection_point, ground);
            }
            if (map_ground->getVectorSize() != 0)
            {
                push_backGround(ground_with_character, ground);
            }
        }
    }
    ground = nullptr;
    map_ground = nullptr;
}

void Grid::addGroundWithCharacter(Ground *ground)
{
    try
    {
        ground_with_character.push_back(ground);
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "BAD_ALLOC" << std::endl;
        throw e;
    }
}
void Grid::removeGroundWithCharacter(const unsigned int index)
{
    if (index > ground_with_character.size() - 1)
    {
        std::cerr << "OUT_OF_RANGE_INDEX" << std::endl;
        std::cerr << "REQUIRE_INDEX [0;< " << ground_with_character.size() - 1 << "], HERE = " << index << std::endl;
        exit(EXIT_FAILURE);
    }
    ground_with_character.erase(ground_with_character.begin() + index);
}
void Grid::push_backGround(std::vector<Ground *> &vector, Ground *ground)
{
    try
    {
        vector.push_back(ground);
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "BAD_ALLOC" << std::endl;
        throw e;
    }
}

JOB Grid::choiceJob(unsigned int file_job)
{
    JOB job;
    switch (file_job)
    {
    case 0:
        job = JOB::NO_JOB;
        break;
    case 1:
        job = JOB::FARMER;
        break;
    case 2:
        job = JOB::LUMBERJACK;
        break;
    case 3:
        job = JOB::QUARRY_MAN;
        break;
    case 4:
        job = JOB::FISHERMAN;
        break;
    default:
        std::cerr << "INVALID_JOB" << std::endl;
        exit(EXIT_FAILURE);
        break;
    }
    return job;
}

Ground *Grid::initGround(char type_ground)
{
    Ground *ground;
    switch (type_ground)
    {
    case 'T':
        ground = new TownHall();
        break;
    case 'L':
        ground = new Lake();
        break;
    case 'Q':
        ground = new Quarry();
        break;
    case 'F':
        ground = new Forest();
        break;
    case 'f':
        ground = new Farm();
        break;
    case '.':
        ground = new Ground();
        break;
    default:
        std::cerr << "INVALID_CHARACTER_FILE";
        ground = nullptr;
        break;
    }
    return ground;
}

Grid::~Grid()
{
    for (unsigned int i = 0; i < row_number; i++)
    {
        for (unsigned int j = 0; j < column_number; j++)
        {
            delete ground_grid[i][j];
        }

        delete[] ground_grid[i];
    }
    delete[] ground_grid;
}

void Grid::displayMap(std::ostream &os) const noexcept
{
    std::vector<Ground *> town_hall;
    for (unsigned int i = 0; i < row_number; i++)
    {
        for (unsigned int j = 0; j < column_number; j++)
        {
            if (ground_grid[i][j]->getGroundType() == GROUND_TYPE::TOWN_HALL)
            {
                push_backGround(town_hall, ground_grid[i][j]);
            }
            ground_grid[i][j]->display(os);
        }
        os << std::endl;
    }
    for (unsigned int i = 0; i < town_hall.size(); i++)
    {
        ((TownHall *)town_hall[i])->displayRessources(os);
    }
    os << std::endl;
}

void Grid::display(std::ostream &os) const noexcept
{
    std::vector<Ground *> town_hall;
    for (unsigned int i = 0; i < row_number; i++)
    {
        for (unsigned int j = 0; j < column_number; j++)
        {
            if (ground_grid[i][j]->getGroundType() == GROUND_TYPE::TOWN_HALL)
            {
                push_backGround(town_hall, ground_grid[i][j]);
            }
            if (ground_grid[i][j]->getVectorSize() == 0) /* TODO : pour le test */
            {
                ground_grid[i][j]->display(os);
            }
            else if (ground_grid[i][j]->getCharacter(0)->getCharacterTeam() == 0)
            {
                os << BOLDRED << ground_grid[i][j]->getVectorSize() << RESET << " ";
            }
            else
            {
                os << BOLDMAGENTA << ground_grid[i][j]->getVectorSize() << RESET << " ";
            }
        }
        os << std::endl;
    }
    for (unsigned int i = 0; i < town_hall.size(); i++)
    {
        ((TownHall *)town_hall[i])->displayRessources(os);
    }
    os << std::endl;
}

void Grid::displayCharacter(std::ostream &os) const noexcept
{
    for (unsigned int i = 0; i < row_number; i++)
    {
        for (unsigned int j = 0; j < column_number; j++)
        {
            if (ground_grid[i][j]->getVectorSize() == 0) /* TODO : pour le test */
            {
                os << ground_grid[i][j]->getVectorSize() << " ";
            }
            else if (ground_grid[i][j]->getCharacter(0)->getCharacterTeam() == 0)
            {
                os << BOLDRED << ground_grid[i][j]->getVectorSize() << RESET << " ";
            }
            else
            {
                os << BOLDMAGENTA << ground_grid[i][j]->getVectorSize() << RESET << " ";
            }
        }
        os << std::endl;
    }
    std::cout << std::endl;
}
unsigned int Grid::getRowNumber() const noexcept
{
    return row_number;
}

unsigned int Grid::getColumnNumber() const noexcept
{
    return column_number;
}

unsigned int Grid::getSizeVectorGroundWithCharacter() const noexcept
{
    return ground_with_character.size();
}

unsigned int Grid::getSizeVectorGroundWithCollectionPoint() const noexcept
{
    return ground_with_collection_point.size();
}

Ground *Grid::getGroundGrid(unsigned int index)
{
    try
    {
        return ground_grid[index / column_number][index % column_number];
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "INVALID_GROUND_ID" << std::endl;
        throw e;
    }
}

Ground *Grid::getDirectionCharacter(StructCoordinates direction)
{
    try
    {
        return ground_grid[direction.getAbscissa()][direction.getOrdinate()];
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "INVALID_DIRECTION" << std::endl;
        throw e;
    }
}

Ground *Grid::getGroundWithCharacter(unsigned int index) const
{
    if (index > ground_with_character.size() - 1)
    {
        std::cerr << "OUT_OF_RANGE_INDEX" << std::endl;
        std::cerr << "REQUIRE_INDEX [0;< " << ground_with_character.size() - 1 << "], HERE = " << index << std::endl;
        exit(EXIT_FAILURE);
    }

    return ground_with_character[index];
}

Ground *Grid::getGroundWithCollectionPoint(unsigned int index) const
{
    if (index > ground_with_collection_point.size() - 1)
    {
        std::cerr << "OUT_OF_RANGE_INDEX" << std::endl;
        std::cerr << "REQUIRE_INDEX [0;< " << ground_with_collection_point.size() - 1 << "], HERE = " << index << std::endl;
        exit(EXIT_FAILURE);
    }

    return ground_with_collection_point[index];
}

Ground *Grid::getGroundGrid(unsigned int row_index, unsigned int column_index) const
{
    if ((row_index > row_number - 1) || (column_index > column_number - 1))
    {
        std::cerr << "OUT_OF_RANGE_INDEX" << std::endl;
        std::cerr << "REQUIRE_ROW < " << row_number << " HERE = " << row_index << std::endl;
        std::cerr << "REQUIRE_COLUMN < " << column_number << " HERE = " << column_index << std::endl;
        exit(EXIT_FAILURE);
    }

    return ground_grid[row_index][column_index];
}
