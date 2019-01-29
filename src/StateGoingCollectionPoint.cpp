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

void StateGoingCollectionPoint::run(Grid &map, Character *character)
{
    ((MaleCharacter *)character)->setCharacterStrategy(new StrategyClosestCollectionPoint());
    if (!(((MaleCharacter *)character)->runStrategy(map)))
    {
        ((MaleCharacter *)character)->setCharacterStrategy(new StrategyLowRessources());
        ((MaleCharacter *)character)->runStrategy(map);
    }
}