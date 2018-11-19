#include "../header/FemaleCharacter.hpp"
#include "../header/mt19937ar.h"
FemaleCharacter::FemaleCharacter(const unsigned int age) : Character(age), baby_per_pregnancy((genrand_int31() % 1) + 1), month_number_pregnancy(0) {}

FemaleCharacter::~FemaleCharacter(){};

unsigned int FemaleCharacter::getBabyPerPregnancy() const noexcept
{
    return baby_per_pregnancy;
}

unsigned int FemaleCharacter::getMonthNumberPregnancy() const noexcept
{
    return month_number_pregnancy;
}

void FemaleCharacter::randomBabyPerPregnancy() noexcept
{
    baby_per_pregnancy = genrand_int31() % 1 + 1;
}

void FemaleCharacter::setMonthPregnancy() noexcept
{
    if (month_number_pregnancy < 9)
    {
        month_number_pregnancy++;
    }
    else
    {
        month_number_pregnancy = 0;
    }
}
