/**
 * \file TownHall.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation de l'hotel de ville
 * \date 2018-12-06
 */
#include "../header/TownHall.hpp"
#include "../header/Color.hpp"
#include "../header/Ground.hpp"
#include <iostream>

/**
 * \brief Constructeur de la classe Town Hall
 * \param level_town_hall Niveau de l'hotel de ville
 * \param rock_nb Nombre de pierre dans le stock initial
 * \param wood_nb Nombre de bois dans le stock initial
 * \param food_nb Nombre de nouriture dans le stock initial
 */
TownHall::TownHall(const unsigned int level_town_hall, const unsigned int rock_nb, const unsigned int wood_nb, const unsigned int food_nb, const unsigned int fish_nb) : Ground(GROUND_TYPE::TOWN_HALL), level(level_town_hall), rock_number(rock_nb), wood_number(wood_nb), food_number(food_nb), fish_number(fish_nb) {}

TownHall::TownHall(const TownHall &town_hall) : Ground(GROUND_TYPE::TOWN_HALL, town_hall.ground_id, town_hall.vector_character), level(town_hall.level), rock_number(town_hall.rock_number), wood_number(town_hall.wood_number), food_number(town_hall.food_number), fish_number(town_hall.fish_number) { town_hall.vector_character[0]; }
TownHall::~TownHall(){}
TownHall* TownHall::clone() const
{
    return new TownHall(*this);
}

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
 * \fn unsigned int TownHall::getFishNumber() const noexcept
 * \brief Getteur sur le nombre de poisson dans l'hotel de ville
 * \return Nombre de poisson dans l'hotel de ville
 */
unsigned int TownHall::getFishNumber() const noexcept
{
    return fish_number;
}

/**
 * \fn void TownHall::incrementLevel() noexcept
 * \brief Incremente le niveau de l'hotel de ville de 1
 */
void TownHall::incrementLevel() noexcept
{
    level++;
}

bool TownHall::addRessources(TYPE_RESSOURCE_TRANSPORTED type, const int ressource_number)
{
    bool flag = true;
    if (ressource_number < 0)
    {
        flag = false;
    }
    else
    {
        switch (type)
        {
        case TYPE_RESSOURCE_TRANSPORTED::FISH:
            fish_number += ressource_number;
            break;
        case TYPE_RESSOURCE_TRANSPORTED::WOOD:
            wood_number += ressource_number;
            break;
        case TYPE_RESSOURCE_TRANSPORTED::FOOD:
            food_number += ressource_number;
            break;
        case TYPE_RESSOURCE_TRANSPORTED::ROCK:
            rock_number += ressource_number;
            break;
        default:
            break;
        }
    }
    return flag;
}

/**
 * \fn bool TownHall::removeRockNumber(const int rock_nb) noexcept
 * \brief Methode pour retirer de la pierre dans l'hotel de ville
 * \param rock_nb Nombre de pierre que l'on souhaite enlever
 * \return Vrai si le nombre de pierre est superieur à 0, faux sinon
 */
bool TownHall::removeRockNumber(const int rock_nb) noexcept
{
    bool flag = true;
    if ((int)rock_number < rock_nb)
    {
        flag = false;
    }
    else
    {
        rock_number -= rock_nb;
    }
    return flag;
}

/**
 * \fn bool TownHall::removeWoodNumber(const int wood_nb) noexcept
 * \brief Methode pour retirer de la bois dans l'hotel de ville
 * \param wood_nb Nombre de bois que l'on souhaite enlever
 * \return Vrai si le nombre de bois est superieur à 0, faux sinon
 */
bool TownHall::removeWoodNumber(const int wood_nb) noexcept
{
    bool flag = true;
    if ((int)wood_number < wood_nb)
    {
        flag = false;
    }
    else
    {
        wood_number -= wood_nb;
    }
    return flag;
}

/**
 * \fn bool TownHall::removeFoodNumber(const int food_nb) noexcept
 * \brief Methode pour retirer de la nouriture dans l'hotel de ville
 * \param food_nb Nombre de nouriture que l'on souhaite enlever
 * \return Vrai si le nombre de nouriture est superieur à 0, faux sinon
 */
bool TownHall::removeFoodNumber(const int food_nb) noexcept
{
    bool flag = true;
    if ((int)food_number < food_nb)
    {
        flag = false;
    }
    else
    {
        food_number -= food_nb;
    }
    return flag;
}

/**
 * \fn bool TownHall::removeFishNumber(const int fish_nb) noexcept
 * \brief Methode pour retirer de la poisson dans l'hotel de ville
 * \param fish_nb Nombre de poisson que l'on souhaite enlever
 * \return Vrai si le nombre de poisson est superieur à 0, faux sinon
 */
bool TownHall::removeFishNumber(const int fish_nb) noexcept
{
    bool flag = true;
    if ((int)fish_number < fish_nb)
    {
        flag = false;
    }
    else
    {
        fish_number -= fish_nb;
    }
    return flag;
}

GROUND_TYPE TownHall::lowStock() const noexcept
{
    GROUND_TYPE ground_type;
    if ((fish_number <= wood_number) && (fish_number <= rock_number) && (fish_number <= food_number))
    {
        ground_type = GROUND_TYPE::LAKE;
    }
    else if ((food_number <= rock_number) && (food_number <= fish_number) && (food_number <= wood_number))
    {
        ground_type = GROUND_TYPE::FARM;
    }
    else if ((rock_number <= wood_number) && (rock_number <= fish_number) && (rock_number <= food_number))
    {
        ground_type = GROUND_TYPE::QUARRY;
    }
    else
    {
        ground_type = GROUND_TYPE::FOREST;
    }
    return ground_type;
}

/**
 * \fn void TownHall::display(std::ostream &os) const noexcept
 * \brief Affichage d'un hotel de ville
 * \param os Flux ou l'on va afficher l'hotel de ville
 */
void TownHall::display(std::ostream &os) const noexcept
{
    if (ground_id == 0)
    {
        os << BOLDRED << "T " << RESET;
    }
    else
    {
        os << BOLDMAGENTA << "T " << RESET;
    }
}

void TownHall::displayRessources(std::ostream &os) const noexcept
{
    os << std::endl;
    if (ground_id == 0)
    {
        os << BOLDRED << "TownHall 0" << RESET << "\tlevel: " << level << std::endl;
        
    }
    else
    {
        os << BOLDMAGENTA << "TownHall 1" << RESET << "\tlevel: " << level << std::endl;    
    }
    os << "Wood " << wood_number << "\tRock " << rock_number << std::endl;
    os << "Fish " << fish_number << "\tFood " << food_number << std::endl;
}
