#include "../header/MaleCharacter.hpp"
MaleCharacter::MaleCharacter() : Character(SEX::MALE_CHARACTER_CHILD), character_current_state(STATE::NO_STATE), type_ressource_transported(TYPE_RESSOURCE_TRANSPORTED::NO_RESSOURCE), speciality(JOB::NO_JOB), time_at_work(0)
{
    direction.abscissa = -1;
    direction.ordinate = -1;
}

MaleCharacter::MaleCharacter(JOB job, SEX gender, const unsigned int age) : Character(gender, age), character_current_state(STATE::NO_STATE), type_ressource_transported(TYPE_RESSOURCE_TRANSPORTED::NO_RESSOURCE),speciality(job), time_at_work(0) {}

MaleCharacter::~MaleCharacter(){};
JOB MaleCharacter::getSpeciality() const noexcept
{
    return speciality;
}

unsigned int MaleCharacter::getTimeAtWork() const noexcept
{
    return time_at_work;
}

STATE MaleCharacter::getCharacterCurrentState() const noexcept
{
    return character_current_state;
}
TYPE_RESSOURCE_TRANSPORTED MaleCharacter::getTypeRessourceTransported() const noexcept
{
    return type_ressource_transported;
}


StructCoordinates MaleCharacter::getDirection() const noexcept
{
    return direction;
}

void MaleCharacter::setDirection(unsigned int x, unsigned int y) noexcept
{
    direction.abscissa = x;
    direction.ordinate = y;
}

void MaleCharacter::setCharacterCurrentState(STATE new_state) noexcept
{
    character_current_state = new_state;
}

void MaleCharacter::setTypeRessourceTransported(TYPE_RESSOURCE_TRANSPORTED new_type_ressources) noexcept
{
    type_ressource_transported = new_type_ressources;
}

void MaleCharacter::setTimeAtWork() noexcept
{
    if (time_at_work == 3)
    {
        time_at_work = 0;
    }
    else
    {
        time_at_work++;
    }
}
void MaleCharacter::setSpeciality(JOB job) noexcept
{
    speciality = job;
}

const MaleCharacter &MaleCharacter::operator=(const MaleCharacter &new_character)
{
    if (this != &new_character)
    {
        Character::operator=(new_character);
        speciality = new_character.speciality;
    }
    return *this;
}
