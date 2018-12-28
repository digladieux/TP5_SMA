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
    int character_team;
    SEX character_gender;

  public:
    Character(const Date &);
    Character(SEX, const Date &);
    Character(const Character &);
    Character(unsigned int, const Date &, int, SEX);

    virtual ~Character();

    const Character &operator=(const Character &);
    unsigned int getCharacterId() const noexcept;
    Date getDateOfBirth() const noexcept;
    unsigned int getCharacterAge(const Date&) const ;
    int getCharacterTeam() const noexcept;
    SEX getCharacterGender() const noexcept;

    void setCharacterTeam(unsigned int) noexcept;

    bool isDead(const Date &) const noexcept;
};
#endif
