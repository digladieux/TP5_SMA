#include "../header/Eating.hpp"
#include "../header/TownHall.hpp"
#include "../header/GoToCollectionPoint.hpp"
#include "../header/Constantes.hpp"


Eating::Eating()
{
}

Eating::~Eating()
{
}
Eating* Eating::clone()
{
    return new Eating();
}
void Eating::run(Game& game, Grid& map, Ground* ground, Character* character)
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

