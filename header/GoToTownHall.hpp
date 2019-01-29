#ifndef GOTOTOWNHALL_HPP
#define GOTOTOWNHALL_HPP

#include "State.hpp"

class GoToTownHall : public State
{
    public:

        GoToTownHall();
        ~GoToTownHall();
        void run(Ground *, Character *);
};

#endif