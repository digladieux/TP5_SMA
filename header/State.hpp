#ifndef STATE_HPP
#define STATE_HPP

#include "../header/Ground.hpp"
#include "../header/MaleCharacter.hpp"

class Ground;
class MaleCharacter;
class Game;
class Grid;

class State
{

    public:
    State();
    virtual ~State();
    virtual State* clone() = 0 ;
    virtual void run(Game&, Grid&, Ground *, MaleCharacter *) const = 0;
};


#endif