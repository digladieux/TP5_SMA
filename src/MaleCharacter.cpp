/**
 * \file Forest.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation d'un personnage masculin
 * \date 2018-12-06
 */

#include "../header/MaleCharacter.hpp"

/**
 * \fn MaleCharacter::MaleCharacter()
 * \brief Constructeur par default de la classe Male Character
 */
MaleCharacter::MaleCharacter(const Date &age) : Character(SEX::MALE, age), character_current_state(STATE::NO_STATE), type_ressource_transported(TYPE_RESSOURCE_TRANSPORTED::NO_RESSOURCE), speciality(JOB::NO_JOB), time_at_work(0)
{
    direction.abscissa = -1;
    direction.ordinate = -1;
}

/**
 * \fn MaleCharacter::MaleCharacter(JOB job, SEX gender, const unsigned int age)
 * \brief Constructeur de la classe Male Character
 * \param job Specialite du personnage
 * \param gender Sexe du personnage
 * \param age Age du personnage
 */
MaleCharacter::MaleCharacter(JOB job, const Date &age) : Character(SEX::MALE, age), character_current_state(STATE::NO_STATE), type_ressource_transported(TYPE_RESSOURCE_TRANSPORTED::NO_RESSOURCE), speciality(job), time_at_work(0) {}

/**
 * \fn MaleCharacter::~MaleCharacter()
 * \brief Destructeur de la classe Male Character
 */
MaleCharacter::~MaleCharacter() {}

/**
 * \fn JOB MaleCharacter::getSpeciality() const noexcept
 * \brief Getteur sur la specialite du personnage masculin
 * \return Specialite du personnage
 */
JOB MaleCharacter::getSpeciality() const noexcept
{
    return speciality;
}

/**
 * \fn unsigned int MaleCharacter::getTimeAtWork() const noexcept
 * \brief Getteur sur le temps au travail passe par le personnage
 * \return Temps de travail realise par le personnage
 */
unsigned int MaleCharacter::getTimeAtWork() const noexcept
{
    return time_at_work;
}

/**
 * \fn STATE MaleCharacter::getCharacterCurrentState() const noexcept
 * \brief Getteur sur l'etat actuel du personnage
 * \return Etat actuel du personnage
 */
STATE MaleCharacter::getCharacterCurrentState() const noexcept
{
    return character_current_state;
}

/**
 * \fn TYPE_RESSOURCE_TRANSPORTED MaleCharacter::getTypeRessourceTransported() const noexcept
 * \brief Getteur sur le type de ressource transporte par le personnage masculin
 * \return Type de ressource transporte par le personnage masculin
 */
TYPE_RESSOURCE_TRANSPORTED MaleCharacter::getTypeRessourceTransported() const noexcept
{
    return type_ressource_transported;
}

/**
 * \fn StructCoordinates MaleCharacter::getDirection() const noexcept
 * \brief Getteur sur la direction du personnage masculin
 * \return Direction du personnage masculin
 */
StructCoordinates MaleCharacter::getDirection() const noexcept
{
    return direction;
}

/**
 * \fn void MaleCharacter::setDirection(unsigned int x, unsigned int y) noexcept
 * \brief Setteur sur la direction du personnage masculin
 * \param x Cordoonee x du point
 * \param y Coordonne y du point
 */
void MaleCharacter::setDirection(unsigned int x, unsigned int y) noexcept
{
    direction.abscissa = x;
    direction.ordinate = y;
}

/**
 * \fn void MaleCharacter::setCharacterCurrentState(STATE new_state) noexcept
 * \brief Setteur sur l'etat actuel du personnage masculin
 * \param new_state Nouvel etat du personnage
 */
void MaleCharacter::setCharacterCurrentState(STATE new_state) noexcept
{
    character_current_state = new_state;
}

/**
 * \fn void MaleCharacter::setTypeRessourceTransported(TYPE_RESSOURCE_TRANSPORTED new_type_ressources) noexcept
 * \brief Setteur sur la ressource transportee
 * \param new_type_ressources Nouvelle ressource transportee
 */
void MaleCharacter::setTypeRessourceTransported(TYPE_RESSOURCE_TRANSPORTED new_type_ressources) noexcept
{
    type_ressource_transported = new_type_ressources;
}

/**
 * \fn void MaleCharacter::setTimeAtWork() noexcept
 * \brief Setteur sur le temps passe au travail
 */
void MaleCharacter::setTimeAtWork() noexcept
{
    /* RAND : CARACTERE ALEATOIRE MODIFIABLE */
    if (time_at_work == 3)
    {
        time_at_work = 0;
    }
    else
    {
        time_at_work++;
    }
}

/**
 * \fn void MaleCharacter::setSpeciality(JOB job) noexcept
 * \brief Setteur sur la specialite du personnage
 * \param job Nouvelle specialite du personnage
 */
void MaleCharacter::setSpeciality(JOB job) noexcept
{
    speciality = job;
}

/**
 * \fn const MaleCharacter &MaleCharacter::operator=(const MaleCharacter &new_character)
 * \brief Surchage de l'operateur =. Permet de cloner un personnage masculin dans un autre
 * \param new_character Personnage masculin sur l'on veut cloner
 * \return Personnage masculin avec les nouvelles caracteristiques
 */
const MaleCharacter &MaleCharacter::operator=(const MaleCharacter &new_character)
{
    if (this != &new_character) /* On verifie que le personnage n'est pas le meme que l'on veut copier */
    {
        Character::operator=(new_character);
        speciality = new_character.speciality;
    }
    return *this;
}
