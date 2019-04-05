/**
 * \file MaleCharacter.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation de la classe MaleCharacter
 * \date 2018-12-06
 */

#include "../header/MaleCharacter.hpp"
#include "../header/Ground.hpp"
#include "../header/Exception.hpp"
#include "../header/StructCoordinates.hpp"
#include "../header/StrategyJob.hpp"
#include "../header/StrategyClosestCollectionPoint.hpp"
#include "../header/StrategyLowRessources.hpp"
#include "../header/Constantes.hpp"
#include "../header/mt19937ar.h"
#include "../header/StateChoisingCollectionPoint.hpp"

/**
 * \fn MaleCharacter::MaleCharacter(const MaleCharacter &maleCharacter) 
 * \brief Constructeur de copie de la classe MaleCharacter
 * \param &maleCharacter Personnage que l'on veut copier
 */
MaleCharacter::MaleCharacter(const MaleCharacter &character) : Character(character.getCharacterId(), character.getDateOfBirth(), character.getCharacterTeam(), character.getCharacterGender(), character.character_life, character.character_current_life), direction(character.direction), character_current_state(character.character_current_state->clone()),
                                                               type_ressource_transported(character.getTypeRessourceTransported()),
                                                               speciality(character.getSpeciality()),
                                                               character_strategy(character.character_strategy->clone()), 
                                                               time_at_work(character.getTimeAtWork())
{

}
/**
 * \fn MaleCharacter::MaleCharacter(const Date &age, unsigned int team, unsigned int column_number, const unsigned int strategy)
 * \brief Constructeur de la classe Male Character
 * \param &age Date de naissance du personnage
 * \param team Equipe du personnage
 * \param column_number Nombre de colonne sur le terrain
 * \param strategy Strategy adopte par le personnage
 */ 
MaleCharacter::MaleCharacter(const Date &age, unsigned int team, unsigned int column_number, const unsigned int strategy) : Character(SEX::MALE, age, team), direction(StructCoordinates()), character_current_state(new StateChoisingCollectionPoint()), type_ressource_transported(TYPE_RESSOURCE_TRANSPORTED::NO_RESSOURCE), time_at_work(0)
{
    if (team != 0)
    {
        direction.setAbcissa(column_number - 1);
        direction.setOrdinate(column_number - 1);
    }
    int id_job = (genrand_int31() % 4) + 1;
    speciality = jobIdToJob(id_job);
    character_strategy = strategyIdToStrategy(strategy);
}

/**
 * \fn MaleCharacter::MaleCharacter(JOB job, const Date &age, unsigned int team, unsigned int column_number, unsigned int life, const unsigned int strategy)
 * \brief Constructeur de la classe MaleCharacter
 * \param job Specialite du personnage
 * \param &age Date de naissance du personnage
 * \param team Equipe du personnage
 * \param column_number Nombre de colonne
 * \param life Point de vie maximale du personnage
 * \param strategy Strategy adopte par le personnage
 */
MaleCharacter::MaleCharacter(JOB job, const Date &age, unsigned int team, unsigned int column_number, unsigned int life, const unsigned int strategy) : Character(SEX::MALE, age, team, life), direction(StructCoordinates()), character_current_state(new StateChoisingCollectionPoint()), type_ressource_transported(TYPE_RESSOURCE_TRANSPORTED::NO_RESSOURCE), speciality(job), time_at_work(0)
{
    if (team != 0)
    {
        direction.setAbcissa(column_number - 1);
        direction.setOrdinate(column_number - 1);
    }
    character_strategy = strategyIdToStrategy(strategy);
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
 * \fn Strategy *MaleCharacter::strategyIdToStrategy(const unsigned int strategy)
 * \brief Methode qui convertit un entier en une strategy
 * \param strategy Strategy que l'on veut adopter pour le personnage
 * \return La strategy du personnage
 */
Strategy *MaleCharacter::strategyIdToStrategy(const unsigned int strategy)
{
    Strategy *new_strategy = nullptr;
    switch (strategy)
    {
    case 0:
        new_strategy = new StrategyJob();
        break;
    case 1:
        new_strategy = new StrategyLowRessources();
        break;
    case 2:
        new_strategy = new StrategyClosestCollectionPoint();
        break;
    default:
        throw InvalidStrategy(strategy);
        break;
    }
    return new_strategy;
}

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
 * \fn TYPE_RESSOURCE_TRANSPORTED MaleCharacter::getTypeRessourceTransported() const noexcept
 * \brief Getteur sur le type de ressource transporte par le personnage masculin
 * \return Type de ressource transporte par le personnage masculin
 */
TYPE_RESSOURCE_TRANSPORTED MaleCharacter::getTypeRessourceTransported() const noexcept
{
    return type_ressource_transported;
}

/**
 * \fn StructCoordinates &MaleCharacter::getDirection() noexcept
 * \brief Getteur sur la direction du personnage masculin
 * \return Direction du personnage masculin
 */
StructCoordinates &MaleCharacter::getDirection() noexcept
{
    return direction;
}

/**
 * \fn void MaleCharacter::setDirection(unsigned int ground_id, unsigned int column_number) noexcept
 * \brief Setteur sur la direction du personnage masculin
 * \param ground_id Id du terrain ou l'on veut se deplacer
 * \param column_number Nombre de colonne sur la carte
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
    delete character_current_state;
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

/**
 * \fn void MaleCharacter::resetTimeAtWork() noexcept
 * \brief Remise a zero du temps de travail
 */
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
 * \fn MaleCharacter &MaleCharacter::operator=(const MaleCharacter &new_character)
 * \brief Surchage de l'operateur d'affectation. Permet de cloner un personnage masculin dans un autre
 * \param new_character Personnage masculin sur l'on veut cloner
 * \return Nouveau Personnage masculin 
 */
MaleCharacter &MaleCharacter::operator=(const MaleCharacter &new_character)
{
    if (this != &new_character) /* On verifie que le personnage n'est pas le meme que l'on veut copier */
    {
        Character::operator=(new_character);
        speciality = new_character.speciality;
    }
    return *this;
}

/**
 * \fn JOB MaleCharacter::jobIdToJob(unsigned int job_id)
 * \brief Methode qui convertit un entier en une specialite
 * \param job_id Job que l'on veut affecter pour le personnage
 * \return La specialite du personnage
 */
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

/**
 * \fn void MaleCharacter::setCharacterStrategy(Strategy *new_strategy)
 * \brief Setteur sur la strategy du personnage. Supprime la strategie actuelle pour en affecter une nouvelle
 * \param *new_strategy Nouvelle strategie du personnage
 */
void MaleCharacter::setCharacterStrategy(Strategy *new_strategy)
{
    Strategy *current_strategy = character_strategy;
    character_strategy = new_strategy;
    delete current_strategy;
}

/**
 * \fn bool MaleCharacter::runStrategy(Grid &map)
 * \brief Lancement de la strategy du personnage
 * \param &map Carte ou se trouve le personnage
 * \return True si le personnage a pu trouver un point de collecte, faux sinon
 */
bool MaleCharacter::runStrategy(Grid &map)
{
    return character_strategy->run(map, this);
}

/**
 * \fn void MaleCharacter::executeState(Game &game, Grid &grid, Ground *ground, MaleCharacter *character, unsigned int &index_ground_with_character, unsigned int &index_character, unsigned int &number_ground_with_character, unsigned int &number_character_ground, bool &is_ground_deleted) const
 * \brief Lancement de l'etat du personnage et des actions associees
 * \param &game Jeux actuel
 * \param &grid Carte ou se trouve le personnage
 * \param *ground Terrain ou se trouve le personnage
 * \param *character Personnage en question
 * \param &index_ground_with_character Indice qui correspond a la position du terrain ou se trouve le personnage dans le vecteur de terrain
 * \param &index_character Indice qui correspond a la position du personnage dans le vecteur de personnage
 * \param &number_ground_with_character Nombre de terrain avec des personnage
 * \param &number_character_ground Nombre de personnage sur ce terrain
 * \param &is_ground_deleted Boolean pour savoir si le terrain a ete supprime
 */
void MaleCharacter::executeState(Game &game, Grid &grid, Ground *ground, MaleCharacter *character, unsigned int &index_ground_with_character, unsigned int &index_character, unsigned int &number_ground_with_character, unsigned int &number_character_ground, bool &is_ground_deleted) const
{
    character_current_state->run(game, grid, ground, character, index_ground_with_character, index_character, number_ground_with_character, number_character_ground, is_ground_deleted);
}
