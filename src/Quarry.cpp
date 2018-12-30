/**
 * \file Quarry.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation d'une carriere
 * \date 2018-12-06
 */

#include "../header/Quarry.hpp"
#include "../header/Color.hpp"
#include <iostream>

/**
 * \fn Quarry::Quarry(const unsigned int wood_number)
 * \brief Constructeur de la classe Quarry
 * \param wood_number Nombre de pierre
 */
Quarry::Quarry(const unsigned int rock_number) : CollectionPoint(GROUND_TYPE::QUARRY, rock_number) {}

Quarry::Quarry(const Quarry &quarry) : CollectionPoint(GROUND_TYPE::QUARRY, quarry.ressources_number, quarry.ground_id, quarry.vector_character) {}
/**
 * \fn Quarry::~Quarry()
 * \brief Destructeur de la classe Quarry
 *
 */
Quarry::~Quarry() {}

/**
 * \fn void Quarry::display(std::ostream &os) const noexcept
 * \brief Affichage d'une carriere
 * \param os Flux ou l'on va afficher la carriere
 */
void Quarry::display(std::ostream &os) const noexcept
{
    os << CYAN "Q " << RESET;
}
