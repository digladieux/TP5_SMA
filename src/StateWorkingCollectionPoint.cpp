#include "../header/StateWorkingCollectionPoint.hpp"
#include "../header/StateGoingTownHall.hpp"


StateWorkingCollectionPoint::StateWorkingCollectionPoint()
{
}

StateWorkingCollectionPoint::~StateWorkingCollectionPoint()
{
}
StateWorkingCollectionPoint* StateWorkingCollectionPoint::clone()
{
    return new StateWorkingCollectionPoint();
}
void StateWorkingCollectionPoint::run(Game&, Grid& map, Ground *ground, MaleCharacter *character) const
{  
    unsigned int work_time = Constantes::CONFIG_SIMU["workTimeSpeciality"];
    if (ground->getGroundType() != (GROUND_TYPE)((MaleCharacter *)character)->getSpeciality())
    {
        work_time = Constantes::CONFIG_SIMU["workTimeNotSpeciality"];
    }

    ((MaleCharacter *)character)->incrementTimeAtWork();
    if (((MaleCharacter *)character)->getTimeAtWork() == 1)
    {
        ((MaleCharacter *)character)->setCharacterCurrentState(new StateGoingTownHall());
        ((MaleCharacter *)character)->setTypeRessourceTransported(ground->getGroundType());
    }
    else if (((MaleCharacter *)character)->getTimeAtWork() > work_time)
    {
        ((MaleCharacter *)character)->resetTimeAtWork();
        ((MaleCharacter *)character)->setDirection(character->getCharacterTeam(), map.getColumnNumber());
        
    }  
}

