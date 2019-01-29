#ifndef STRATEGYLOWRESSOURCES_HPP
#define STRATEGYLOWRESSOURCES_HPP

#include "Strategy.hpp"

class StrategyLowRessources : public Strategy
{
    public:
        StrategyLowRessources();
        ~StrategyLowRessources();

       bool run(Grid&, MaleCharacter *) ;
};

#endif
