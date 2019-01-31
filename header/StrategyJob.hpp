#ifndef STRATEGYJOB_HPP
#define STRATEGYJOB_HPP

#include "Strategy.hpp"

class StrategyJob : public Strategy
{
    public:
        StrategyJob();
        ~StrategyJob();

       bool run(Grid&, MaleCharacter *) ;
};

#endif