/**
 * \file Quarry.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source Quarry.cpp
 * \date 2018-12-03
 */

#ifndef QUARRY_HPP
#define QUARRY_HPP

#include "CollectionPoint.hpp"

/**
 * \class Quarry
 * \brief La carriere etant un point de collecte de ressource, elle herite des attributs et des methodes de CollectionPoint
 */
class Quarry : public CollectionPoint
{
  public:
    Quarry(const unsigned int rock_number = 1000);
    Quarry(const Quarry &);
    Quarry(const Ground &, const unsigned int)  ;
    Quarry *clone() const ;

    ~Quarry();

    void display(std::ostream &os = std::cout) const noexcept;
};

#endif
