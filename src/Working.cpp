#include "../header/Working.hpp"
#include "../header/Constantes.hpp"


Working::Working()
{
}

Working::~Working()
{
}
Working* Working::clone()
{
    return new Working();
}
void Working::run(Game& game, Grid& grid, Ground *ground, Character * character)
{
    unsigned int ressource_level_up = Constantes::CONFIG_SIMU["levelUp"];

    if (((MaleCharacter *)character)->getTimeAtWork() < Constantes::CONFIG_SIMU["workTimeNotSpeciality"])
    {
        ((TownHall *)ground)->removeRockNumber((((TownHall *)ground)->getLevel() * ressource_level_up));
        ((TownHall *)ground)->removeWoodNumber((((TownHall *)ground)->getLevel() * ressource_level_up));
        ((MaleCharacter *)character)->resetTimeAtWork();
        ((TownHall *)ground)->incrementLevel();

        ((MaleCharacter *)character)->setCharacterCurrentState(new GoToCollectionPoint());

    }
    else
    {
        ((MaleCharacter *)character)->incrementTimeAtWork();
    }    
}