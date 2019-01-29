#ifndef STATE_WORKING_HPP
#define STATE_WORKING_HPP


#include "State.hpp"
#include "Constantes.hpp"
#include "TownHall.hpp"
#include "StateGoingCollectionPoint.hpp"

class StateWorking : public State
{
    public:

        StateWorking();
        ~StateWorking();
        StateWorking *clone();
        void run(Ground *, Character *);
};

#endif
