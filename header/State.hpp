#ifndef STATE_HPP
#define STATE_HPP

#include "../header/Ground.hpp"
#include "../header/Character.hpp"

class Ground;
class Character;

class State
{

    public:
    State();
    virtual ~State();
    virtual void run(Ground*, Character *) = 0 ;
};


#endif