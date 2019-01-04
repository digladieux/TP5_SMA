/**
 * \file FemaleCharacter.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source FemaleCharacter.cpp
 * \date 2018-12-03
 */

#ifndef FEMALE_CHARACTER_HPP
#define FEMALE_CHARACTER_HPP

#include "Character.hpp"
#include "Date.hpp"

/**
 * \class FemaleCharacter
 * \brief Un personnage feminin herite des attributs et methodes d'un personnage. Le but d'un personnage feminin est de donner naissance a des enfants
 */
class FemaleCharacter : public Character
{
private:
  unsigned int baby_per_pregnancy; /*! Nombre de bebe par couche */
  Date pregnancy_time;             /*! Nombre de mois avant la couche */

public:
  FemaleCharacter(const Date &);
  FemaleCharacter(const FemaleCharacter &);
  ~FemaleCharacter();

  unsigned int getBabyPerPregnancy() const noexcept;
  Date getPregnancyTime() const noexcept;

  void randomBabyPerPregnancy() noexcept;
  void setTimePregnancy(const Date &date) noexcept;
  unsigned int getMonthPregnancy(const Date &) const;
};
#endif
