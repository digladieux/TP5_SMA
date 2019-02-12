#ifndef STRATEGYLOWRESSOURCES_HPP
#define STRATEGYLOWRESSOURCES_HPP

#include "Strategy.hpp"

class StrategyLowRessources : public Strategy
{
    public:
        StrategyLowRessources();
        ~StrategyLowRessources();
        StrategyLowRessources *clone();

       bool run(Grid&, MaleCharacter *) ;
};

#endif
