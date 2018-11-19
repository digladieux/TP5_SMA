#ifndef TOWN_HALL_HPP
#define TOWN_HALL_HPP
#include "Ground.hpp"

class TownHall : public Ground
{
  private:
    unsigned int level;
    unsigned int rock_number;
    unsigned int wood_number;
    unsigned int food_number;

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
};
#endif
