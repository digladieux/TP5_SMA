/**
 * \file Character.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source Character.cpp
 * \date 2018-12-03
 */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

/**
 * \enum class SEX
 * \brief Enumeration qui definit la majorite d'un personnage, ainsi que son sexe
 *
 */
enum class SEX
{
  MALE_CHARACTER_ADULT,   /*! Adulte Masculin */
  FEMALE_CHARACTER_ADULT, /*! Adulte Feminin */
  MALE_CHARACTER_CHILD,   /*! Enfant Masculin */
  FEMALE_CHARACTER_CHILD  /*! Enfant Feminin */
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
  unsigned int character_age;
  int character_team;
  SEX character_gender;

public:
  Character();
  Character(SEX, const unsigned int age = 0);
  virtual ~Character();

  const Character &operator=(const Character &);
  unsigned int getCharacterId() const noexcept;
  unsigned int getCharacterAge() const noexcept;
  int getCharacterTeam() const noexcept;
  SEX getCharacterGender() const noexcept;

  void setCharacterGenderAdult() noexcept;
  void setCharacterTeam(unsigned int) noexcept;

  void incrementAge() noexcept;
  bool isDead() const noexcept;
};
#endif
