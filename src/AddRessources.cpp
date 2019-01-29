#include "../header/AddRessources.hpp"
#include "../header/Eating.hpp"
#include "../header/Working.hpp"
#include "../header/HavingSex.hpp"



AddRessources::AddRessources()
{
}

AddRessources::~AddRessources()
{
}
AddRessources* AddRessources::clone()
{
    return new AddRessources();
}

void AddRessources::run(Game& game, Grid& grid, Ground *ground, Character *character)
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
        ((MaleCharacter *)character)->setCharacterCurrentState(new Eating());
    }
    else if ((((TownHall *)ground)->getWoodNumber() >= ((TownHall *)ground)->getLevel() * ressource_level_up) && (((TownHall *)ground)->getRockNumber() >= ((TownHall *)ground)->getLevel() * ressource_level_up))
    {
        ((MaleCharacter *)character)->setCharacterCurrentState(new Working());
    }
    else
    {
        ((MaleCharacter *)character)->setCharacterCurrentState(new HavingSex());
    }
}