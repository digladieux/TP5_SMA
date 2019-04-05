/**
 * \file StateAddingRessources.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation de la classe StateAddingRessources
 * \date 2018-12-03
 */

#include "../header/StateAddingRessources.hpp"
#include "../header/StateEating.hpp"
#include "../header/StateBuilding.hpp"
#include "../header/StateHavingSex.hpp"


/**
 * \fn StateAddingRessources::StateAddingRessources()
 * \brief Constructeur par default de la classe StateAddingRessources
 */
StateAddingRessources::StateAddingRessources(){}

/**
 * \fn StateAddingRessources::~StateAddingRessources()
 * \brief Destructeur de la classe StateAddingRessources
 */
StateAddingRessources::~StateAddingRessources() {}

/**
 * \fn StateAddingRessources* StateAddingRessources::clone() const
 * \brief Constructeur dynamique de la classe StateAddingRessources. C'est un moyen de construire un constructeur virtuel. Quand on ne connait pas le type de State que l'on a et que l'on veut faire une copie de ce dernier, on utilise cette methode
 */
StateAddingRessources* StateAddingRessources::clone()
{
    return new StateAddingRessources();
}
/**
 * \fn void StateAddingRessources::run(Game&, Grid& grid, Ground *ground, MaleCharacter *character, unsigned int &, unsigned int & j, unsigned int &, unsigned int &, bool &) const
 * \brief Lancement de l'etat Ajout de ressource dans un hotel de ville par le personnage
 * \param &grid Carte ou se trouve le personnage
 * \param *ground Case ou se trouve le personnage
 * \param *character Personnage en question
 * \param &j Indice qui correspond a la position du personnage dans le vecteur de personnage
 */
void StateAddingRessources::run(Game&, Grid& grid, Ground *ground, MaleCharacter *character, unsigned int &, unsigned int & j, unsigned int &, unsigned int &, bool &) const
{
    unsigned int number_ressource = Constantes::CONFIG_SIMU["ressourceSpecialityNumber"];
    unsigned int ressource_level_up = Constantes::CONFIG_SIMU["levelUp"];

    if ((JOB)character->getTypeRessourceTransported() != character->getSpeciality())
    {
        number_ressource = Constantes::CONFIG_SIMU["ressourceNotSpecialityNumber"];
    }

    (static_cast<TownHall*>(ground))->addRessources(character->getTypeRessourceTransported(), number_ressource);

    if ( ((unsigned int)character->getCharacterCurrentLife() < (grid.getColumnNumber() + grid.getColumnNumber()) * (unsigned int)Constantes::CONFIG_SIMU["lifePerTurn"] + (unsigned int)Constantes::CONFIG_SIMU["workTimeNotSpeciality"]) && (ground->getVectorSize() > 1) ) 
    {
        character->setCharacterCurrentState(new StateEating());
    }
    else if (((static_cast<TownHall*>(ground))->getWoodNumber() >= (static_cast<TownHall*>(ground))->getLevel() * ressource_level_up) && ((static_cast<TownHall*>(ground))->getRockNumber() >= (static_cast<TownHall*>(ground))->getLevel() * ressource_level_up))
    {
        character->setCharacterCurrentState(new StateBuilding());
    }
    else
    {
        (static_cast<MaleCharacter*>(character))->setCharacterCurrentState(new StateHavingSex());
    }
    j++ ;
}