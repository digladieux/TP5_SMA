/**
 * \file StateGoingCollectionPoint.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source StateGoingCollectionPoint.cpp
 * \date 2018-12-03
 */

#ifndef STATE_GOING_COLLECTION_POINT_HPP
#define STATE_GOING_COLLECTION_POINT_HPP

#include "State.hpp"

class Grid;

/**
 * \class StateGoingCollectionPoint
 * \brief Etat de choix du point de collect par un personnage
 */
class StateGoingCollectionPoint : public State
{
  public:
    StateGoingCollectionPoint();
    ~StateGoingCollectionPoint();
    StateGoingCollectionPoint *clone();
    void run(Game &, Grid &, Ground *, MaleCharacter *, unsigned int &, unsigned int &, unsigned int &, unsigned int &, bool &) const;

};

#endif
