/**
 * \file Game.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source Game.cpp
 * \date 2018-12-03
 */

#ifndef GAME_HPP
#define GAME_HPP

#include "Grid.hpp"

void run(Grid &, unsigned int);
void game(Grid &);
void lifeOfCharacter(Grid &);
bool deathOfCharacter(Grid &grid, Character *character, unsigned int i, unsigned int &j);
void birthOfCharacter(Grid &grid, Character *character);
void transitionToAdult(Character *);
void incrementMonthGestationIfPregnant(Character *);

#endif