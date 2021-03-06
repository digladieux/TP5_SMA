/**
 * \file StateChoisingCollectionPoint.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation de la classe StateChoisingCollectionPoint
 * \date 2018-12-03
 */

#include "../header/StateChoisingCollectionPoint.hpp"
#include "../header/Exception.hpp"
#include "../header/StateMovement.hpp"
#include "../header/StrategyClosestCollectionPoint.hpp"
#include "../header/StrategyLowRessources.hpp"
#include "../header/CollectionPoint.hpp"
#include "../header/Constantes.hpp"
#include "../header/Game.hpp"

/**
 * \fn StateChoisingCollectionPoint::StateChoisingCollectionPoint()
 * \brief Constructeur par default de la classe StateChoisingCollectionPoint
 */
StateChoisingCollectionPoint::StateChoisingCollectionPoint(){}


/**
 * \fn StateChoisingCollectionPoint::~StateChoisingCollectionPoint()
 * \brief Destructeur de la classe StateChoisingCollectionPoint
 */
StateChoisingCollectionPoint::~StateChoisingCollectionPoint(){}

/**
 * \fn StateChoisingCollectionPoint* StateChoisingCollectionPoint::clone() const
 * \brief Constructeur dynamique de la classe StateChoisingCollectionPoint. C'est un moyen de construire un constructeur virtuel. Quand on ne connait pas le type de State que l'on a et que l'on veut faire une copie de ce dernier, on utilise cette methode
 */
StateChoisingCollectionPoint *StateChoisingCollectionPoint::clone()
{
    return new StateChoisingCollectionPoint();
}

/**
 * \fn void StateChoisingCollectionPoint::run(Game &, Grid &grid, Ground *, MaleCharacter *character, unsigned int &, unsigned int &j, unsigned int &, unsigned int &, bool &) const
 * \brief Lancement de l'etat Choix du point de collection par le personnage
 * \param &grid Carte ou se trouve le personnage
 * \param *character Personnage en question
 * \param &j Indice qui correspond a la position du personnage dans le vecteur de personnage
 */
void StateChoisingCollectionPoint::run(Game &, Grid &grid, Ground *, MaleCharacter *character, unsigned int &, unsigned int &j, unsigned int &, unsigned int &, bool &) const
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