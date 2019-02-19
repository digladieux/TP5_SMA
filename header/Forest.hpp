/**
 * \file Forest.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source Forest.cpp
 * \date 2018-12-03
 */

#ifndef FOREST_HPP
#define FOREST_HPP

#include "CollectionPoint.hpp"

/**
 * \class Forest
 * \brief La foret etant un point de collecte de ressource, elle herite des attributs et des methodes de CollectionPoint
 */
class Forest : public CollectionPoint
{
  public:
    explicit Forest(const unsigned int wood_number = 1000);
    Forest(const Forest &);
    Forest(const Ground &, const unsigned int);
    ~Forest();
    Forest* clone() const ;
    void display(std::ostream &os = std::cout) const noexcept;
};

#endif
