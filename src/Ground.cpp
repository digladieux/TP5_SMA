#include "../header/Ground.hpp"
#include <iostream>
#include <exception>

unsigned int Ground::ground_number = 0;

Ground::Ground(GROUND_TYPE type) : ground_id(ground_number), ground_type(type)
{
    ground_number++;
}
Ground::~Ground()
{
    Character *character;
    for (auto it = vector_character.begin(); it != vector_character.end(); )
    {
        character = *it;
        ++it;
        delete character;
    }
}
/*TODO : Ground:15 Verifier si l'id est correct en fonction de la taille de la map */

void Ground::clearVector() noexcept
{
    Character *character;
    for (auto it = vector_character.begin(); it != vector_character.end();)
    {
        character = *it;
        it++;
        delete character;
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
    vector_character.erase(vector_character.begin() + index);
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

void Ground::display(std::ostream& os) const noexcept
{
    os << " . ";
}
