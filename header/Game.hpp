/**
 * \file Game.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source Game.cpp
 * \date 2018-12-03
 */

#ifndef GAME_HPP
#define GAME_HPP

#include "Grid.hpp"
class Game
{
  private:
    Grid map;
    Date turn;
    void caseCollectionPoint(Character *, Ground *);
    void caseTownHall(Character *, Ground *);
    void movementCharacter(Character *, Ground *, unsigned int, unsigned int);

  public:
    Game(const Grid &, const Date &date = Date());

    void run(unsigned int);
    void lifeOfCharacter();
    bool deathOfCharacter(Character *character, unsigned int i, unsigned int &j);
    void birthOfCharacter(Character *character);
    void incrementMonthGestationIfPregnant(Character *);
    static bool compare(GROUND_TYPE ground_type, JOB job);
};

#endif
