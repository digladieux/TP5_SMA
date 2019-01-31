#include "../header/StateBuilding.hpp"
#include "../header/Constantes.hpp"


StateBuilding::StateBuilding()
{
}

StateBuilding::~StateBuilding()
{
}
StateBuilding* StateBuilding::clone()
{
    return new StateBuilding();
}
void StateBuilding::run(Game&, Grid&, Ground *ground, MaleCharacter * character, unsigned int &, unsigned int &j, unsigned int &, unsigned int &, bool &) const
{
    unsigned int ressource_level_up = Constantes::CONFIG_SIMU["levelUp"];

    if (character->getTimeAtWork() < Constantes::CONFIG_SIMU["workTimeNotSpeciality"])
    {
        ((TownHall *)ground)->removeRockNumber((((TownHall *)ground)->getLevel() * ressource_level_up));
        ((TownHall *)ground)->removeWoodNumber((((TownHall *)ground)->getLevel() * ressource_level_up));
        character->resetTimeAtWork();
        ((TownHall *)ground)->incrementLevel();

        character->setCharacterCurrentState(new StateGoingCollectionPoint());

    }
    else
    {
        character->incrementTimeAtWork();
    }    
    j++;
}