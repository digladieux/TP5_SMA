#ifndef STATE_ADDING_RESSOURCES_HPP
#define STATE_ADDING_RESSOURCES_HPP

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
    void run(Game &, Grid &, Ground *, MaleCharacter *, unsigned int &, unsigned int &, unsigned int &, unsigned int &, bool &) const;

};

#endif