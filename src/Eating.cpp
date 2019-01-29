#include "../header/Eating.hpp"
#include "../header/GoToCollectionPoint.hpp"


Eating::Eating()
{
}

Eating::~Eating()
{
}

void Eating::run(Ground *ground, Character * character)
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
        ((MaleCharacter *)character)->setCharacterCurrentState(new GoToCollectionPoint());
    }    
}

