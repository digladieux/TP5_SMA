/**
 * \file Forest.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation d'un personnage masculin
 * \date 2018-12-06
 */

#include "../header/MaleCharacter.hpp"
#include "../header/Ground.hpp"
#include "../header/Exception.hpp"
#include "../header/StructCoordinates.hpp"

MaleCharacter::MaleCharacter(const MaleCharacter &character) : Character(character.getCharacterId(), character.getDateOfBirth(), character.getCharacterTeam(), character.getCharacterGender()), direction(character.direction), character_current_state(character.getCharacterCurrentState()), type_ressource_transported(character.getTypeRessourceTransported()), speciality(character.getSpeciality()), time_at_work(character.getTimeAtWork())
{
}
/**
 * \fn MaleCharacter::MaleCharacter()
 * \brief Constructeur par default de la classe Male Character
 */
MaleCharacter::MaleCharacter(const Date &age) : Character(SEX::MALE, age), direction(0, 0), character_current_state(STATE::NO_STATE), type_ressource_transported(TYPE_RESSOURCE_TRANSPORTED::NO_RESSOURCE), speciality(JOB::NO_JOB), time_at_work(0) {}

/**
 * \fn MaleCharacter::MaleCharacter(JOB job, SEX gender, const unsigned int age)
 * \brief Constructeur de la classe Male Character
 * \param job Specialite du personnage
 * \param gender Sexe du personnage
 * \param age Age du personnage
 */
MaleCharacter::MaleCharacter(JOB job, const Date &age) : Character(SEX::MALE, age), direction(0, 0), character_current_state(STATE::NO_STATE), type_ressource_transported(TYPE_RESSOURCE_TRANSPORTED::NO_RESSOURCE), speciality(job), time_at_work(0) {}

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
 * \fn StructCoordinates StructCoordinates::getDirection() const noexcept
 * \brief Getteur sur la direction du personnage masculin
 * \return Direction du personnage masculin
 */
StructCoordinates &MaleCharacter::getDirection() noexcept
{
    return direction;
}

/**
 * \fn void StructCoordinates::setDirection(unsigned int x, unsigned int y) noexcept
 * \brief Setteur sur la direction du personnage masculin
 * \param x Cordoonee x du point
 * \param y Coordonne y du point
 */
void MaleCharacter::setDirection(unsigned int ground_id, unsigned int column_number) noexcept
{
    direction.setAbcissa(ground_id / column_number);
    direction.setOrdinate(ground_id % column_number);
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
 * \brief Seteur sur la ressource transportee
 * \param new_type_ressources Nouvelle ressource transportee
 */
void MaleCharacter::setTypeRessourceTransported(GROUND_TYPE new_type_ressources)
{
    switch (new_type_ressources)
    {
    case GROUND_TYPE::QUARRY:
        type_ressource_transported = TYPE_RESSOURCE_TRANSPORTED::ROCK;
        break;
    case GROUND_TYPE::FOREST:
        type_ressource_transported = TYPE_RESSOURCE_TRANSPORTED::WOOD;
        break;
    case GROUND_TYPE::LAKE:
        type_ressource_transported = TYPE_RESSOURCE_TRANSPORTED::FISH;
        break;
    case GROUND_TYPE::FARM:
        type_ressource_transported = TYPE_RESSOURCE_TRANSPORTED::FOOD;
        break;
    default:
        throw InvalidGroundType( (unsigned int) new_type_ressources);
    }
}

/**
 * \fn void MaleCharacter::incrementTimeAtWork() noexcept
 * \brief Setteur sur le temps passe au travail
 */
void MaleCharacter::incrementTimeAtWork() noexcept
{
    time_at_work++;
}

void MaleCharacter::resetTimeAtWork() noexcept
{
    time_at_work = 0;
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
