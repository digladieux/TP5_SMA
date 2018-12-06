/**
 * \file TownHall.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation de l'hotel de ville
 * \date 2018-12-06
 */
#include "../header/TownHall.hpp"
#include <iostream>

/**
 * \brief Constructeur de la classe Town Hall
 * \param level_town_hall Niveau de l'hotel de ville
 * \param rock_nb Nombre de pierre dans le stock initial
 * \param wood_nb Nombre de bois dans le stock initial
 * \param food_nb Nombre de nouriture dans le stock initial
 */
TownHall::TownHall(const unsigned int level_town_hall, const unsigned int rock_nb, const unsigned int wood_nb, const unsigned int food_nb) :
Ground(GROUND_TYPE::TOWN_HALL), level(level_town_hall), rock_number(rock_nb), wood_number(wood_nb), food_number(food_nb) {}

/**
 * \fn unsigned int TownHall::getLevel() const noexcept
 * \brief Getteur sur le niveau de l'hotel de ville
 * \return Niveau de l'hotel de ville
 */
unsigned int TownHall::getLevel() const noexcept
{
    return level;
}

/**
 * \fn unsigned int TownHall::getRockNumber() const noexcept
 * \brief Getteur sur le nombre de pierre dans l'hotel de ville
 * \return Nombre de pierre dans l'hotel de ville
 */
unsigned int TownHall::getRockNumber() const noexcept
{
    return rock_number;
}

/**
 * \fn unsigned int TownHall::getWoodNumber() const noexcept
 * \brief Getteur sur le nombre de bois dans l'hotel de ville
 * \return Nombre de bois dans l'hotel de ville
 */
unsigned int TownHall::getWoodNumber() const noexcept
{
    return wood_number;
}

/**
 * \fn unsigned int TownHall::getFoodNumber() const noexcept
 * \brief Getteur sur le nombre de nourriture dans l'hotel de ville
 * \return Nombre de nourriture dans l'hotel de ville
 */
unsigned int TownHall::getFoodNumber() const noexcept
{
    return food_number;
}

/**
 * \fn void TownHall::incrementLevel() noexcept
 * \brief Incremente le niveau de l'hotel de ville de 1
 */
void TownHall::incrementLevel() noexcept
{
    level++;
}

/**
 * \fn bool TownHall::setRockNumber(const int rock_nb) noexcept
 * \brief Methode pour ajouter ou retirer des pierres dans l'hotel de ville
 * \param rock_nb Nombre de pierre que l'on souhaite enlever
 * \return Vrai si le nombre de pierre est au dessus de 0, faux sinon
 */
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

/**
 * \fn bool TownHall::setWoodNumber(const int rock_nb) noexcept
 * \brief Methode pour ajouter ou retirer du bois dans l'hotel de ville
 * \param rock_nb Nombre de bois que l'on souhaite enlever
 * \return Vrai si le nombre de bois est au dessus de 0, faux sinon
 */
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

/**
 * \fn bool TownHall::setFoodNumber(const int rock_nb) noexcept
 * \brief Methode pour ajouter ou retirer de la nourriture dans l'hotel de ville
 * \param rock_nb Nombre de nourriture que l'on souhaite enlever
 * \return Vrai si le nombre de nourriture est au dessus de 0, faux sinon
 */
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

/**
 * \fn void TownHall::display(std::ostream &os) const noexcept
 * \brief Affichage d'un hotel de ville
 * \param os Flux ou l'on va afficher l'hotel de ville
 */
void TownHall::display(std::ostream& os) const noexcept
{
    os << "T ";
}
