


class Eating : public State
{
    public:
        virtual void Eating();
        virtual void run(Ground *, Character *);
}



virtual void Eating::Eating()
{
}

virtual void Eating::run(Ground *ground, Character * character)
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
        ((MaleCharacter *)character)->setCharacterCurrentState(STATE::GOING_TO_COLLECTION_POINT);
    }    
}

