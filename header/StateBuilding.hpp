/**
 * \file StateBuilding.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source StateBuilding.cpp
 * \date 2018-12-03
 */

#ifndef STATE_WORKING_HPP
#define STATE_WORKING_HPP


#include "State.hpp"
#include "Constantes.hpp"
#include "TownHall.hpp"
#include "StateGoingCollectionPoint.hpp"

/**
 * \class StateBuilding
 * \brief Etat d'amelioration de l'hotel de ville par un personnage
 */
class StateBuilding : public State
{
    public:

        StateBuilding();
        ~StateBuilding();
        StateBuilding *clone();
    void run(Game &, Grid &, Ground *, MaleCharacter *, unsigned int &, unsigned int &, unsigned int &, unsigned int &, bool &) const;

};

#endif
