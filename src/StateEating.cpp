#include "../header/StateEating.hpp"
#include "../header/TownHall.hpp"
#include "../header/StateGoingCollectionPoint.hpp"
#include "../header/Constantes.hpp"


StateEating::StateEating()
{
}

StateEating::~StateEating()
{
}
StateEating* StateEating::clone()
{
    return new StateEating();
}
void StateEating::run(Game&, Grid&, Ground *ground, MaleCharacter *character, unsigned int &, unsigned int &j, unsigned int &, unsigned int &, bool &) const
{
    if (((TownHall *)ground)->removeFishNumber(1))
    {
        character->giveCharacterLife((unsigned int)Constantes::CONFIG_SIMU["lifeWin"]);
    }
    else if (((TownHall *)ground)->removeFishNumber(1))
    {
        character->giveCharacterLife((unsigned int)Constantes::CONFIG_SIMU["lifeWin"]);
    }
    if (character->getCharacterGender() == SEX::MALE)
    {
        character->setCharacterCurrentState(new StateGoingCollectionPoint());
    }    
    j++;
}

