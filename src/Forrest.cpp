/**
 * \file Forest.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation d'une foret
 * \date 2018-12-06
 */

#include "../header/Forest.hpp"
#include <iostream>

/**
 * \fn Forest::Forest(const unsigned int wood_number)
 * \brief Constructeur de la classe Foret
 * \param wood_number Nombre de bois
 */
Forest::Forest(const unsigned int wood_number) : CollectionPoint(GROUND_TYPE::FOREST, wood_number) {}

Forest::Forest(const Forest& forest) : CollectionPoint(GROUND_TYPE::FOREST, forest.ressources_number, forest.ground_id, forest.vector_character){}
/**
 * \fn Forest::~Forest()
 * \brief Destructeur de la classe Foret
 *
 */
Forest::~Forest() {}

/**
 * \fn void Forest::display(std::ostream &os) const noexcept
 * \brief Affichage d'une foret
 * \param os Flux ou l'on va afficher la foret
 */
void Forest::display(std::ostream &os) const noexcept
{
    os << "F ";
}
