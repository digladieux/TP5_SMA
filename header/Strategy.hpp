/**
 * \file Strategy.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source Strategy.cpp
 * \date 2018-12-03
 */

#ifndef STRATEGY_HPP
#define STRATEGY_HPP

#include "MaleCharacter.hpp"
#include "Grid.hpp"
#include "MaleCharacter.hpp"
class MaleCharacter;
class Grid;

/**
 * \class Strategy
 * \brief Classe non instanciable de la strategy d'un personnage dans le choix d'un point de collecte
 */
class Strategy
{
  public:
    Strategy();
    virtual ~Strategy();

    /**
     * \fn virtual State* clone() = 0 
     * \brief Methode virtuelle pur pour la copie dynamique d'une strategy
     */
    
    virtual Strategy *clone() = 0;
    /**
     * \fn virtual bool run(Grid &, MaleCharacter *) = 0;
     * \brief Methode virtuelle pur pour l'execution d'une strategy
     * return True si on a trouve un point de collecte, false sinon
     */

    virtual bool run(Grid &, MaleCharacter *) = 0;
};

#endif