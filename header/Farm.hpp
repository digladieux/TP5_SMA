/**
 * \file Farm.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source Farm.cpp
 * \date 2018-12-03
 */

#ifndef FARM_HPP
#define FARM_HPP

#include "CollectionPoint.hpp"

/**
 * \class Farm
 * \brief La ferme etant un point de collecte de ressource, elle herite des attributs et des methodes de CollectionPoint
 */
class Farm : public CollectionPoint
{
  public:
    Farm(const unsigned int food_number = 1000);
    Farm(const Farm &);
    Farm(const Ground &, const unsigned int) ;

    ~Farm();

    void display(std::ostream &os = std::cout) const noexcept;
};

#endif
