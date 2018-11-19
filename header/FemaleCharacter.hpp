#ifndef FEMALE_CHARACTER_HPP
#define FEMALE_CHARACTER_HPP

#include "Character.hpp"

class FemaleCharacter : public Character
{
  private:
    unsigned int baby_per_pregnancy;
    unsigned int month_number_pregnancy;

  public:
    FemaleCharacter(const unsigned int age = 0);
    ~FemaleCharacter();

    unsigned int getBabyPerPregnancy() const noexcept;
    unsigned int getMonthNumberPregnancy() const noexcept;

    void randomBabyPerPregnancy() noexcept;
    void setMonthPregnancy() noexcept;
};
#endif
