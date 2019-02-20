/**
 * \file StateWorkingCollectionPoint.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source StateWorkingCollectionPoint.cpp
 * \date 2018-12-03
 */

#ifndef STATE_WORKING_COLLECTION_POINT
#define STATE_WORKING_COLLECTION_POINT

#include "State.hpp"
#include "Ground.hpp"
#include "Character.hpp"
#include "Constantes.hpp"
#include "TownHall.hpp"



/**
 * \class StateWorkingCollectionPoint
 * \brief Etat de travail sur un point de collecte
 */
class StateWorkingCollectionPoint : public State
{
    public:
        StateWorkingCollectionPoint();
        ~StateWorkingCollectionPoint();
        StateWorkingCollectionPoint *clone();
        void run(Game &, Grid &, Ground *, MaleCharacter *, unsigned int &, unsigned int &, unsigned int &, unsigned int &, bool &) const;
};

#endif