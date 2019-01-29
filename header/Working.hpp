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
        void run(Ground *, Character *);
};

#endif
