#ifndef STATE_HPP
#define STATE_HPP

#include "../header/Ground.hpp"
#include "../header/Character.hpp"

class Ground;
class Character;
class Game;
class Grid;

class State
{

    public:
    State();
    virtual ~State();
    virtual State* clone() = 0 ;
    virtual void run(Grid&,Character *);
    virtual void run(Ground *, Character *);
    virtual void run(Character *);
};


#endif