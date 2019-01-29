#ifndef STATE_GOING_TOWN_HALL_HPP
#define STATE_GOING_TOWN_HALL_HPP

#include "State.hpp"

class StateGoingTownHall : public State
{
  public:
    StateGoingTownHall();
    ~StateGoingTownHall();
    StateGoingTownHall *clone();

    void run(Character *);
};

#endif