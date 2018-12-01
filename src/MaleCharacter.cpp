#include "../header/MaleCharacter.hpp"

MaleCharacter::MaleCharacter() : Character(SEX::MALE_CHARACTER_CHILD), speciality(JOB::NO_JOB), time_at_work(0) {}

MaleCharacter::MaleCharacter(JOB job, SEX gender, const unsigned int age) : Character(gender, age), speciality(job), time_at_work(0) {}

MaleCharacter::~MaleCharacter(){};
JOB MaleCharacter::getSpeciality() const noexcept
{
    return speciality;
}

unsigned int MaleCharacter::getTimeAtWork() const noexcept
{
    return time_at_work;
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

