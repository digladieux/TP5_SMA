#include "../header/Character.hpp"
#include "../header/mt19937ar.h"
unsigned int Character::character_number = 0;

Character::Character() : character_id(character_number), character_age(0), team(-1)
{
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

Character::Character(SEX gender, const unsigned int age) : character_id(character_number), character_age(age), team(-1), character_gender(gender)
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

int Character::getTeam() const noexcept
{
    return team;
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

void Character::setTeam(unsigned int new_team) noexcept
{
    team = new_team;
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
