#include "../header/GoToTownHall.hpp"

GoToTownHall::GoToTownHall()
{
}

GoToTownHall::~GoToTownHall()
{
}

void run(Ground *ground, Character * character)
{
    ((MaleCharacter *)character)->setCharacterCurrentState(new AddRessources());    
}

