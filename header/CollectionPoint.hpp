/**
 * \file CollectionPoint.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source CollectionPoint.cpp
 * \date 2018-12-03
 */

#ifndef COLLECTION_POINT_HPP
#define COLLECTION_POINT_HPP

#include "MaleCharacter.hpp"
#include "Ground.hpp"
#include <vector>

/**
 * \class CollectionPoint
 * \brief Un point de collecte etant sur un terrain, il herite de toutes les methodes et attributs de Ground. C'est le lieu de collecte des ressources pour le developpement de l'hotel de ville
 */
class CollectionPoint : public Ground
{
  protected:
    unsigned int ressources_number; /*! Nombre de ressource sur le point de collecte */

  public:
    CollectionPoint(const Ground& , GROUND_TYPE, const unsigned int);
    CollectionPoint(GROUND_TYPE, const unsigned int ressources_nb = 1000);
    CollectionPoint(GROUND_TYPE, const unsigned int, unsigned int, const std::vector<Character *>&);
    
    virtual ~CollectionPoint();

    unsigned int getRessourcesNumber() const noexcept;
    void setRessources(const unsigned int);
    bool ressourcesNumberExtracted(const unsigned int);
    void evolutionRessources() noexcept;

    virtual void display(std::ostream &os) const noexcept = 0;
};

#endif
