#include "../header/HavingSex.hpp"
#include "../header/Constantes.hpp"
#include "../header/Grid.hpp"
#include "../header/FemaleCharacter.hpp"
#include "../header/GoToCollectionPoint.hpp"

HavingSex::HavingSex() {}

HavingSex::~HavingSex() {}

HavingSex * HavingSex::clone()
{
    return new HavingSex();
}

void HavingSex::run(Game &game, Grid &map, Ground *ground, Character *character)
{
    if (((MaleCharacter *)character)->getTimeAtWork() < Constantes::CONFIG_SIMU["workTimeNotSpeciality"])
    {
        ((MaleCharacter *)character)->incrementTimeAtWork();

        unsigned int index = 0;
        bool flag = false;
        while ((index < ground->getVectorSize()) && (!(flag)))
        {
            if ((SEX::FEMALE == (ground->getCharacter(index)->getCharacterGender())) && (Date() == (((FemaleCharacter *)ground->getCharacter(index))->getPregnancyTime())) && ((FemaleCharacter *)ground->getCharacter(index))->getCharacterAge(game.getTurn()) >= Constantes::CONFIG_SIMU["majority"])
            {
                ((FemaleCharacter *)ground->getCharacter(index))->randomBabyPerPregnancy();
                if (((FemaleCharacter *)ground->getCharacter(index))->getBabyPerPregnancy() > 0)
                {
                    flag = true;
                }
            }
            else
            {
                index++;
            }
        }

        if (flag)
        {
            ((MaleCharacter *)character)->setCharacterCurrentState(new HavingSex());
            ((FemaleCharacter *)ground->getCharacter(index))->setTimePregnancy(game.getTurn());
        }

        else
        {
            ((MaleCharacter *)character)->setCharacterCurrentState(new GoToCollectionPoint());
        }
    }
    else
    {
        ((MaleCharacter *)character)->resetTimeAtWork();
        ((MaleCharacter *)character)->setCharacterCurrentState(new GoToCollectionPoint());
    }
}