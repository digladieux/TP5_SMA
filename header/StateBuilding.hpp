#ifndef STATE_WORKING_HPP
#define STATE_WORKING_HPP


#include "State.hpp"
#include "Constantes.hpp"
#include "TownHall.hpp"
#include "StateGoingCollectionPoint.hpp"

class StateBuilding : public State
{
    public:

        StateBuilding();
        ~StateBuilding();
        StateBuilding *clone();
    void run(Game &, Grid &, Ground *, MaleCharacter *, unsigned int &, unsigned int &, unsigned int &, unsigned int &, bool &) const;

};

#endif
