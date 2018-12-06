/**
 * \file FemaleCharacter.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation d'un personnage feminin
 * \date 2018-12-06
 */

#include "../header/FemaleCharacter.hpp"
#include "../header/mt19937ar.h"

/**
 * \fn FemaleCharacter::FemaleCharacter()
 * \brief Constructeur par default de la classe Female Character
 */
FemaleCharacter::FemaleCharacter() : /* RAND : CARACTERE ALEATOIRE MODIFIABLE */
                                     Character(SEX::FEMALE_CHARACTER_CHILD), baby_per_pregnancy((genrand_int31() % 1) + 1), month_number_pregnancy(0)
{
}

/**
 * \fn FemaleCharacter::FemaleCharacter(SEX gender, const unsigned int age)
 * \brief Constructeur de la classe Female Character
 * \param gender Majorite du personnage feminin
 * \param age Age du personnage feminin
 */
FemaleCharacter::FemaleCharacter(SEX gender, const unsigned int age) : /* RAND : CARACTERE ALEATOIRE MODIFIABLE */
                                                                       Character(gender, age), baby_per_pregnancy((genrand_int31() % 1) + 1), month_number_pregnancy(0)
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
 * \fn unsigned int FemaleCharacter::getMonthNumberPregnancy() const noexcept
 * \brief Getteur sur le numero du mois de la grossesse
 * \return Nombre de mois de grossesse
 */
unsigned int FemaleCharacter::getMonthNumberPregnancy() const noexcept
{
    return month_number_pregnancy;
}

/**
 * \fn void FemaleCharacter::randomBabyPerPregnancy() noexcept
 * \brief Affecte un nombre aleatoire sur nombre de bebe par grossesse
 */
void FemaleCharacter::randomBabyPerPregnancy() noexcept
{
    /* RAND : CARACTERE ALEATOIRE MODIFIABLE */
    baby_per_pregnancy = genrand_int31() % 1 + 1;
}

/**
 * \fn void FemaleCharacter::setMonthPregnancy() noexcept
 * \brief Incremente le nombre de mois de grossesse ou bien le met a 0 si on a atteind les 9 mois
 */
void FemaleCharacter::setMonthPregnancy() noexcept
{
    if (month_number_pregnancy == 9)
    {
        month_number_pregnancy = 0;
    }
    else
    {
        month_number_pregnancy++;
    }
}
