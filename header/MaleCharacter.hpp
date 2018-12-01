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
    unsigned int time_at_work;

  public:
    MaleCharacter();
    MaleCharacter(JOB, SEX, const unsigned int);
    ~MaleCharacter();

    JOB getSpeciality() const noexcept;
    unsigned int getTimeAtWork() const noexcept;
    void setTimeAtWork() noexcept;

    void setSpeciality(JOB job) noexcept;
    const MaleCharacter &operator=(const MaleCharacter &new_character);
};
#endif
