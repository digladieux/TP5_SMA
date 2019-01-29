#include "../header/GoToTownHall.hpp"
#include "../header/AddRessources.hpp"


GoToTownHall::GoToTownHall()
{
}

GoToTownHall::~GoToTownHall()
{
}
GoToTownHall *GoToTownHall::clone()
{
    return new GoToTownHall();
}
void GoToTownHall::run(Game& game, Grid& grid, Ground *ground, Character * character)
{
    ((MaleCharacter *)character)->setCharacterCurrentState(new AddRessources());    
}

