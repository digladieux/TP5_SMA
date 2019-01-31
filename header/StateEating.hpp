#ifndef STATE_EATING_HPP
#define STATE_EATING_HPP

#include "State.hpp"



class StateEating : public State
{
    public:
        StateEating();
        ~StateEating();
        StateEating *clone();
        void run(Game&, Grid&, Ground *, MaleCharacter *) const;
};

#endif