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
    unsigned int number_of_death_this_turn;
    unsigned int number_of_death_total;

    void caseCollectionPoint(Character *, Ground *);
    void caseTownHall(Character *, Ground *);
    void turnCharacter(Character *, Ground *, unsigned int, unsigned int);
    void movementCharacter(Character *, Ground *, unsigned int, unsigned int, unsigned int, unsigned int);

  public:
    Game(const Grid &, const Date &date = Date());

    void run(unsigned int);
    void lifeOfCharacter();
    bool deathOfCharacter(Character *, unsigned int, unsigned int &);
    void birthOfCharacter(Character *);
    void incrementMonthGestationIfPregnant(Character *);
    static bool compareGroundTypeSpeciality(GROUND_TYPE, JOB);
    static bool compareTypeRessourceTransportedJob(TYPE_RESSOURCE_TRANSPORTED, JOB); /* TODO : test unitaire a faire */
    static double euclidienneDistance(const StructCoordinates &, const StructCoordinates &);

        void display(std::ostream &os = std::cout) const noexcept;
};

#endif
