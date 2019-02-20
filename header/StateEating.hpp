/**
 * \file StateEating.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source StateEating.cpp
 * \date 2018-12-03
 */

#ifndef STATE_EATING_HPP
#define STATE_EATING_HPP

#include "State.hpp"


/**
 * \class StateEating
 * \brief Etat de s'alimenter pour ne pas mourrir pour un personnage
 */
class StateEating : public State
{
    public:
        StateEating();
        ~StateEating();
        StateEating *clone();
    void run(Game &, Grid &, Ground *, MaleCharacter *, unsigned int &, unsigned int &, unsigned int &, unsigned int &, bool &) const;

};

#endif