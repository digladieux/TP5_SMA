


class AddRessources : public State
{
    public:
        virtual void AddREssources();
        virtual void run(Ground*, Character *);
}


virtual void AddREssources::AddREssources()
{

}


virtual void AddREssources::run(Ground *ground, Character *character)
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
        ((MaleCharacter *)character)->setCharacterCurrentState(STATE::EATING);
    }
    else if ((((TownHall *)ground)->getWoodNumber() >= ((TownHall *)ground)->getLevel() * ressource_level_up) && (((TownHall *)ground)->getRockNumber() >= ((TownHall *)ground)->getLevel() * ressource_level_up))
    {
        ((MaleCharacter *)character)->setCharacterCurrentState(STATE::WORKING);
    }
    else
    {
        ((MaleCharacter *)character)->setCharacterCurrentState(STATE::HAVING_SEX);
    }
}