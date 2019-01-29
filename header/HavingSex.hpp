#ifndef HAVINGSEX_HPP
#define HAVINGSEX_HPP

#include "State.hpp"



class HavingSex : public State
{
    public:

        HavingSex();
        ~HavingSex();
        void run(Ground *, Character *);
};

#endif