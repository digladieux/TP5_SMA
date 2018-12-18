#include "../header/Grid.hpp"
#include "../header/TownHall.hpp"
#include "../header/Lake.hpp"
#include "../header/Farm.hpp"
#include "../header/Forest.hpp"
#include "../header/Quarry.hpp"
#include "../header/FemaleCharacter.hpp"

#include <fstream>
#include <string>
#include <iostream>

Grid::Grid(std::string file_name) : ground_with_character(0)
{

    std::ifstream file("INSTANCES/" + file_name);
    Character *character = nullptr;
    std::vector<Character *> vector_character;
    unsigned int *character_per_town = nullptr;
    Ground::resetGroundNumber();
    JOB job;
    unsigned int
        character_number,
        type_character,
        town_hall_number,
        file_job,
        day,
        month,
        year,
        counter = 0;

    if (file.fail())
    {
        std::cerr << "INVALID_FILE" << std::endl;
        exit(EXIT_FAILURE);
    }
    file >> character_number;

    try
    {
        character_per_town = new unsigned int[character_number]; /* TODO : grid.cpp:40 plus opti */
        vector_character.resize(character_number);

        for (unsigned int i = 0; i < character_number; i++)
        {
            character_per_town[i] = 0;
        }
    }
    catch (const std::bad_alloc &e)
    {
        throw e;
    }

    /*! CHARACTER */

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
        character = nullptr;
    }

    /*! MAP */

    file >> row_number >> column_number;
    char type_ground;
    Ground *ground;
    ground_grid = new Ground **[row_number]();

    for (unsigned int i = 0; i < row_number; i++)
    {
        ground_grid[i] = new Ground *[column_number]();

        for (unsigned int j = 0; j < column_number; j++)
        {
            file >> type_ground;
            ground = initGround(type_ground);
            ground_grid[i][j] = ground;

            /*! Ajout des personnages dans la ville */
            if ((ground->getGroundType() != GROUND_TYPE::LAND) && (ground->getGroundType() != GROUND_TYPE::TOWN_HALL))
            {
                try
                {
                    ground_with_collection_point.push_back(ground_grid[i][j]);
                }
                catch (const std::bad_alloc &e)
                {
                    std::cerr << "BAD_ALLOC" << std::endl;
                    throw e;
                }
            }
            if (ground->getGroundType() == GROUND_TYPE::TOWN_HALL)
            {
                try
                {
                    ground_with_character.push_back(ground_grid[i][j]);
                }
                catch (const std::bad_alloc &e)
                {
                    std::cerr << "BAD_ALLOC" << std::endl;
                    throw e;
                }
                for (unsigned int k = 0; k < character_per_town[counter]; k++)
                {
                    character = vector_character[0];
                    character->setCharacterTeam(ground->getGroundId());
                    ground_grid[i][j]->addCharacter(character);
                    vector_character.erase(vector_character.begin());
                }
                counter++;
            }
        }
    }

    character = nullptr;
    delete[] character_per_town;
    character_per_town = nullptr;
    file.close();
}

Grid::Grid(const Grid &map) : row_number(map.row_number), column_number(map.column_number)
{
    ground_grid = new Ground **[row_number]();
    ground_with_character.clear();
    ground_with_collection_point.clear();
    try
    {
        ground_with_character.resize(map.ground_with_character.size());
        ground_with_collection_point.resize(map.ground_with_collection_point.size());
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "BAD_ALLOC" << std::endl;
        throw e;
    }

    for (unsigned int i = 0; i < row_number; i++)
    {
        ground_grid[i] = new Ground *[column_number]();

        for (unsigned int j = 0; j < column_number; j++)
        {
            ground_grid[i][j] = map.ground_grid[i][j];
        }
    }
    for (unsigned int i = 0; i < ground_with_character.size(); i++)
    {
        ground_with_character[i] = map.ground_with_character[i];
    }

    for (unsigned int i = 0; i < ground_with_collection_point.size(); i++)
    {
        ground_with_collection_point[i] = map.ground_with_collection_point[i];
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
    for (unsigned int i = 0; i < row_number; i++)
    {
        for (unsigned int j = 0; j < column_number; j++)
        {
            ground_grid[i][j]->display(os);
        }
        os << std::endl;
    }
    os << std::endl;
}

void Grid::displayCharacter(std::ostream &os) const noexcept
{
    for (unsigned int i = 0; i < row_number; i++)
    {
        for (unsigned int j = 0; j < column_number; j++)
        {
            os << ground_grid[i][j]->getVectorSize() << " ";
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
        return ground_grid[direction.abscissa][direction.ordinate];
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
