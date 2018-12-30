/**
 * \file Character.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation d'un personnage
 * \date 2018-12-03
 */

#include "../header/Character.hpp"
#include "../header/mt19937ar.h"
unsigned int Character::character_number = 0;

/**
 * \fn Character::Character()
 * \brief Constructeur par default d'un Personnage
 *
 */
Character::Character(const Character &character) : character_id(character.character_id), character_date_of_birth(character.character_date_of_birth), character_team(character.character_team), character_gender(character.character_gender)
{
    {
        character_number++;
    }
}
Character::Character(const Date &age) : character_id(character_number), character_date_of_birth(age), character_team(-1)
{
    character_number++;
    /* RAND : CARACTERE ALEATOIRE MODIFIABLE */
    if (genrand_real1() < 0.5)
    {
        character_gender = SEX::MALE;
    }
    else
    {
        character_gender = SEX::FEMALE;
    }
}
Character::Character(unsigned int id, const Date &age, int team, SEX gender) : character_id(id), character_date_of_birth(age), character_team(team), character_gender(gender)
{
    character_number++;
}
/**
 * \fn Character::Character(SEX gender, const unsigned int age)
 * \brief Constructeur de la classe Character
 * \param gender Sexe du personnage
 * \param age Age du personnage
 */
Character::Character(SEX gender, const Date &age) : character_id(character_number), character_date_of_birth(age), character_team(-1), character_gender(gender)
{
    character_number++;
}

/**
 * \brief Destructeur de la classe Character
 */
Character::~Character()
{
}

/**
 * \fn unsigned int Character::getCharacterId() const noexcept
 * \brief Getteur sur l'id du personnage
 * \return Id du personnage
 */
unsigned int Character::getCharacterId() const noexcept
{
    return character_id;
}

/**
 * \fn unsigned int Character::getDateOfBirth() const noexcept
 * \brief Getteur sur l'age du personnage
 * \return Age du personnage
 */
Date Character::getDateOfBirth() const noexcept
{
    return character_date_of_birth;
}

/**
 * \fn SEX Character::getCharacterGender() const noexcept
 * \brief Getteur sur le sexe du personnage
 * \return Sexe du personnage
 */
SEX Character::getCharacterGender() const noexcept
{
    return character_gender;
}

/**
 * \fn int Character::getCharacterTeam() const noexcept
 * \brief Getteur sur l'equipe du personnage
 * \return Equipe du personnage
 */
int Character::getCharacterTeam() const noexcept
{
    return character_team;
}

unsigned int Character::getCharacterAge(const Date &current_date) const
{
    unsigned int age;
    /*if (!(character_date_of_birth < current_date))
    {
        throw std::invalid_argument("INVALID_COMPARAISON");
    }*/
    if (Date(character_date_of_birth.getDay(), character_date_of_birth.getMonth(), 0) < Date(current_date.getDay(), current_date.getMonth(), 0))
    {
        age = current_date.getYear() - character_date_of_birth.getYear() - 1;
    }
    else
    {
        age = current_date.getYear() - character_date_of_birth.getYear();
    }

    return age;
}
/**
 * \fn void Character::setCharacterTeam(unsigned int new_team) noexcept
 * \brief Setteur sur l'equipe du personnage
 * \param new_team Nouvelle equipe du personnage
 */
void Character::setCharacterTeam(unsigned int new_team) noexcept
{
    character_team = new_team;
}

/**
 * \fn const Character &Character::operator=(const Character &new_character)
 * \brief Surchage de l'operateur =. Permet de cloner un personnage
 * \param new_character Le personnage que l'on veut cloner
 * \return Nouveau personnage
 */
const Character &Character::operator=(const Character &new_character)
{
    if (this != &new_character)
    {
        character_id = new_character.character_id;
        character_date_of_birth = new_character.character_date_of_birth;
    }
    return *this;
}

/**
 * \fun bool Character::isDead() const noexcept
 * \brief Permet de gerer aleatoirement la mort ou non d'un personnage
 * \return Vrai si le personnage meurt, faux sinon
 */
bool Character::isDead(const Date &current_date) const noexcept
{
    bool dead = false;
    double random = genrand_real1();
    /* RAND : CARACTERE ALEATOIRE MODIFIABLE */
    unsigned int age = this->getCharacterAge(current_date);
    if (age < 18)
    {
        if (random < 0.0005)
        {
            dead = true;
        }
    }
    else if (age < 30)
    {
        if (random < 0.0010)
        {
            dead = true;
        }
    }
    else if (age < 50)
    {
        if (random < 0.0015)
        {
            dead = true;
        }
    }
    else if (age < 70)
    {
        if (random < 0.0020)
        {
            dead = true;
        }
    }
    else if (age < 90)
    {
        if (random < 0.0025)
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
