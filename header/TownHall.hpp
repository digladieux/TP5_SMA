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
    unsigned int level;       /*! Niveau de l'hotel de ville */
    unsigned int rock_number; /*! Nombre de pierre dans l'HdV */
    unsigned int wood_number; /*! Nombre de bois dans l'HdV */
    unsigned int food_number; /*! Nombre de nourriture dans l'HdV */
    unsigned int fish_number; /*! Nombre de poisson dans l'HdV */

  public:
    TownHall(const unsigned int level_town_hall = 0, const unsigned int rock_nb = 0, const unsigned int wood_nb = 0, const unsigned int food_nb = 0, const unsigned int fish_nb = 0);
    TownHall(const TownHall &);

    unsigned int getLevel() const noexcept;
    unsigned int getRockNumber() const noexcept;
    unsigned int getWoodNumber() const noexcept;
    unsigned int getFoodNumber() const noexcept;
    unsigned int getFishNumber() const noexcept;

    void incrementLevel() noexcept;
    /* a mettre en prive apres */

    bool addRessources(TYPE_RESSOURCE_TRANSPORTED, const int);

    bool removeRockNumber(const int) noexcept;
    bool removeWoodNumber(const int) noexcept;
    bool removeFoodNumber(const int) noexcept;
    bool removeFishNumber(const int) noexcept;

    GROUND_TYPE lowStock() const noexcept;

    void display(std::ostream &os = std::cout) const noexcept;
    void displayRessources(std::ostream &os) const noexcept;
};
#endif
