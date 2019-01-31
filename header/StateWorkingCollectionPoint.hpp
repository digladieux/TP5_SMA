#ifndef STATE_WORKING_COLLECTION_POINT
#define STATE_WORKING_COLLECTION_POINT

#include "State.hpp"
#include "Ground.hpp"
#include "Character.hpp"
#include "Constantes.hpp"
#include "TownHall.hpp"




class StateWorkingCollectionPoint : public State
{
    public:
        StateWorkingCollectionPoint();
        ~StateWorkingCollectionPoint();
        StateWorkingCollectionPoint *clone();
        void run(Game&, Grid&, Ground *, MaleCharacter *) const;
};

#endif