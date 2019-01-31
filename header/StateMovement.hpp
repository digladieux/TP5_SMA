#ifndef STATE_MOVEMENT
#define STATE_MOVEMENT

#include "State.hpp"
#include "Ground.hpp"
#include "Character.hpp"
#include "Constantes.hpp"
#include "TownHall.hpp"

class StateMovement : public State
{
  private:
    bool movementOrdinate(Grid&, Character *, Ground *, unsigned int, unsigned int, unsigned int &, unsigned int &, unsigned int &, unsigned int &, bool &)const ;
    bool movementAbscissa(Grid&, Character *, Ground *, unsigned int, unsigned int, unsigned int &, unsigned int &, unsigned int &, unsigned int &, bool &)const ;
    bool movementCharacter(Grid&, Character *, Ground *, unsigned int, unsigned int, unsigned int &, unsigned int &, unsigned int &, unsigned int &, bool &)const ;

  public:
    StateMovement();
    ~StateMovement();
    StateMovement *clone();
    void run(Game &, Grid &, Ground *, MaleCharacter *, unsigned int &, unsigned int &, unsigned int &, unsigned int &, bool &) const;
    
};

#endif