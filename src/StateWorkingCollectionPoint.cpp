/**
 * \file StateWorkingCollectionPoint.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation de la classe StateWorkingCollectionPoint
 * \date 2018-12-03
 */

#include "../header/StateWorkingCollectionPoint.hpp"
#include "../header/StateMovement.hpp"
#include "../header/StateAddingRessources.hpp"

/**
 * \fn StateWorkingCollectionPoint::StateWorkingCollectionPoint()
 * \brief Constructeur par default de la classe StateWorkingCollectionPoint
 */
StateWorkingCollectionPoint::StateWorkingCollectionPoint(){}

/**
 * \fn StateWorkingCollectionPoint::~StateWorkingCollectionPoint()
 * \brief Destructeur de la classe StateWorkingCollectionPoint
 */
StateWorkingCollectionPoint::~StateWorkingCollectionPoint(){}

/**
 * \fn StateWorkingCollectionPoint* StateWorkingCollectionPoint::clone() const
 * \brief Constructeur dynamique de la classe StateWorkingCollectionPoint. C'est un moyen de construire un constructeur virtuel. Quand on ne connait pas le type de State que l'on a et que l'on veut faire une copie de ce dernier, on utilise cette methode
 */
StateWorkingCollectionPoint* StateWorkingCollectionPoint::clone()
{
    return new StateWorkingCollectionPoint();
}


/**
 * \fn void StateWorkingCollectionPoint::run(Game&, Grid& map, Ground *ground, MaleCharacter *character, unsigned int &, unsigned int &j, unsigned int &, unsigned int &, bool &) const
 * \brief Lancement de l'etat Travail sur le point de collecte par le personnage
 * \param &grid Carte ou se trouve le personnage
 * \param *ground Terrain ou se trouve le personnage
 * \param *character Personnage en question
 * \param &j Indice qui correspond a la position du personnage dans le vecteur de personnage
 */
void StateWorkingCollectionPoint::run(Game&, Grid& map, Ground *ground, MaleCharacter *character, unsigned int &, unsigned int &j, unsigned int &, unsigned int &, bool &) const
{  
    unsigned int work_time = Constantes::CONFIG_SIMU["workTimeSpeciality"];
    if (ground->getGroundType() != (GROUND_TYPE)character->getSpeciality())
    {
        work_time = Constantes::CONFIG_SIMU["workTimeNotSpeciality"];
    }

    character->incrementTimeAtWork();
    if (character->getTimeAtWork() > work_time)
    {
        character->resetTimeAtWork();
        character->setDirection(character->getCharacterTeam(), map.getColumnNumber());
        character->setCharacterCurrentState(new StateMovement());


    }  
    j++ ;
}

