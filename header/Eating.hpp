#ifndef EATING_HPP
#define EATING_HPP

#include "State.hpp"



class Eating : public State
{
    public:
        Eating();
        ~Eating();
        Eating *clone();
        void run(Game&, Grid&, Ground *, Character *);
};

#endif