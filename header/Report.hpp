#ifndef REPORT_HPP
#define REPORT_HPP
#include <iostream>
class Report
{
private:
  static unsigned int counter;      /*! Compteur du nombre de rapport */
  unsigned int id;                  /*! Identifiant du rapport */
  unsigned int people_number_init;  /*! Nombre d'habitant d'une equipe */
  unsigned int death_number;/*! Nombre de mort */
  unsigned int birth_number;/*! Nombre de naissance */
  unsigned int level;       /*! Niveau de l'hotel de ville */
  unsigned int rock_number; /*! Nombre de pierre dans l'HdV */
  unsigned int wood_number; /*! Nombre de bois dans l'HdV */
  unsigned int food_number; /*! Nombre de nourriture dans l'HdV */
  unsigned int fish_number; /*! Nombre de poisson dans l'HdV */
  unsigned int team;

public:
  Report();
  Report(const Report&);
  ~Report();

  void incrementNumberOfDeath() noexcept;
  void incrementNumberOfBirth() noexcept;
  void setLevel(const unsigned int) noexcept;
  void setRockNumber(const unsigned int) noexcept;
  void setWoodNumber(const unsigned int) noexcept;
  void setFoodNumber(const unsigned int) noexcept;
  void setFishNumber(const unsigned int) noexcept;
  void setTeam(const unsigned int) noexcept;
  void setNumberOfCharacter(const unsigned int) noexcept;

  unsigned int getNumberOfDeath() const noexcept;
  unsigned int getNumberOfBirth() const noexcept;
  unsigned int getLevel() const noexcept;
  unsigned int getRockNumber() const noexcept;
  unsigned int getWoodNumber() const noexcept;
  unsigned int getFoodNumber() const noexcept;
  unsigned int getFishNumber() const noexcept;

  unsigned int getTeam() const noexcept;
  unsigned int getNumberOfCharacter() const noexcept;

  void display(std::ostream &os = std::cout) const noexcept;
  
};

#endif