#ifndef STRATEGY_HPP
#define STRATEGY_HPP

#include "MaleCharacter.hpp"
#include "Grid.hpp"
#include "MaleCharacter.hpp"

class MaleCharacter ;
class Grid ;

class Strategy
{
    public:
        Strategy() ;
        virtual ~Strategy() ;
        virtual bool run(Grid&, MaleCharacter *) = 0 ;
};

#endif