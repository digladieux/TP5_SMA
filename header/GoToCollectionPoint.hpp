#ifndef GOTOCOLLECTIONPOINT_HPP
#define GOTOCOLLECTIONPOINT_HPP

#include "State.hpp"

class Grid;
class GoToCollectionPoint : public State
{
  public:
    GoToCollectionPoint();
    ~GoToCollectionPoint();
    GoToCollectionPoint *clone();
    void run(Game &game, Grid &, Ground *, Character *);
};

#endif
