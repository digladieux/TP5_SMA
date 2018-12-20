/**
 * \file FemaleCharacter.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source FemaleCharacter.cpp
 * \date 2018-12-03
 */

#ifndef FEMALE_CHARACTER_HPP
#define FEMALE_CHARACTER_HPP

#include "Character.hpp"

/**
 * \class FemaleCharacter
 * \brief Un personnage feminin herite des attributs et methodes d'un personnage. Le but d'un personnage feminin est de donner naissance a des enfants
 */
class FemaleCharacter : public Character
{
  private:
    unsigned int baby_per_pregnancy;     /*! Nombre de bebe par couche */
    unsigned int month_number_pregnancy; /*! Nombre de mois avant la couche */

  public:
    FemaleCharacter(const Date &);
    FemaleCharacter(const FemaleCharacter&);
    ~FemaleCharacter();

    unsigned int getBabyPerPregnancy() const noexcept;
    unsigned int getMonthNumberPregnancy() const noexcept;

    void randomBabyPerPregnancy() noexcept;
    void setMonthPregnancy() noexcept;
};
#endif
