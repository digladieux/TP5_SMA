/**
 * \file StateMovement.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source StateMovement.cpp
 * \date 2018-12-03
 */

#ifndef STATE_MOVEMENT_HPP
#define STATE_MOVEMENT_HPP

#include "State.hpp"
#include "Ground.hpp"
#include "Character.hpp"
#include "Constantes.hpp"
#include "TownHall.hpp"

/**
 * \class StateMovement
 * \brief Etat de deplacement du personnage
 * 
 */
class StateMovement : public State
{
  private:
    bool movementOrdinate(Grid&, Character *, Ground *, unsigned int, unsigned int, unsigned int &, unsigned int &, unsigned int &, unsigned int &, bool &)const ;
    bool movementAbscissa(Grid&, Character *, Ground *, unsigned int, unsigned int, unsigned int &, unsigned int &, unsigned int &, unsigned int &, bool &)const ;
    bool movementCharacter(Grid&, Character *, Ground *, unsigned int, unsigned int, unsigned int &, unsigned int &, unsigned int &, unsigned int &, bool &)const ;

  public:
    StateMovement();
    ~StateMovement();
    StateMovement *clone();
    void run(Game &, Grid &, Ground *, MaleCharacter *, unsigned int &, unsigned int &, unsigned int &, unsigned int &, bool &) const;
    
};

#endif