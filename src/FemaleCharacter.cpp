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

/**
 * \fn FemaleCharacter::FemaleCharacter(const FemaleCharacter &character)
 * \brief Constructeur de copie de la classe Female Character
 * \param &character Personnage Feminin que l'on veut copie
 */
FemaleCharacter::FemaleCharacter(const FemaleCharacter &character) : Character(character.character_id, character.character_date_of_birth, character.character_team, character.character_gender, character.character_life, character.character_current_life), baby_per_pregnancy(character.baby_per_pregnancy), pregnancy_time(character.pregnancy_time), menopause(character.menopause) {}

/**
 * \fn FemaleCharacter::FemaleCharacter(const Date &age, unsigned int team)
 * \brief Constructeur de la classe Female Character
 * \param &age Date de naissance du personnage
 * \param team Equipe du personnage
 */
FemaleCharacter::FemaleCharacter(const Date &age, unsigned int team) : Character(SEX::FEMALE, age, team), baby_per_pregnancy(genrand_int31() % (unsigned int)Constantes::CONFIG_SIMU["maxBaby"]), pregnancy_time(Date())
{
    unsigned int menopause_min = Constantes::CONFIG_SIMU["menopauseMin"];
    unsigned int menopause_max = Constantes::CONFIG_SIMU["menopauseMax"];
    menopause = genrand_int31() % (menopause_max - menopause_min) + menopause_min;
    menopause += (unsigned int)Constantes::CONFIG_SIMU["menopauseMin"];
}

/**
 * \fn FemaleCharacter::FemaleCharacter(const Date &age, unsigned int number_of_baby, unsigned int age_of_menopause, unsigned int team, unsigned int life)
 * \brief Constructeur de la classe Female Character
 * \param &age Date de naissance du personnage
 * \param number_of_baby Nombre d'enfant par femme
 * \param age_of_menopause Age maximale que la femme peut faire des enfant
 * \param team Equipe du personnage
 * \param life Vie maximale sur personnage
 */
FemaleCharacter::FemaleCharacter(const Date &age, unsigned int number_of_baby, unsigned int age_of_menopause, unsigned int team, unsigned int life) : Character(SEX::FEMALE, age, team, life), baby_per_pregnancy(number_of_baby), pregnancy_time(Date()), menopause(age_of_menopause)
{
}

/**
 * \fn FemaleCharacter::~FemaleCharacter()
 * \brief Destructeur de la classe Female Character
 */
FemaleCharacter::~FemaleCharacter() {}
FemaleCharacter &FemaleCharacter::operator=(const FemaleCharacter &new_character)
{
    if (this != &new_character) /* On verifie que le personnage n'est pas le meme que l'on veut copier */
    {
        Character::operator=(new_character);
        baby_per_pregnancy = new_character.baby_per_pregnancy;
        pregnancy_time = new_character.pregnancy_time;
        menopause = new_character.menopause;
    }
    return *this;
}
/**
 * \fn unsigned int FemaleCharacter::getBabyPerPregnancy() const noexcept
 * \brief Getteur sur le nombre d'enfant par grossesse
 * \return Nombre d'enfant par grossesse
 */
unsigned int FemaleCharacter::getBabyPerPregnancy() const noexcept
{
    return baby_per_pregnancy;
}

/**
 * \fn Date FemaleCharacter::getPregnancyTime() const noexcept
 * \brief Getteur sur le debut de la grossesse
 * \return Debut de la grossesse
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

/**
 * \fn void FemaleCharacter::setTimePregnancy(const Date &date) noexcept
 * \brief Setteur sur le debut de la grossesse
 * \param &date Date de debut de la grossesse
 */
void FemaleCharacter::setTimePregnancy(const Date &date) noexcept
{
    pregnancy_time = date;
}

/**
 * \fn unsigned int FemaleCharacter::getMonthPregnancy(const Date &current_date) const
 * \brief Getteur sur le nombre de mois de grossesse
 * \param &current_date Date actuelle
 */
unsigned int FemaleCharacter::getMonthPregnancy(const Date &current_date) const
{
    unsigned int month = 0;
    if ((!(character_date_of_birth < current_date)) && !(current_date == pregnancy_time))
    {
        throw CurrentDateBeforeBirthException(current_date, character_date_of_birth);
    }
    if (!(current_date == pregnancy_time))
    {
        if (current_date.getMonth() >= pregnancy_time.getMonth())
        {
            month += ( current_date.getYear() - pregnancy_time.getYear() ) * 12 ;
            if (current_date.getDay() >= pregnancy_time.getDay())
            {
                month += current_date.getMonth() - pregnancy_time.getMonth() ;
            }
            else
            {
                month += current_date.getMonth() - pregnancy_time.getMonth() - 1 ;
            }
        }
        else
        {
            month += ( current_date.getYear() - pregnancy_time.getYear() - 1 ) * 12 ;
            if (current_date.getDay() >= pregnancy_time.getDay())
            {
                month += 12 + current_date.getMonth() - pregnancy_time.getMonth() ;
            }
            else
            {
                month += 12 + current_date.getMonth() - pregnancy_time.getMonth() - 1 ;
            }
        }

        
    }

    return month ;
}

/**
 * \fn unsigned int FemaleCharacter::getMenopause() const noexcept
 * \brief Getteur sur l'age (en annee) a la date ou la femme a la menopause
 * 
 */
unsigned int FemaleCharacter::getMenopause() const noexcept
{
    return menopause ;
}