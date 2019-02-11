#include "../header/StateHavingSex.hpp"
#include "../header/Ground.hpp"
#include "../header/Constantes.hpp"
#include "../header/Grid.hpp"
#include "../header/FemaleCharacter.hpp"
#include "../header/StateGoingCollectionPoint.hpp"

StateHavingSex::StateHavingSex() {}

StateHavingSex::~StateHavingSex() {}

StateHavingSex * StateHavingSex::clone()
{
    return new StateHavingSex();
}
void StateHavingSex::run(Game& game, Grid&, Ground *ground, MaleCharacter *character, unsigned int &, unsigned int &j, unsigned int &, unsigned int &, bool &) const
{
    if (character->getTimeAtWork() < Constantes::CONFIG_SIMU["workTimeNotSpeciality"])
    {
        character->incrementTimeAtWork();

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
            character->setCharacterCurrentState(new StateHavingSex());
            ((FemaleCharacter *)ground->getCharacter(index))->setTimePregnancy(game.getTurn());
        }

        else
        {
            character->setCharacterCurrentState(new StateGoingCollectionPoint());
        }
    }
    else
    {
        character->resetTimeAtWork();
        character->setCharacterCurrentState(new StateGoingCollectionPoint());
    }
    j++ ;
}