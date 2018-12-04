/**
 * \file TownHall.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source TownHall.cpp
 * \date 2018-12-03
 */

#ifndef TOWN_HALL_HPP
#define TOWN_HALL_HPP
#include "Ground.hpp"

/**
 * \class TownHall
 * \brief Hotel de Ville (ou HdV) qui represente notre ville
 */
class TownHall : public Ground
{
  private:
    unsigned int level;         /*! Niveau de l'hotel de ville */
    unsigned int rock_number;   /*! Nombre de pierre dans l'HdV */
    unsigned int wood_number;   /*! Nombre de bois dans l'HdV */
    unsigned int food_number;   /*! Nombre de nourriture dans l'HdV */

  public:
    TownHall(const unsigned int level_town_hall = 0, const unsigned int rock_nb = 0, const unsigned int wood_nb = 0, const unsigned int food_nb = 0);

    unsigned int getLevel() const noexcept;
    unsigned int getRockNumber() const noexcept;
    unsigned int getWoodNumber() const noexcept;
    unsigned int getFoodNumber() const noexcept;

    void incrementLevel() noexcept;
    bool setRockNumber(const int) noexcept;
    bool setWoodNumber(const int) noexcept;
    bool setFoodNumber(const int) noexcept;

    void display(std::ostream &os = std::cout) const noexcept;
};
#endif
