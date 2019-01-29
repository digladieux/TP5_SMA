#ifndef GOTOTOWNHALL_HPP
#define GOTOTOWNHALL_HPP

#include "State.hpp"

class GoToTownHall : public State
{
  public:
    GoToTownHall();
    ~GoToTownHall();
    GoToTownHall *clone();

    void run(Game &game, Grid &, Ground *, Character *);
};

#endif