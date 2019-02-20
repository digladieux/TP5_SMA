/**
 * \file Farm.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation d'une ferme
 * \date 2018-12-06
 */

#include "../header/Farm.hpp"
#include <iostream>
#include "../header/Color.hpp"

/**
 * \fn Farm::Farm(const unsigned int food_number)
 * \brief Constructeur de la classe Farm
 * \param food_number Nombre de nourriture
 */
Farm::Farm(const unsigned int food_number) : CollectionPoint(GROUND_TYPE::FARM, food_number) {}

/**
 * \fn Farm::Farm(const Farm &farm) 
 * \brief Constructeur de copie de la classe Farm
 * \param farm Ferme que l'on veut copier
 */
Farm::Farm(const Farm &farm) : CollectionPoint(GROUND_TYPE::FARM, farm.ressources_number, farm.ground_id, farm.vector_character) {}

/**
 * \fn Farm::Farm(const Ground &farm, const unsigned int ressources_number)
 * \brief Constructeur de copie de la classe Farm avec sa classe mere en parametre
 * \param &farm Copie du terrain que l'on veut faire
 * \param ressources_number Nombre de ressource sur ce terrain
 */
Farm::Farm(const Ground &farm, const unsigned int ressources_number) : CollectionPoint(farm, GROUND_TYPE::FARM, ressources_number) {}

/**
 * \fn Farm::~Farm()
 * \brief Destructeur de la classe Farm
 *
 */
Farm::~Farm() {}

/**
 * \fn Farm* Farm::clone() const
 * \brief Constructeur dynamique de la classe Farm. C'est un moyen de construire un constructeur virtuel. Quand on ne connait pas le type de CollectionPoint que l'on a et que l'on veut faire une copie de ce dernier, on utilise cette methode
 */
Farm* Farm::clone() const
{
    return new Farm(*this);
}
/**
 * \fn void Farm::display(std::ostream &os) const noexcept
 * \brief Affichage d'une ferme
 * \param os Flux ou l'on va afficher la ferme
 */
void Farm::display(std::ostream &os) const noexcept
{
    os << YELLOW << "f " << RESET;
}
