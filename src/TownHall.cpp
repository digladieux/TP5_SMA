#include "../header/TownHall.hpp"

TownHall::TownHall(const unsigned int level_town_hall, const unsigned int rock_nb, const unsigned int wood_nb, const unsigned int food_nb) : level(level_town_hall), rock_number(rock_nb), wood_number(wood_nb), food_number(food_nb) {}

unsigned int TownHall::getLevel() const noexcept
{
    return level;
}

unsigned int TownHall::getRockNumber() const noexcept
{
    return rock_number;
}

unsigned int TownHall::getWoodNumber() const noexcept
{
    return wood_number;
}

unsigned int TownHall::getFoodNumber() const noexcept
{
    return food_number;
}

void TownHall::incrementLevel() noexcept
{
    level++;
}

bool TownHall::setRockNumber(const int rock_nb) noexcept
{
    bool flag = true;
    if ((int)rock_number + rock_nb < 0)
    {
        flag = false;
    }
    else
    {
        rock_number += rock_nb;
    }
    return flag;
}

bool TownHall::setWoodNumber(const int wood_nb) noexcept
{
    bool flag = true;
    if ((int)wood_number + wood_nb < 0)
    {
        flag = false;
    }
    else
    {
        wood_number += wood_nb;
    }
    return flag;
}

bool TownHall::setFoodNumber(const int food_nb) noexcept
{
    bool flag = true;
    if ((int)food_number + food_nb < 0)
    {
        flag = false;
    }
    else
    {
        food_number += food_nb;
    }
    return flag;
}
