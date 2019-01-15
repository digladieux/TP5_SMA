/**
 * \file FemaleCharacter.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation d'un personnage feminin
 * \date 2018-12-06
 */

#include "../header/FemaleCharacter.hpp"
#include "../header/mt19937ar.h"
#include "../header/Constantes.hpp"
#include "../header/Exception.hpp"

FemaleCharacter::FemaleCharacter(const FemaleCharacter &character) : Character(character.getCharacterId(), character.getDateOfBirth(), character.getCharacterTeam(), character.getCharacterGender()), baby_per_pregnancy(character.getBabyPerPregnancy()), pregnancy_time(character.getPregnancyTime()) {}
/**
 * \fn FemaleCharacter::FemaleCharacter()
 * \brief Constructeur par default de la classe Female Character
 */
FemaleCharacter::FemaleCharacter(const Date &age) : Character(SEX::FEMALE, age), baby_per_pregnancy(genrand_int31() % (unsigned int) Constantes::CONFIG_SIMU["maxBaby"]), pregnancy_time(Date())
{
}


/**
 * \fn FemaleCharacter::FemaleCharacter()
 * \brief Constructeur par default de la classe Female Character
 */
FemaleCharacter::FemaleCharacter(const Date &age, unsigned int number_of_baby) : Character(SEX::FEMALE, age), baby_per_pregnancy(number_of_baby), pregnancy_time(Date())
{
}

/**
 * \fn FemaleCharacter::~FemaleCharacter()
 * \brief Destructeur de la classe Female Character:: Female Character
 */
FemaleCharacter::~FemaleCharacter() {}

/**
 * \fn unsigned int FemaleCharacter::getBabyPerPregnancy() const noexcept
 * \brief Getteur sur le nombre d'enfant par grossesse
 * \return Nombre d'enfant par grosse
 */
unsigned int FemaleCharacter::getBabyPerPregnancy() const noexcept
{
    return baby_per_pregnancy;
}

/**
 * \fn Date FemaleCharacter::getPregnancyTime() const noexcept
 * \brief Getteur sur le numero du mois de la grossesse
 * \return Nombre de mois de grossesse
 */
Date FemaleCharacter::getPregnancyTime() const noexcept
{
    return pregnancy_time;
}

/**
 * \fn void FemaleCharacter::randomBabyPerPregnancy() noexcept
 * \brief Affecte un nombre aleatoire sur nombre de bebe par grossesse
 */
void FemaleCharacter::randomBabyPerPregnancy() noexcept
{
    unsigned int max_baby = Constantes::CONFIG_SIMU["maxBaby"];
    baby_per_pregnancy = genrand_int31() % max_baby;
}

void FemaleCharacter::setTimePregnancy(const Date &date) noexcept
{
    pregnancy_time = date;
}

unsigned int FemaleCharacter::getMonthPregnancy(const Date &current_date) const
{
    unsigned int month;
    if (pregnancy_time == current_date)
    {
        month = 0;
    }
    else if (!(character_date_of_birth < current_date))
    {
        throw CurrentDateBeforeBirthException(current_date, character_date_of_birth);
    }
    else if (pregnancy_time.getMonth() == current_date.getMonth())
    {
        month = 0;
    }
    else if (pregnancy_time.getMonth() < current_date.getMonth())
    {
        if (pregnancy_time.getDay() == current_date.getDay())
        {
            month = current_date.getMonth() - pregnancy_time.getMonth();
        }
        else if (pregnancy_time.getDay() < current_date.getDay())
        {
            month = current_date.getMonth() - pregnancy_time.getMonth();
        }
        else
        {
            month = current_date.getMonth() - pregnancy_time.getMonth() - 1;
        }
    }
    else
    {
        if (pregnancy_time.getDay() == current_date.getDay())
        {
            month = 12 + current_date.getMonth() - pregnancy_time.getMonth();
        }
        else if (pregnancy_time.getDay() < current_date.getDay())
        {
            month = 12 - pregnancy_time.getMonth() + current_date.getMonth();
        }
        else
        {
            month = 12 - pregnancy_time.getMonth() + current_date.getMonth() - 1;
        }
    }
    return month;
}
