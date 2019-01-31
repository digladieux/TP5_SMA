#ifndef STATE_GOING_COLLECTION_POINT_HPP
#define STATE_GOING_COLLECTION_POINT_HPP

#include "State.hpp"

class Grid;
class StateGoingCollectionPoint : public State
{
  public:
    StateGoingCollectionPoint();
    ~StateGoingCollectionPoint();
    StateGoingCollectionPoint *clone();
    void run(Game &, Grid &, Ground *, MaleCharacter *, unsigned int &, unsigned int &, unsigned int &, unsigned int &, bool &) const;

};

#endif
