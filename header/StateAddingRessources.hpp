#ifndef ADDRESSOURCES_HPP
#define ADDRESSOURCES_HPP

#include "State.hpp"
#include "Ground.hpp"
#include "Character.hpp"
#include "Constantes.hpp"
#include "TownHall.hpp"




class StateAddingRessources : public State
{
    public:
        StateAddingRessources();
        ~StateAddingRessources();
        StateAddingRessources *clone();
        void run(Ground *, Character *);
};

#endif