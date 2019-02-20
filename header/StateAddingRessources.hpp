/**
 * \file StateAddingRessources.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source StateAddingRessources.cpp
 * \date 2018-12-03
 */

#ifndef STATE_ADDING_RESSOURCES_HPP
#define STATE_ADDING_RESSOURCES_HPP

#include "State.hpp"
#include "Ground.hpp"
#include "Character.hpp"
#include "Constantes.hpp"
#include "TownHall.hpp"



/**
 * \class StateAddingRessources
 * \brief Etat de l'ajout de ressource dans l'hotel de ville pour un personnage
 */
class StateAddingRessources : public State
{
    public:
        StateAddingRessources();
        ~StateAddingRessources();
        StateAddingRessources *clone();
    void run(Game &, Grid &, Ground *, MaleCharacter *, unsigned int &, unsigned int &, unsigned int &, unsigned int &, bool &) const;

};

#endif