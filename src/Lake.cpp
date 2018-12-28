/**
 * \file Lake.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation d'un lac
 * \date 2018-12-06
 */

#include "../header/Lake.hpp"
#include <iostream>

/**
 * \fn Lake::Lake(const unsigned int fish_number)
 * \brief Constructeur de la classe Lake
 * \param fish_number Nombre de poisson
 */
Lake::Lake(const unsigned int fish_number) : CollectionPoint(GROUND_TYPE::LAKE, fish_number) {}

Lake::Lake(const Lake &lake) : CollectionPoint(GROUND_TYPE::LAKE, lake.ressources_number, lake.ground_id, lake.vector_character) {}
/**
 * \fn Lake::~Lake()
 * \brief Destructeur de la classe Lake
 *
 */
Lake::~Lake() {}

/**
 * \fn void Lake::display(std::ostream &os) const noexcept
 * \brief Affichage d'un lac
 * \param os Flux ou l'on va afficher le lac
 */
void Lake::display(std::ostream &os) const noexcept
{
    os << "L ";
}
