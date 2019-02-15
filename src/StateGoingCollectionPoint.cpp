/**
 * \file StateGoingCollectionPoint.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation de la classe StateGoingCollectionPoint
 * \date 2018-12-03
 */

#include "../header/StateGoingCollectionPoint.hpp"
#include "../header/Exception.hpp"
#include "../header/StateMovement.hpp"
#include "../header/StrategyClosestCollectionPoint.hpp"
#include "../header/StrategyLowRessources.hpp"
#include "../header/CollectionPoint.hpp"
#include "../header/Constantes.hpp"
#include "../header/Game.hpp"

/* TODO : il ne va pas au collection il le choisi il faut renommer */

/**
 * \fn StateGoingCollectionPoint::StateGoingCollectionPoint()
 * \brief Constructeur par default de la classe StateGoingCollectionPoint
 */
StateGoingCollectionPoint::StateGoingCollectionPoint(){}


/**
 * \fn StateGoingCollectionPoint::~StateGoingCollectionPoint()
 * \brief Destructeur de la classe StateGoingCollectionPoint
 */
StateGoingCollectionPoint::~StateGoingCollectionPoint(){}

/**
 * \fn StateGoingCollectionPoint* StateGoingCollectionPoint::clone() const
 * \brief Constructeur dynamique de la classe StateGoingCollectionPoint. C'est un moyen de construire un constructeur virtuel. Quand on ne connait pas le type de State que l'on a et que l'on veut faire une copie de ce dernier, on utilise cette methode
 */
StateGoingCollectionPoint *StateGoingCollectionPoint::clone()
{
    return new StateGoingCollectionPoint();
}

/**
 * \fn void StateGoingCollectionPoint::run(Game &, Grid &grid, Ground *, MaleCharacter *character, unsigned int &, unsigned int &j, unsigned int &, unsigned int &, bool &) const
 * \brief Lancement de l'etat Choix du point de collection par le personnage
 * \param &grid Carte ou se trouve le personnage
 * \param *character Personnage en question
 * \param &j Indice qui correspond a la position du personnage dans le vecteur de personnage
 */
void StateGoingCollectionPoint::run(Game &, Grid &grid, Ground *, MaleCharacter *character, unsigned int &, unsigned int &j, unsigned int &, unsigned int &, bool &) const
{
    if (!(character->runStrategy(grid)))
    {
        character->setCharacterStrategy(new StrategyClosestCollectionPoint());
        if (!(character->runStrategy(grid)))
        {
            throw NoRessourceAvailable() ;
        }
    }
    character->setCharacterCurrentState(new StateMovement());
    j++;
}