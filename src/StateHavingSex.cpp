/**
 * \file StateHavingSex.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation de la classe StateHavingSex
 * \date 2018-12-03
 */

#include "../header/StateHavingSex.hpp"
#include "../header/Ground.hpp"
#include "../header/Constantes.hpp"
#include "../header/Grid.hpp"
#include "../header/FemaleCharacter.hpp"
#include "../header/StateGoingCollectionPoint.hpp"
/**
 * \fn StateHavingSex::StateHavingSex()
 * \brief Constructeur par default de la classe StateHavingSex
 */
StateHavingSex::StateHavingSex() {}


/**
 * \fn StateHavingSex::~StateHavingSex()
 * \brief Destructeur de la classe StateHavingSex
 */
StateHavingSex::~StateHavingSex() {}

/**
 * \fn StateHavingSex* StateHavingSex::clone() const
 * \brief Constructeur dynamique de la classe StateHavingSex. C'est un moyen de construire un constructeur virtuel. Quand on ne connait pas le type de State que l'on a et que l'on veut faire une copie de ce dernier, on utilise cette methode
 */
StateHavingSex * StateHavingSex::clone()
{
    return new StateHavingSex();
}

/**
 * \fn void StateHavingSex::run(Game& game, Grid&, Ground *ground, MaleCharacter *character, unsigned int &, unsigned int &j, unsigned int &, unsigned int &, bool &) const
 * \brief Lancement de l'etat Faire l'Amour par le personnage
 * \param &game Jeux actuel
 * \param *ground Terrain ou se trouve le personnage
 * \param *character Personnage en question
 * \param &j Indice qui correspond a la position du personnage dans le vecteur de personnage
 */
void StateHavingSex::run(Game& game, Grid&, Ground *ground, MaleCharacter *character, unsigned int &, unsigned int &j, unsigned int &, unsigned int &, bool &) const
{
    if (character->getTimeAtWork() < Constantes::CONFIG_SIMU["workTimeNotSpeciality"])
    {
        character->incrementTimeAtWork();

        unsigned int index = 0;
        bool flag = false;
        while ((index < ground->getVectorSize()) && (!(flag)))
        {
            if ((SEX::FEMALE == (ground->getCharacter(index)->getCharacterGender())) && (Date() == ((static_cast<FemaleCharacter*>(ground->getCharacter(index)))->getPregnancyTime())) && (static_cast<FemaleCharacter*>(ground->getCharacter(index)))->getCharacterAge(game.getTurn()) >= Constantes::CONFIG_SIMU["majority"])
            {
                (static_cast<FemaleCharacter*>(ground->getCharacter(index)))->randomBabyPerPregnancy();
                if ((static_cast<FemaleCharacter*>(ground->getCharacter(index)))->getBabyPerPregnancy() > 0)
                {
                    flag = true;
                }
            }
            else
            {
                index++;
            }
        }

        if (flag)
        {
            character->setCharacterCurrentState(new StateHavingSex());
            (static_cast<FemaleCharacter*>(ground->getCharacter(index)))->setTimePregnancy(game.getTurn());
        }

        else
        {
            character->setCharacterCurrentState(new StateGoingCollectionPoint());
        }
    }
    else
    {
        character->resetTimeAtWork();
        character->setCharacterCurrentState(new StateGoingCollectionPoint());
    }
    j++ ;
}