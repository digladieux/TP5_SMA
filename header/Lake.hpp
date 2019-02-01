/**
 * \file Lake.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source Lake.cpp
 * \date 2018-12-03
 */

#ifndef LAKE_HPP
#define LAKE_HPP

#include "CollectionPoint.hpp"

/**
 * \class Lake
 * \brief Le lac etant un point de collecte de ressource, il herite des attributs et des methodes de CollectionPoint
 */
class Lake : public CollectionPoint
{
  public:
    Lake(const unsigned int fish_nb = 1000);
    Lake(const Lake &);
    Lake(const Ground &, const unsigned int);
    Lake* clone() const ;
    ~Lake();

    void display(std::ostream &os = std::cout) const noexcept;
};
#endif
