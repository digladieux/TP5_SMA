/**
 * \file StateBuilding.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation de la classe StateBuilding
 * \date 2018-12-03
 */

#include "../header/StateBuilding.hpp"
#include "../header/Constantes.hpp"

/**
 * \fn StateBuilding::StateBuilding()
 * \brief Constructeur par default de la classe StateBuilding
 */

StateBuilding::StateBuilding()
{
}

/**
 * \fn StateBuilding::~StateBuilding()
 * \brief Destructeur de la classe StateBuilding
 */
StateBuilding::~StateBuilding(){}

/**
 * \fn StateBuilding* StateBuilding::clone() const
 * \brief Constructeur dynamique de la classe StateBuilding. C'est un moyen de construire un constructeur virtuel. Quand on ne connait pas le type de State que l'on a et que l'on veut faire une copie de ce dernier, on utilise cette methode
 */
StateBuilding* StateBuilding::clone()
{
    return new StateBuilding();
}

/**
 * \fn void StateBuilding::run(Game&, Grid&, Ground *ground, MaleCharacter * character, unsigned int &, unsigned int &j, unsigned int &, unsigned int &, bool &) const
 * \brief Lancement de l'etat Construction de l'hotel de ville par le personnage
 * \param *ground Case ou se trouve le personnage
 * \param *character Personnage en question
 * \param &j Indice qui correspond a la position du personnage dans le vecteur de personnage
 */
void StateBuilding::run(Game&, Grid&, Ground *ground, MaleCharacter * character, unsigned int &, unsigned int &j, unsigned int &, unsigned int &, bool &) const
{
    unsigned int ressource_level_up = Constantes::CONFIG_SIMU["levelUp"];

    if (character->getTimeAtWork() < Constantes::CONFIG_SIMU["workTimeNotSpeciality"])
    {
        (static_cast<TownHall*>(ground))->removeRockNumber(((static_cast<TownHall*>(ground))->getLevel() * ressource_level_up));
        (static_cast<TownHall*>(ground))->removeWoodNumber(((static_cast<TownHall*>(ground))->getLevel() * ressource_level_up));
        character->resetTimeAtWork();
        (static_cast<TownHall*>(ground))->incrementLevel();

        character->setCharacterCurrentState(new StateGoingCollectionPoint());

    }
    else
    {
        character->incrementTimeAtWork();
    }    
    j++;
}