/**
 * \file StateChoisingCollectionPoint.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source StateChoisingCollectionPoint.cpp
 * \date 2018-12-03
 */

#ifndef STATE_GOING_COLLECTION_POINT_HPP
#define STATE_GOING_COLLECTION_POINT_HPP

#include "State.hpp"

class Grid;

/**
 * \class StateChoisingCollectionPoint
 * \brief Etat de choix du point de collect par un personnage
 */
class StateChoisingCollectionPoint : public State
{
  public:
    StateChoisingCollectionPoint();
    ~StateChoisingCollectionPoint();
    StateChoisingCollectionPoint *clone();
    void run(Game &, Grid &, Ground *, MaleCharacter *, unsigned int &, unsigned int &, unsigned int &, unsigned int &, bool &) const;

};

#endif
