/**
 * \file Farm.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation d'une ferme
 * \date 2018-12-06
 */

#include "../header/Farm.hpp"
#include <iostream>

/**
 * \fn Farm::Farm(const unsigned int food_number)
 * \brief Constructeur de la classe Farm
 * \param food_number Nombre de nourriture
 */
Farm::Farm(const unsigned int food_number) : CollectionPoint(GROUND_TYPE::FARM, food_number) {}

Farm::Farm(const Farm &farm) : CollectionPoint(GROUND_TYPE::FARM, farm.ressources_number, farm.ground_id, farm.vector_character) {}

/**
 * \fn Farm::~Farm()
 * \brief Destructeur de la classe Farm
 *
 */
Farm::~Farm() {}

/**
 * \fn void Farm::display(std::ostream &os) const noexcept
 * \brief Affichage d'une ferme
 * \param os Flux ou l'on va afficher la ferme
 */
void Farm::display(std::ostream &os) const noexcept
{
    os << "f ";
}
