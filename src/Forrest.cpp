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

/**
 * \fn Forest::Forest(const Forest &forest) 
 * \brief Constructeur de copie de la classe Forest
 * \param forest Foret que l'on veut copier
 */
Forest::Forest(const Forest& forest) : CollectionPoint(GROUND_TYPE::FOREST, forest.ressources_number, forest.ground_id, forest.vector_character){}

/**
 * \fn Forest::Forest(const Ground &forest, const unsigned int ressources_number)
 * \brief Constructeur de copie de la classe Forest avec sa classe mere en parametre
 * \param &forest Copie du terrain que l'on veut faire
 * \param ressources_number Nombre de ressource sur ce terrain
 */
Forest::Forest(const Ground& forest, const unsigned int ressources_number) : CollectionPoint(forest, GROUND_TYPE::FOREST, ressources_number){}
/**
 * \fn Forest::~Forest()
 * \brief Destructeur de la classe Foret
 *
 */
Forest::~Forest() {}

/**
 * \fn Forest* Forest::clone() const
 * \brief Constructeur dynamique de la classe Forest. C'est un moyen de construire un constructeur virtuel. Quand on ne connait pas le type de CollectionPoint que l'on a et que l'on veut faire une copie de ce dernier, on utilise cette methode
 */
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
