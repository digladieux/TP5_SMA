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
#include "../header/StrategyJob.hpp"
#include "../header/Constantes.hpp"
#include "../header/mt19937ar.h"
#include "../header/StateGoingCollectionPoint.hpp"

MaleCharacter::MaleCharacter(const MaleCharacter &character) : Character(character.getCharacterId(), character.getDateOfBirth(), character.getCharacterTeam(), character.getCharacterGender(), character.character_life, character.character_current_life), direction(character.direction), character_strategy(new StrategyJob()), type_ressource_transported(character.getTypeRessourceTransported()), speciality(character.getSpeciality()), time_at_work(character.getTimeAtWork())
{
     character_current_state = character.character_current_state->clone() ;
}
/**
 * \fn MaleCharacter::MaleCharacter()
 * \brief Constructeur par default de la classe Male Character
 */
MaleCharacter::MaleCharacter(const Date &age, unsigned int team,  unsigned int column_number) : Character(SEX::MALE, age, team), direction(StructCoordinates()), character_current_state(new StateGoingCollectionPoint()), type_ressource_transported(TYPE_RESSOURCE_TRANSPORTED::NO_RESSOURCE), character_strategy(new StrategyJob()),time_at_work(0)
{
    if (team != 0)
    {
        direction.setAbcissa(column_number - 1);
        direction.setOrdinate(column_number - 1);
    }
    int id_job = (genrand_int31() % 4) + 1;
    speciality = jobIdToJob(id_job);
}

/**
 * \fn MaleCharacter::MaleCharacter(JOB job, SEX gender, const unsigned int age)
 * \brief Constructeur de la classe Male Character
 * \param job Specialite du personnage
 * \param gender Sexe du personnage
 * \param age Age du personnage
 */
MaleCharacter::MaleCharacter(JOB job, const Date &age, unsigned int team, unsigned int column_number, unsigned int life) : Character(SEX::MALE, age, team, life), direction(StructCoordinates()), character_current_state(new StateGoingCollectionPoint()), type_ressource_transported(TYPE_RESSOURCE_TRANSPORTED::NO_RESSOURCE), speciality(job), character_strategy(new StrategyJob()), time_at_work(0)
{
    if (team != 0)
    {
        direction.setAbcissa(column_number - 1);
        direction.setOrdinate(column_number - 1);
    }
}

/**
 * \fn MaleCharacter::~MaleCharacter()
 * \brief Destructeur de la classe Male Character
 */
MaleCharacter::~MaleCharacter()
{
    delete character_strategy;
    delete character_current_state;
}

/**
 * \fn JOB MaleCharacter::getSpeciality() const noexcept
 * \brief Getteur sur la specialite du personnage masculin
 * \return Specialite du personnage
 up*/
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
void MaleCharacter::setCharacterCurrentState(State *new_state) noexcept
{
    delete character_current_state ;
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
        throw InvalidGroundType((unsigned int)new_type_ressources);
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

JOB MaleCharacter::jobIdToJob(unsigned int job_id)
{
    JOB job;
    switch (job_id)
    {
    case 1:
        job = JOB::QUARRY_MAN;
        break;

    case 2:
        job = JOB::LUMBERJACK;
        break;

    case 3:
        job = JOB::FISHERMAN;
        break;

    case 4:
        job = JOB::FARMER;
        break;

    default:
        throw InvalidJob(job_id);
    }

    return job;
}

void MaleCharacter::setCharacterStrategy(Strategy *new_strategy)
{
    Strategy *current_strategy = character_strategy;
    character_strategy = new_strategy;
    delete current_strategy;
}

bool MaleCharacter::runStrategy(Grid& map)
{
    return character_strategy->run(map, this) ;
}

void MaleCharacter::executeState(Game& game, Grid& grid, Ground * ground, Character * character)
{
    character_current_state->run();
}
