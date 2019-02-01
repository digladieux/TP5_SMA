#include "../header/StateWorkingCollectionPoint.hpp"
#include "../header/StateMovement.hpp"
#include "../header/StateAddingRessources.hpp"


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
void StateWorkingCollectionPoint::run(Game&, Grid& map, Ground *ground, MaleCharacter *character, unsigned int &, unsigned int &j, unsigned int &, unsigned int &, bool &) const
{  
    unsigned int work_time = Constantes::CONFIG_SIMU["workTimeSpeciality"];
    if (ground->getGroundType() != (GROUND_TYPE)character->getSpeciality())
    {
        work_time = Constantes::CONFIG_SIMU["workTimeNotSpeciality"];
    }

    character->incrementTimeAtWork();
    if (character->getTimeAtWork() == 1)
    {
        character->setTypeRessourceTransported(ground->getGroundType());
    }
    else if (character->getTimeAtWork() > work_time)
    {
        character->resetTimeAtWork();
        character->setDirection(character->getCharacterTeam(), map.getColumnNumber());
        character->setCharacterCurrentState(new StateMovement());


    }  
    j++ ;
}

