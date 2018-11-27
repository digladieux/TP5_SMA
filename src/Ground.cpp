#include "../header/Ground.hpp"
#include <iostream>
#include <exception>

unsigned int Ground::ground_number = 0;

Ground::Ground(GROUND_TYPE type) : ground_id(ground_number), ground_type(type), vector_character(0)
{
    ground_number++;
}

Ground::Ground(const Ground *ground)
{
    ground_id = ground->ground_id;
    ground_type = ground->ground_type;
    try
    {
        vector_character.resize(ground->vector_character.size());
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "BAD_ALLOCATION" << std::endl;
        throw e;
    }

    for (unsigned int i = 0; i < vector_character.size(); i++)
    {
        vector_character[i] = ground->vector_character[i];
    }
}

Ground::~Ground()
{
    Character *character;
    for (unsigned int i = 0; i < vector_character.size(); i++)
    {
        character = vector_character[0];
        vector_character.erase(vector_character.begin());
        delete character;
    }
}
/*TODO : Ground:15 Verifier si l'id est correct en fonction de la taille de la map */

void Ground::clearVector() noexcept
{
    Character *character;
    for (unsigned int i = 0; i < vector_character.size(); i++)
    {
        character = vector_character[0];
        delete character;
        vector_character.erase(vector_character.begin());
    }
}
unsigned int Ground::getGroundId() const noexcept
{
    return ground_id;
}

GROUND_TYPE Ground::getGroundType() const noexcept
{
    return ground_type;
}

unsigned int Ground::getVectorSize() const noexcept
{
    return vector_character.size();
}

void Ground::addCharacter(Character *new_worker)
{
    try
    {
        vector_character.push_back(new_worker);
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "VECTOR_TOO_HIGH" << std::endl;
        throw e;
    }
}

void Ground::removeCharacter(const unsigned int index)
{
    if (((int)index < 0) || (index >= vector_character.size()))
    {
        std::cerr << "[0;" << vector_character.size() - 1 << "], INDEX = " << index << std::endl;
        throw std::out_of_range("OUT_OF_RANGE_EXCEPTION");
    }
    Character *character = vector_character[index];
    vector_character.erase(vector_character.begin() + index);
    delete character;
}

Character *Ground::getCharacter(const unsigned int index)
{
    if (((int)index < 0) || (index >= vector_character.size()))
    {
        std::cerr << "ERROR - [0;" << vector_character.size() - 1 << "], INDEX = " << index << std::endl;
        throw std::out_of_range("OUT_OF_RANGE_EXCEPTION");
    }

    return vector_character[index];
}

void Ground::display(std::ostream &os) const noexcept
{
    os << ". ";
}
