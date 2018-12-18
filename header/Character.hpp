/**
 * \file Character.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source Character.cpp
 * \date 2018-12-03
 */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "../header/Date.hpp"
/**
 * \enum class SEX
 * \brief Enumeration qui definit la majorite d'un personnage, ainsi que son sexe
 *
 */
enum class SEX
{
    MALE,
    FEMALE
};

/**
 * \class Character
 * \brief Personnage qui represente notre agent
 */
class Character
{
  protected:
    static unsigned int character_number;
    unsigned int character_id;
    Date character_age;
    int character_team;
    SEX character_gender;

  public:
    Character(const Date &);
    Character(SEX, const Date &);
    virtual ~Character();

    const Character &operator=(const Character &);
    unsigned int getCharacterId() const noexcept;
    Date getCharacterAge() const noexcept;
    int getCharacterTeam() const noexcept;
    SEX getCharacterGender() const noexcept;

    void setCharacterTeam(unsigned int) noexcept;

    void incrementAge() noexcept;
    bool isDead(const Date &) const noexcept;
};
#endif
