/**
 * \file Lake.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation d'un lac
 * \date 2018-12-06
 */

#include "../header/Lake.hpp"
#include <iostream>
#include "../header/Color.hpp"
/**
 * \fn Lake::Lake(const unsigned int fish_number)
 * \brief Constructeur de la classe Lake
 * \param fish_number Nombre de poisson
 */
Lake::Lake(const unsigned int fish_number) : CollectionPoint(GROUND_TYPE::LAKE, fish_number) {}

Lake::Lake(const Lake &lake) : CollectionPoint(GROUND_TYPE::LAKE, lake.ressources_number, lake.ground_id, lake.vector_character) {}
Lake::Lake(const Ground &lake, const unsigned int ressources_number) : CollectionPoint(lake, GROUND_TYPE::LAKE, ressources_number) {}
/**
 * \fn Lake::~Lake()
 * \brief Destructeur de la classe Lake
 *
 */
Lake::~Lake() {}

Lake* Lake::clone() const
{
    return new Lake(*this);
}
/**
 * \fn void Lake::display(std::ostream &os) const noexcept
 * \brief Affichage d'un lac
 * \param os Flux ou l'on va afficher le lac
 */
void Lake::display(std::ostream &os) const noexcept
{
    os << BLUE << "L " << RESET;
}
