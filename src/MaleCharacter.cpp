#include "../header/MaleCharacter.hpp"

MaleCharacter::MaleCharacter() : Character(SEX::MALE_CHARACTER_CHILD), speciality(JOB::NO_JOB) {}

MaleCharacter::MaleCharacter(JOB job, SEX gender, const unsigned int age) : Character(gender, age), speciality(job) {}

MaleCharacter::~MaleCharacter(){};
JOB MaleCharacter::getSpeciality() const noexcept
{
    return speciality;
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
