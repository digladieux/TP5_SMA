/**
 * \file Character.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source Character.cpp
 * \date 2018-12-03
 */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Date.hpp"
#include "Enum.hpp"

/**
 * \class Character
 * \brief Personnage qui represente notre agent
 */
class Character
{
protected:
  static unsigned int character_number;
  unsigned int character_id;
  Date character_date_of_birth;
  unsigned int character_team;
  SEX character_gender;
  unsigned int character_life ;
  int character_current_life ;

public:
  Character(const Date &, unsigned int team = 0);
  Character(SEX, const Date &, unsigned int team = 0, unsigned int life = 200);
  Character(const Character &);
  Character(unsigned int, const Date &, int, SEX, unsigned int, unsigned int);

  virtual ~Character();

  const Character &operator=(const Character &);
  unsigned int getCharacterId() const noexcept;
  Date getDateOfBirth() const noexcept;
  unsigned int getCharacterAge(const Date &) const;
  unsigned int getCharacterTeam() const noexcept;
  SEX getCharacterGender() const noexcept;
  int getCharacterCurrentLife() const noexcept;
  bool decrementCharacterLife() noexcept;
  void giveCharacterLife(unsigned int) noexcept;
  void setCharacterTeam(unsigned int) noexcept;
  
  bool isDead(const Date &) const noexcept;
};
#endif
