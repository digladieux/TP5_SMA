/**
 * \file CollectionPoint.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation d'un point de collecte
 * \date 2018-12-03
 */

#include "../header/CollectionPoint.hpp"
#include "../header/Constantes.hpp"
#include "../header/mt19937ar.h"
#include <iostream>
#include <exception>

/**
 * \fn CollectionPoint::CollectionPoint(GROUND_TYPE type, const unsigned int ressources_nb)
 * \brief Constructeur de la classe Collection Point
 * \param type Type de terrain (Carriere, Foret, etc..)
 * \param ressources_nb Nombre de ressource sur ce terrain
 */
CollectionPoint::CollectionPoint(GROUND_TYPE type, const unsigned int ressources_nb) : Ground(type), ressources_number(ressources_nb) {}

CollectionPoint::CollectionPoint(GROUND_TYPE type, const unsigned int ressources_nb, unsigned int id, std::vector<Character *> vector) : Ground(type, id, vector), ressources_number(ressources_nb) {}

/**
 * \fn CollectionPoint::~CollectionPoint()
 * \brief Destructeur de la classe Collection Point
 */
CollectionPoint::~CollectionPoint() {}

/**
 * \fn unsigned int CollectionPoint::getRessourcesNumber() const noexcept
 * \brief Getteur sur le nombre de ressource
 * \return unsigned int
 */
unsigned int CollectionPoint::getRessourcesNumber() const noexcept
{
    return ressources_number;
}

/**
 * \fn void CollectionPoint::setRessources(const unsigned int new_ressources_number)
 * \brief Setteur sur le nombre de ressource
 * \new_ressources_number Nouveau nombre de ressource
 */
void CollectionPoint::setRessources(const unsigned int new_ressources_number)
{
    ressources_number = new_ressources_number;
}

/**
 * \fn bool CollectionPoint::ressourcesNumberExtracted(const unsigned int ressources_number_extracted)
 * \brief Decremente de x le nombre de ressource sur un point de collecte
 * \param ressources_number_extracted Nombre de ressource que l'on veut extraire
 * \return Vrai si on a pu extraire le nombre de ressource, faux sinon
 */
bool CollectionPoint::ressourcesNumberExtracted(const unsigned int ressources_number_extracted)
{
    bool flag = true;
    if ((int)ressources_number - (int)ressources_number_extracted < 0)
    {
        flag = false;
    }
    else
    {
        ressources_number -= ressources_number_extracted;
    }
    return flag;
}

/**
 * \fn void CollectionPoint::evolutionRessources() noexcept
 * \brief Ajout de ressource dans un point de collecte
 */
void CollectionPoint::evolutionRessources() noexcept
{
    double evolution = genrand_real1();
    double ressources_nb = genrand_int31() %(int) Constantes::CONFIG_SIMU["maxRessourceEvolution"];

    if (evolution < (int) Constantes::CONFIG_SIMU["chanceEvolution"])
    {
        ressources_number += ressources_nb;
    }
}

/**
 * \fn void CollectionPoint::display(std::ostream &os) const noexcept
 * \brief Affichage d'un point de collecte. Cette methode est virtuel, dans le but d'etre redefini dans les classes filles.
 * \param os Flux ou l'on va afficher le point de collecte
 */
void CollectionPoint::display(std::ostream &os) const noexcept
{
    os << "C ";
}
