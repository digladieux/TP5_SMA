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
void StateGoingTownHall::run(Character * character)
{
    ((MaleCharacter *)character)->setCharacterCurrentState(new StateAddingRessources());    
}

