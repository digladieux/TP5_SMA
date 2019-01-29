#include "../header/StateAddingRessources.hpp"
#include "../header/StateEating.hpp"
#include "../header/StateWorking.hpp"
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

void StateAddingRessources::run(Ground *ground, Character *character)
{
    unsigned int number_ressource = Constantes::CONFIG_SIMU["ressourceSpecialityNumber"];
    unsigned int ressource_level_up = Constantes::CONFIG_SIMU["levelUp"];

    if ((JOB)((MaleCharacter *)character)->getTypeRessourceTransported() != ((MaleCharacter *)character)->getSpeciality())
    {
        number_ressource = Constantes::CONFIG_SIMU["ressourceNotSpecialityNumber"];
    }

    ((TownHall *)ground)->addRessources(((MaleCharacter *)character)->getTypeRessourceTransported(), number_ressource);

    if (character->getCharacterCurrentLife() < 50) /* TODO RAND */
    {
        ((MaleCharacter *)character)->setCharacterCurrentState(new StateEating());
    }
    else if ((((TownHall *)ground)->getWoodNumber() >= ((TownHall *)ground)->getLevel() * ressource_level_up) && (((TownHall *)ground)->getRockNumber() >= ((TownHall *)ground)->getLevel() * ressource_level_up))
    {
        ((MaleCharacter *)character)->setCharacterCurrentState(new StateWorking());
    }
    else
    {
        ((MaleCharacter *)character)->setCharacterCurrentState(new StateHavingSex());
    }
}