#include "../header/StateWorking.hpp"
#include "../header/Constantes.hpp"


StateWorking::StateWorking()
{
}

StateWorking::~StateWorking()
{
}
StateWorking* StateWorking::clone()
{
    return new StateWorking();
}
void StateWorking::run(Ground *ground, Character * character)
{
    unsigned int ressource_level_up = Constantes::CONFIG_SIMU["levelUp"];

    if (((MaleCharacter *)character)->getTimeAtWork() < Constantes::CONFIG_SIMU["workTimeNotSpeciality"])
    {
        ((TownHall *)ground)->removeRockNumber((((TownHall *)ground)->getLevel() * ressource_level_up));
        ((TownHall *)ground)->removeWoodNumber((((TownHall *)ground)->getLevel() * ressource_level_up));
        ((MaleCharacter *)character)->resetTimeAtWork();
        ((TownHall *)ground)->incrementLevel();

        ((MaleCharacter *)character)->setCharacterCurrentState(new StateGoingCollectionPoint());

    }
    else
    {
        ((MaleCharacter *)character)->incrementTimeAtWork();
    }    
}