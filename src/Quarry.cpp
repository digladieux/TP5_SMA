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

/**
 * \fn Quarry::Quarry(const Quarry &quarry) 
 * \brief Constructeur de copie de la classe Quarry
 * \param &quarry Carriere que l'on veut copier
 */
Quarry::Quarry(const Quarry &quarry) : CollectionPoint(GROUND_TYPE::QUARRY, quarry.ressources_number, quarry.ground_id, quarry.vector_character) {}

/**
 * \fn Quarry::Quarry(const Ground &quarry, const unsigned int ressources_number)
 * \brief Constructeur de copie de la classe Quarry avec sa classe mere en parametre
 * \param &quarry Copie du terrain que l'on veut faire
 * \param ressources_number Nombre de ressource sur ce terrain
 */
Quarry::Quarry(const Ground &quarry, const unsigned int ressources_number) : CollectionPoint(quarry, GROUND_TYPE::QUARRY, ressources_number) {}
/**
 * \fn Quarry::~Quarry()
 * \brief Destructeur de la classe Quarry
 *
 */
Quarry::~Quarry() {}

/**
 * \fn Quarry* Quarry::clone() const
 * \brief Constructeur dynamique de la classe Quarry. C'est un moyen de construire un constructeur virtuel. Quand on ne connait pas le type de CollectionPoint que l'on a et que l'on veut faire une copie de ce dernier, on utilise cette methode
 */
Quarry* Quarry::clone() const
{
    return new Quarry(*this);
}

/**
 * \fn void Quarry::display(std::ostream &os) const noexcept
 * \brief Affichage d'une carriere
 * \param os Flux ou l'on va afficher la carriere
 */
void Quarry::display(std::ostream &os) const noexcept
{
    os << CYAN "Q " << RESET;
}
