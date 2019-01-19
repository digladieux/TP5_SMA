#include "../header/Grid.hpp"
#include "../header/TownHall.hpp"
#include "../header/Lake.hpp"
#include "../header/Farm.hpp"
#include "../header/Forest.hpp"
#include "../header/Color.hpp"
#include "../header/Quarry.hpp"
#include "../header/FemaleCharacter.hpp"
#include "../header/Exception.hpp"
#include "../header/json.hpp"

#include <fstream>
#include <string>
#include <iostream>
using json = nlohmann::json;

Grid::Grid(std::vector<unsigned int>& choice_map, std::vector<unsigned int>& choice_character) : ground_with_character(0)
{
    std::string file_name_map = "./MAPS/Maps.json";
    std::string file_name_character = "./CHARACTERS/Characters.json";
    std::ifstream file_map(file_name_map);
    std::ifstream file_character(file_name_character);
    std::vector<Character *> vector_character;
    Ground::resetGroundNumber();
    if (file_map.fail())
    {
        throw InvalidFile(file_name_map);
    }
    else if (file_character.fail())
    {
        throw InvalidFile(file_name_character);
    }

    /*! CHARACTER */
    initialisationCharacter(file_character, choice_character, vector_character);
    /*! MAP */

    initialisationMap(file_map, choice_map, vector_character);
    file_map.close();
    file_character.close();
}

void Grid::initialisationCharacter(std::ifstream &file_character, std::vector<unsigned int> choice_character, std::vector<Character *> &vector_character)
{
    try
    {
        vector_character.resize(choice_character.size());
    }
    catch (const std::bad_alloc &e)
    {
        throw e;
    }
    Character *character;
    json json_character;
    file_character >> json_character;
    std::string key_character;
    Date date_of_birth;
    unsigned int sex;
    for (unsigned int i = 0; i < choice_character.size(); i++)
    {
        if ((unsigned int)choice_character[i] > json_character["character_number"] )
        {
            throw InvalidKey(choice_character[i], json_character["character_number"] ) ;
        }
        key_character = "character" + std::to_string(choice_character[i]);
        try
        {
            date_of_birth = Date(json_character[key_character]["day"], json_character[key_character]["month"], json_character[key_character]["year"]);
        }
        catch (const ConstructorDateException &e)
        {
            throw e;
        }
        sex = json_character[key_character]["sex"];
        switch (sex)
        {
        case 0:
            character = new MaleCharacter(json_character[key_character]["job"], date_of_birth);
            /* TODO : cette fonction et on supprimera la ligne dans le initialisation map 
            ((MaleCharacter *)character)->setDirection(0);*/
            break;

        case 1:
            // TODO : faire un new constructeur
            character = new FemaleCharacter(date_of_birth, (unsigned int)json_character[key_character]["baby"]);
            break;

        default:
            throw InvalidGender(sex);
        }
        switch((int)json_character[key_character]["team"])
        {
            case 0:
                character->setCharacterTeam(0);
                break ;
            case 1:
         /*TODO : a changer par   (int)json_map[key_map]["row_number"] * (int)json[key_map]["column_number"] - 1*/
                character->setCharacterTeam(399);
                break ;
            default:
                throw InvalidTeam((int)json_character[key_character]["team"]) ;
                break ; 
        }
        vector_character[i] = character;
    }
}

void Grid::initialisationMap(std::ifstream &file_map, std::vector<unsigned int> choice_map, std::vector<Character *> &vector_character)
{
    json json_maps;
    unsigned int k, x, y;
    Ground *ground;
    Ground * collection_point ;
    Character *character;
    std::string key;

    file_map >> json_maps;
    row_number = json_maps["row_number"];
    column_number = json_maps["column_number"];
    ground_grid = new Ground **[row_number]();

    for (unsigned int i = 0; i < row_number; i++)
    {
        ground_grid[i] = new Ground *[column_number]();

        for (unsigned int j = 0; j < column_number; j++)
        {
            // TownHall
            if (((i == 0) && (j == 0)) || ((i == row_number - 1) && (j == column_number - 1)))
            {
                ground = new TownHall();
                ground_grid[i][j] = ground;
                push_backGround(ground_with_character, ground);
                k = 0;
                /*! Ajout des personnages dans la ville */
                while (k < vector_character.size())
                {
                    if (vector_character[k]->getCharacterTeam() == ground->getGroundId())
                    {
                        character = vector_character[k];
                        if (character->getCharacterGender() == SEX::MALE)
                        {
                            ((MaleCharacter *)character)->setDirection(ground->getGroundId(), column_number);
                        }
                        ground_grid[i][j]->addCharacter(character);
                        vector_character.erase(vector_character.begin() + k);
                    }
                    else
                    {
                        k++;
                    }
                }
            }
            else
            {
                ground = new Ground();
                ground_grid[i][j] = ground;
            }
        }
    }

    for (unsigned int i = 0; i < choice_map.size(); i++)
    {
        if ((unsigned int)choice_map[i] > json_maps["collection_point_number"] )
        {
            throw InvalidKey(choice_map[i], json_maps["collection_point_number"] ) ;
        }
        key = "collection_point" + std::to_string(choice_map[i]);
        x = json_maps[key]["x"] ;
        y = json_maps[key]["y"] ;
        ground = this->getGroundGrid(x, y);
        collection_point = initGround(ground, (int)json_maps[key]["type"] );
        push_backGround(ground_with_collection_point, collection_point);
        //ground = initGround(json_maps[key]["type"], json_maps[key]["ressource_number"]);
        ground_grid[x][y] = collection_point;
        delete ground;
    }
}

Ground *Grid::initGround(Ground * ground, unsigned int ground_type)
{
    Ground *collection_point;
    switch (ground_type)
    {
    case 1 :
        collection_point = new Quarry(*(Quarry*)ground);
        break;
    case 2 :
        collection_point = new Forest(*(Forest*)ground);
        break;
    case 3 :
        collection_point = new Lake(*(Lake*)ground);
        break;
    case 4 :
        collection_point = new Farm(*(Farm*)ground);
        break;
    default:
        throw InvalidGroundTypeReadingFile(ground_type);
        break;
    }
    return collection_point;
}

Ground *Grid::initGround(unsigned int type_ground, unsigned int ressource_number)
{
    Ground *ground;
    switch (type_ground)
    {
    case 1:
        ground = new Quarry(ressource_number);
        break;
    case 2:
        ground = new Forest(ressource_number);
        break;
    case 3:
        ground = new Lake(ressource_number);
        break;
    case 4:
        ground = new Farm(ressource_number);
        break;
    default:
        throw InvalidGroundTypeReadingFile(type_ground);
        break;
    }
    return ground;
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
        throw e;
    }
}
void Grid::removeGroundWithCharacter(const unsigned int index)
{
    if (index > ground_with_character.size() - 1)
    {
        throw OutOfRangeSuperior(index, ground_with_character.size());
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
        throw InvalidJob(file_job);
        break;
    }
    return job;
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
            if (ground_grid[i][j]->getVectorSize() == 0)
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
            if (ground_grid[i][j]->getVectorSize() == 0)
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
    if (index / column_number >= row_number)
    {
        throw OutOfRangeSuperior(index / column_number, row_number - 1);
    }
    else if (index % column_number >= column_number)
    {
        throw OutOfRangeSuperior(index % column_number, column_number - 1);
    }
    return ground_grid[index / column_number][index % column_number];
}

Ground *Grid::getDirectionCharacter(StructCoordinates direction)
{
    if (direction.getAbscissa() >= row_number)
    {
        throw OutOfRangeSuperior(direction.getAbscissa(), row_number - 1);
    }
    else if (direction.getOrdinate() >= column_number)
    {
        throw OutOfRangeSuperior(direction.getOrdinate(), column_number - 1);
    }
    return ground_grid[direction.getAbscissa()][direction.getOrdinate()];
}

Ground *Grid::getGroundWithCharacter(unsigned int index) const
{
    if (index > ground_with_character.size() - 1)
    {
        throw OutOfRangeSuperior(index, ground_with_character.size() - 1);
    }
    return ground_with_character[index];
}

Ground *Grid::getGroundWithCollectionPoint(unsigned int index) const
{
    if (index > ground_with_collection_point.size() - 1)
    {
        throw OutOfRangeSuperior(index, ground_with_collection_point.size() - 1);
    }

    return ground_with_collection_point[index];
}

Ground *Grid::getGroundGrid(unsigned int row_index, unsigned int column_index) const
{
    if (row_index > row_number - 1)
    {
        throw OutOfRangeSuperior(row_index, row_number - 1);
    }
    else if (column_index > column_number - 1)
    {
        throw OutOfRangeSuperior(column_index, column_number - 1);
    }

    return ground_grid[row_index][column_index];
}
