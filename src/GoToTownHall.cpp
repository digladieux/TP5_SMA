


class GoToTownHall : public State
{
    public:

        virtual void GoToTownHall();
        virtual void run(Ground *, Character *);
}

virtual void GoToTownHall::GoToTownHall()
{
}

virtual void run(Ground *ground, Character * character)
{
    ((MaleCharacter *)character)->setCharacterCurrentState(STATE::ADD_RESSOURCES_TO_TOWNHALL);    
}

