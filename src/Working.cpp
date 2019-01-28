


class Working : public State
{
    public:

        virtual void Working();
        virtual void run(Ground *, Character *);
}






virtual void Working::Working()
{
}


virtual void Working::run(Ground *ground, Character * character)
{
    unsigned int ressource_level_up = Constantes::CONFIG_SIMU["levelUp"];

    if (((MaleCharacter *)character)->getTimeAtWork() < Constantes::CONFIG_SIMU["workTimeNotSpeciality"])
    {
        ((TownHall *)ground)->removeRockNumber((((TownHall *)ground)->getLevel() * ressource_level_up));
        ((TownHall *)ground)->removeWoodNumber((((TownHall *)ground)->getLevel() * ressource_level_up));
        ((MaleCharacter *)character)->resetTimeAtWork();
        ((TownHall *)ground)->incrementLevel();
        ((MaleCharacter *)character)->setCharacterCurrentState(STATE::GOING_TO_COLLECTION_POINT);
    }
    else
    {
        ((MaleCharacter *)character)->incrementTimeAtWork();
    }    
}