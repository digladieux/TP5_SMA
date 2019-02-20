/**
 * \file State.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source State.cpp
 * \date 2018-12-03
 */

#ifndef STATE_HPP
#define STATE_HPP

#include "../header/MaleCharacter.hpp"

class Ground;
class MaleCharacter;
class Game;
class Grid;

/**
 * \class State
 * \brief Classe non instanciable de l'etat d'un personnage
 */
class State
{

    public:
    State();
    virtual ~State();

    /**
     * \fn virtual State* clone() = 0 
     * \brief Methode virtuelle pur pour la copie dynamique d'un etat
     */
    virtual State* clone() = 0 ;
    
    /**
     * \fn virtual void run(Game &, Grid &, Ground *, MaleCharacter *, unsigned int &, unsigned int &, unsigned int &, unsigned int &, bool &) const = 0
     * \brief Methode virtuelle pur pour l'execution d'un etat
     */
    virtual void run(Game &, Grid &, Ground *, MaleCharacter *, unsigned int &, unsigned int &, unsigned int &, unsigned int &, bool &) const = 0;

};


#endif