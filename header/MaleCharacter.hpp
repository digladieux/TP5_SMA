#ifndef MALE_CHARACTER_HPP
#define MALE_CHARACTER_HPP

#include "Character.hpp"

enum class JOB
{
    NO_JOB,
    FARMER,
    LUMBERJACK,
    QUARRY_MAN,
    FISHERMAN
};

class MaleCharacter : public Character
{
  private:
    JOB speciality;

  public:
    MaleCharacter(JOB job = JOB::NO_JOB, const unsigned int age = 0);
    ~MaleCharacter();

    JOB getSpeciality() const noexcept;
    void setSpeciality(JOB job) noexcept;
    const MaleCharacter &operator=(const MaleCharacter &new_character);
};
#endif
