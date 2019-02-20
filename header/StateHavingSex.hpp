/**
 * \file StateHavingSex.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source StateHavingSex.cpp
 * \date 2018-12-03
 */


#ifndef STATE_HAVING_SEX_HPP
#define STATE_HAVING_SEX_HPP

#include "State.hpp"
class Ground ;

/**
 * \class StateHavingSex
 * \brief Etat de faire l'amour par un personnage
 */
class StateHavingSex : public State
{
    public:

        StateHavingSex();
        ~StateHavingSex();
        StateHavingSex *clone() ;
    void run(Game &, Grid &, Ground *, MaleCharacter *, unsigned int &, unsigned int &, unsigned int &, unsigned int &, bool &) const;
};

#endif