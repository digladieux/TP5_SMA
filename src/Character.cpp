#include "../header/Character.hpp"
#include "../header/mt19937ar.h"

unsigned int Character::character_number = 0;

Character::Character() : character_id(character_number), character_age(0)
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

Character::Character(SEX gender, const unsigned int age) : character_id(character_number), character_age(age), character_gender(gender)
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
    if ((character_age < 18) && (random < 0.05))
    {
        dead = true;
    }
    if ((character_age < 30) && (character_age >= 18) && (random < 0.10))
    {
        dead = true;
    }
    if ((character_age < 50) && (character_age >= 30) && (random < 0.15))
    {
        dead = true;
    }
    if ((character_age < 70) && (character_age >= 50) && (random < 0.25))
    {
        dead = true;
    }
    if ((character_age < 90) && (character_age >= 70) && (random < 0.30))
    {
        dead = true;
    }
    else
    {
        dead = true;
    }
    return dead;
}
