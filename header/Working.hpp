#ifndef WORKING_HPP
#define WORKING_HPP


#include "State.hpp"
#include "Constantes.hpp"
#include "TownHall.hpp"
#include "GoToCollectionPoint.hpp"

class Working : public State
{
    public:

        Working();
        ~Working();
        Working *clone();
        void run(Game&, Grid&, Ground *, Character *);
};

#endif
