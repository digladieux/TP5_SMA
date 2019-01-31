#include "../header/StateGoingCollectionPoint.hpp"
#include "../header/StrategyClosestCollectionPoint.hpp"
#include "../header/StrategyLowRessources.hpp"
#include "../header/CollectionPoint.hpp"
#include "../header/Constantes.hpp"
#include "../header/Game.hpp"

StateGoingCollectionPoint::StateGoingCollectionPoint()
{
}

StateGoingCollectionPoint::~StateGoingCollectionPoint()
{
}

StateGoingCollectionPoint *StateGoingCollectionPoint::clone()
{
    return new StateGoingCollectionPoint();
}
void StateGoingCollectionPoint::run(Game&, Grid& grid, Ground *, MaleCharacter *character) const
{
    character->setCharacterStrategy(new StrategyClosestCollectionPoint());
    if (!(character->runStrategy(grid)))
    {
        character->setCharacterStrategy(new StrategyLowRessources());
        character->runStrategy(grid);
    }
}