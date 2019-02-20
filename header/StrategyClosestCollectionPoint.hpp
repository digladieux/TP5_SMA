/**
 * \file StrategyClosestCollectionPoint.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source StrategyClosestCollectionPoint.cpp
 * \date 2018-12-03
 */

#ifndef STRATEGY_CLOSEST_COLLECTION_POINT_HPP
#define STRATEGY_CLOSEST_COLLECTION_POINT_HPP

#include "Strategy.hpp"

/**
 * \class StrategyClosestCollectionPoint
 * \brief La strategie est d'aller vers le point de collecte le plus proche
 */
class StrategyClosestCollectionPoint : public Strategy
{
    public:
        StrategyClosestCollectionPoint();
        ~StrategyClosestCollectionPoint();
        StrategyClosestCollectionPoint *clone();

       bool run(Grid&, MaleCharacter *) ;
};

#endif