/**
 * \file Character.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation de la classe Character
 * \date 2018-12-03
 */

#include "../header/Character.hpp"
#include "../header/Exception.hpp"
#include "../header/Constantes.hpp"
#include "../header/mt19937ar.h"

/**
 * \brief Variable statique du nombre de personnage genere a 0 ;
 */
unsigned int Character::character_number = 0; 
/**
 * \fn Character::Character(const Character &character) 
 * \brief Constructeur de copie de la classe Character
 * \param &character Personnage que l'on veut copier
 */
Character::Character(const Character &character) : character_id(character.character_id), character_date_of_birth(character.character_date_of_birth), character_team(character.character_team), character_gender(character.character_gender), character_life(character.character_life), character_current_life(character.character_current_life)
{
    character_number++;
}

/**
 * \fn Character::Character(const Date &age, unsigned int team)
 * \brief Constructeur de la classe Character
 * \param &age Date de naissance du personnage
 * \param team Equipe du personnage
 */
Character::Character(const Date &age, unsigned int team) : character_id(character_number), character_date_of_birth(age), character_team(team)
{
    unsigned int life_min = Constantes::CONFIG_SIMU["lifeMin"] ;
    unsigned int life_max = Constantes::CONFIG_SIMU["lifeMax"] ;
    character_life = (genrand_int31() % ( life_max - life_min )) + life_min;
    character_current_life = character_life;
    character_number++;
    if (genrand_real1() < Constantes::CONFIG_SIMU["chanceMale"])
    {
        character_gender = SEX::MALE;
    }
    else
    {
        character_gender = SEX::FEMALE;
    }
}

/**
 * \fn Character::Character(unsigned int id, const Date &age, int team, SEX gender, unsigned int life, unsigned int current_life)
 * \brief Constructeur de la classe Character 
 * \param id Identifiant unique du personnage
 * \param &age Date de naissance du personnage
 * \param gender Sexe du personnage
 * \param life Vie maximale que le personnage peut avoir
 * \param current_life Vie actuelle du personnange
 */
Character::Character(unsigned int id, const Date &age, int team, SEX gender, unsigned int life, unsigned int current_life) : character_id(id), character_date_of_birth(age), character_team(team), character_gender(gender), character_life(life), character_current_life(current_life)
{
    character_number++;
}
/**
 * \fn Character::Character(SEX gender, const Date &age, unsigned int team, unsigned int life)
 * \brief Constructeur de la classe Character 
 * \param gender Sexe du personnage
 * \param &age Date de naissance du personnage
 * \param team Equipe du personnage
 * \param life Vie maximale que le personnage peut avoir
 */
Character::Character(SEX gender, const Date &age, unsigned int team, unsigned int life) : character_id(character_number), character_date_of_birth(age), character_team(team), character_gender(gender), character_life(life), character_current_life(life)
{
    character_number++;
}


/**
 * \fn Character::~Character()
 * \brief Destructeur du personnage
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
 * \return Date de naissance du personnage
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
unsigned int Character::getCharacterTeam() const noexcept
{
    return character_team;
}

/**
 * \fn unsigned int Character::getCharacterAge(const Date &current_date) const
 * \brief Getter sur l'age du personnage
 * \param &current_date Date du jour courant
 * \return Age du personnage (en annee)
 */
unsigned int Character::getCharacterAge(const Date &current_date) const
{
    return character_date_of_birth.getAge(current_date);
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
 * \fn bool Character::isDead() const noexcept
 * \brief Permet de gerer aleatoirement la mort ou non d'un personnage
 * \return Vrai si le personnage meurt, faux sinon
 */
bool Character::isDead(const Date &current_date) const noexcept
{
    bool dead = false;
    /* RAND */
    double random = genrand_real1();
    unsigned int age = this->getCharacterAge(current_date);
    if (random < 0.0000000025 * age + 0.00025)
    {
        dead = true;
    }

    return dead;
}


/**
 * \fn bool Character::decrementCharacterLife() noexcept
 * \brief Permet de savoir si la decrementation de la vie du personnage a bien ete faite
 * \return Vrai si la decrementation a bien ete faite, faux sinon
 */
bool Character::decrementCharacterLife() noexcept
{
    /*TODO: verifie si il peut aller jusqu a la case car lifePerTurn*/
    character_current_life -= (int)Constantes::CONFIG_SIMU["lifePerTurn"];
    return character_current_life < 0;
}

/**
 * \fn void Character::giveCharacterLife() noexcept
 * \brief Remonte la vie d'un personnage
 * \param Nombre de point de vie que l'on veut redonner au personnage
 */
void Character::giveCharacterLife(unsigned int life) noexcept
{
    character_current_life = (character_current_life + life >= character_life) ? character_life : character_current_life + life;
}



/**
 * \fn int Character::getCharacterCurrentLife() const noexcept
 * \brief Renvoie le niveau de vie actuel de personnage
 * \return Vie actuelle du personnage
 */
int Character::getCharacterCurrentLife() const noexcept
{
    return character_current_life;
}
