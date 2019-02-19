/**
 * \file StateEating.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation de la classe StateEating
 * \date 2018-12-03
 */

#include "../header/StateEating.hpp"
#include "../header/TownHall.hpp"
#include "../header/StateGoingCollectionPoint.hpp"
#include "../header/Constantes.hpp"

/**
 * \fn StateEating::StateEating()
 * \brief Constructeur par default de la classe StateEating
 */

StateEating::StateEating(){}

/**
 * \fn StateEating::~StateEating()
 * \brief Destructeur de la classe StateEating
 */
StateEating::~StateEating(){}

/**
 * \fn StateEating* StateEating::clone() const
 * \brief Constructeur dynamique de la classe StateEating. C'est un moyen de construire un constructeur virtuel. Quand on ne connait pas le type de State que l'on a et que l'on veut faire une copie de ce dernier, on utilise cette methode
 */
StateEating* StateEating::clone()
{
    return new StateEating();
}

/**
 * \fn void StateEating::run(Game&, Grid&, Ground *ground, MaleCharacter * character, unsigned int &, unsigned int &j, unsigned int &, unsigned int &, bool &) const
 * \brief Lancement de l'etat manger par le personnage
 * \param *ground Case ou se trouve le personnage
 * \param *character Personnage en question
 * \param &j Indice qui correspond a la position du personnage dans le vecteur de personnage
 */
void StateEating::run(Game&, Grid&, Ground *ground, MaleCharacter *character, unsigned int &, unsigned int &j, unsigned int &, unsigned int &, bool &) const
{
    if ((static_cast<TownHall*>(ground))->removeFishNumber(1))
    {
        character->giveCharacterLife((unsigned int)Constantes::CONFIG_SIMU["lifeWin"]);
    }
    else if ((static_cast<TownHall*>(ground))->removeFishNumber(1))
    {
        character->giveCharacterLife((unsigned int)Constantes::CONFIG_SIMU["lifeWin"]);
    }
    if (character->getCharacterGender() == SEX::MALE)
    {
        character->setCharacterCurrentState(new StateGoingCollectionPoint());
    }    
    j++;
}

