#ifndef HAVINGSEX_HPP
#define HAVINGSEX_HPP

#include "State.hpp"



class HavingSex : public State
{
    public:

        HavingSex();
        ~HavingSex();
        HavingSex *clone() ;
        void run(Game&, Grid&, Ground *, Character *);
};

#endif