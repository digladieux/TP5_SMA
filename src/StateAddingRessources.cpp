#include "../header/StateAddingRessources.hpp"
#include "../header/StateEating.hpp"
#include "../header/StateBuilding.hpp"
#include "../header/StateHavingSex.hpp"



StateAddingRessources::StateAddingRessources()
{
}

StateAddingRessources::~StateAddingRessources()
{
}
StateAddingRessources* StateAddingRessources::clone()
{
    return new StateAddingRessources();
}

void StateAddingRessources::run(Game&, Grid& grid, Ground *ground, MaleCharacter *character) const
{
    unsigned int number_ressource = Constantes::CONFIG_SIMU["ressourceSpecialityNumber"];
    unsigned int ressource_level_up = Constantes::CONFIG_SIMU["levelUp"];

    if ((JOB)character->getTypeRessourceTransported() != character->getSpeciality())
    {
        number_ressource = Constantes::CONFIG_SIMU["ressourceNotSpecialityNumber"];
    }

    ((TownHall *)ground)->addRessources(character->getTypeRessourceTransported(), number_ressource);

    if ((unsigned int)character->getCharacterCurrentLife() < grid.getColumnNumber() + grid.getColumnNumber() + (unsigned int)Constantes::CONFIG_SIMU["workTimeNotSpeciality"]) 
    {
        character->setCharacterCurrentState(new StateEating());
    }
    else if ((((TownHall *)ground)->getWoodNumber() >= ((TownHall *)ground)->getLevel() * ressource_level_up) && (((TownHall *)ground)->getRockNumber() >= ((TownHall *)ground)->getLevel() * ressource_level_up))
    {
        character->setCharacterCurrentState(new StateBuilding());
    }
    else
    {
        ((MaleCharacter *)character)->setCharacterCurrentState(new StateHavingSex());
    }
}