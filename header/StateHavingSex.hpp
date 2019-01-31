#ifndef STATE_HAVING_SEX_HPP
#define STATE_HAVING_SEX_HPP

#include "State.hpp"



class StateHavingSex : public State
{
    public:

        StateHavingSex();
        ~StateHavingSex();
        StateHavingSex *clone() ;
        void run(Game&, Grid&, Ground *, MaleCharacter *) const;
};

#endif