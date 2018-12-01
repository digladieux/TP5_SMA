#include "../header/Character.hpp"
#include "../header/mt19937ar.h"
#include <limits>
unsigned int Character::character_number = 0;

Character::Character() : character_id(character_number), character_age(0), character_current_state(STATE::NO_STATE), type_ressource_transported(TYPE_RESSOURCE_TRANSPORTED::NO_RESSOURCE)
{
    direction.abscissa = std::numeric_limits<unsigned int>::max();
    direction.ordinate = std::numeric_limits<unsigned int>::max();
    character_number++;
    if (genrand_real1() < 0.5)
    {
        character_gender = SEX::MALE_CHARACTER_CHILD;
    }
    else
    {
        character_gender = SEX::FEMALE_CHARACTER_CHILD;
    }
}

Character::Character(SEX gender, const unsigned int age) : character_id(character_number), character_age(age), character_gender(gender), character_current_state(STATE::NO_STATE), type_ressource_transported(TYPE_RESSOURCE_TRANSPORTED::NO_RESSOURCE)
{
    character_number++;
}

Character::~Character() {}
unsigned int Character::getCharacterId() const noexcept
{
    return character_id;
}

unsigned int Character::getCharacterAge() const noexcept
{
    return character_age;
}

SEX Character::getCharacterGender() const noexcept
{
    return character_gender;
}

STATE Character::getCharacterCurrentState() const noexcept
{
    return character_current_state;
}
TYPE_RESSOURCE_TRANSPORTED Character::getTypeRessourceTransported() const noexcept
{
    return type_ressource_transported;
}

StructCoordinates Character::getDirection() const noexcept
{
    return direction;
}

void Character::setCharacterCurrentState(STATE new_state) noexcept
{
    character_current_state = new_state;
}

void Character::setTypeRessourceTransported(TYPE_RESSOURCE_TRANSPORTED new_type_ressources) noexcept
{
    type_ressource_transported = new_type_ressources;
}

void Character::setCharacterGenderAdult() noexcept
{
    if (character_gender == SEX::FEMALE_CHARACTER_CHILD)
    {
        character_gender = SEX::FEMALE_CHARACTER_ADULT;
    }
    else
    {
        character_gender = SEX::MALE_CHARACTER_ADULT;
    }
}

void Character::setDirection(unsigned int x, unsigned int y) noexcept
{
    direction.abscissa = x;
    direction.ordinate = y;
}

void Character::incrementAge() noexcept
{
    character_age++;
}

const Character &Character::operator=(const Character &new_character)
{
    if (this != &new_character)
    {
        character_id = new_character.character_id;
        character_age = new_character.character_age;
    }
    return *this;
}

bool Character::isDead() const noexcept
{
    bool dead = false;
    double random = genrand_real1();
    if (character_age < 18)
    {
        if (random < 0.005)
        {
            dead = true;
        }
    }
    else if (character_age < 30)
    {
        if (random < 0.010)
        {
            dead = true;
        }
    }
    else if (character_age < 50)
    {
        if (random < 0.015)
        {
            dead = true;
        }
    }
    else if (character_age < 70)
    {
        if (random < 0.020)
        {
            dead = true;
        }
    }
    else if (character_age < 90)
    {
        if (random < 0.025)
        {
            dead = true;
        }
    }
    else
    {
        dead = true;
    }
    return dead;
}
