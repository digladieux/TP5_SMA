#ifndef STRATEGY_CLOSEST_COLLECTION_POINT_HPP
#define STRATEGY_CLOSEST_COLLECTION_POINT_HPP

#include "Strategy.hpp"

class StrategyClosestCollectionPoint : public Strategy
{
    public:
        StrategyClosestCollectionPoint();
        ~StrategyClosestCollectionPoint();

       bool run(Grid&, MaleCharacter *) ;
};

#endif