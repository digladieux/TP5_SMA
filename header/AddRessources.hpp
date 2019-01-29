#ifndef ADDRESSOURCES_HPP
#define ADDRESSOURCES_HPP

#include "State.hpp"
#include "Ground.hpp"
#include "Character.hpp"
#include "Constantes.hpp"
#include "TownHall.hpp"




class AddRessources : public State
{
    public:
        AddRessources();
        ~AddRessources();
        AddRessources *clone();
        void run(Game&, Grid&, Ground *, Character *);
};

#endif