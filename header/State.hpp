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
    virtual void run(Game& game, Grid&, Ground *, Character *) = 0;
};


#endif