/**
 * \file Forest.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation d'une foret
 * \date 2018-12-06
 */

#include "../header/Forest.hpp"
#include <iostream>
#include "../header/Color.hpp"


/**
 * \fn Forest::Forest(const unsigned int wood_number)
 * \brief Constructeur de la classe Foret
 * \param wood_number Nombre de bois
 */
Forest::Forest(const unsigned int wood_number) : CollectionPoint(GROUND_TYPE::FOREST, wood_number) {}
    
Forest::Forest(const Forest& forest) : CollectionPoint(GROUND_TYPE::FOREST, forest.ressources_number, forest.ground_id, forest.vector_character){}
Forest::Forest(const Ground& forest, const unsigned int ressources_number) : CollectionPoint(forest, GROUND_TYPE::FOREST, ressources_number){}
/**
 * \fn Forest::~Forest()
 * \brief Destructeur de la classe Foret
 *
 */
Forest::~Forest() {}
Forest* Forest::clone() const
{
    return new Forest(*this);
}
/**
 * \fn void Forest::display(std::ostream &os) const noexcept
 * \brief Affichage d'une foret
 * \param os Flux ou l'on va afficher la foret
 */
void Forest::display(std::ostream &os) const noexcept
{
    os << GREEN << "F " << RESET;
}
