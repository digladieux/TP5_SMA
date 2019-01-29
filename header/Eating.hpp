#ifndef EATING_HPP
#define EATING_HPP

#include "State.hpp"



class Eating : public State
{
    public:
        Eating();
        ~Eating();
        void run(Ground *, Character *);
};

#endif