#include "../header/StateGoingTownHall.hpp"
#include "../header/StateAddingRessources.hpp"


StateGoingTownHall::StateGoingTownHall()
{
}

StateGoingTownHall::~StateGoingTownHall()
{
}
StateGoingTownHall *StateGoingTownHall::clone()
{
    return new StateGoingTownHall();
}
void StateGoingTownHall::run(Game&, Grid&, Ground *, MaleCharacter *character) const
{
    character->setCharacterCurrentState(new StateAddingRessources());    
}

