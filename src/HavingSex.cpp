


class HavingSex : public State
{
    public:

        virtual void HavingSex();
        virtual void run(Ground *, Character *);
}

virtual void HavingSex::HavingSex()
{
}

virtual void HavingSex::run(Ground* ground, Character* character)
{
    if (((MaleCharacter *)character)->getTimeAtWork() < Constantes::CONFIG_SIMU["workTimeNotSpeciality"])
    {
        ((MaleCharacter *)character)->incrementTimeAtWork();

        unsigned int index = 0;
        bool flag = false;
        while ((index < ground->getVectorSize()) && (!(flag)))
        {
            if ((SEX::FEMALE == (ground->getCharacter(index)->getCharacterGender())) && (Date() == (((FemaleCharacter *)ground->getCharacter(index))->getPregnancyTime())) && ((FemaleCharacter *)ground->getCharacter(index))->getCharacterAge(turn) >= Constantes::CONFIG_SIMU["majority"])
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
            ((MaleCharacter *)character)->setCharacterCurrentState(STATE::HAVING_SEX);
            ((FemaleCharacter *)ground->getCharacter(index))->setTimePregnancy(turn);
        }

        else
        {
            ((MaleCharacter *)character)->setCharacterCurrentState(STATE::GOING_TO_COLLECTION_POINT);
        }
    }
    else
    {
        ((MaleCharacter *)character)->resetTimeAtWork();
        ((MaleCharacter *)character)->setCharacterCurrentState(STATE::GOING_TO_COLLECTION_POINT);
    }    
}