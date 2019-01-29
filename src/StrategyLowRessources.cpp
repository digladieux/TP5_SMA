#include "../header/StrategyLowRessources.hpp"
#include "../header/Game.hpp"
#include "../header/Constantes.hpp"
#include "../header/Ground.hpp"
#include "../header/CollectionPoint.hpp"
#include "../header/TownHall.hpp"
StrategyLowRessources::StrategyLowRessources(){}
StrategyLowRessources::~StrategyLowRessources(){}
bool StrategyLowRessources::run(Grid& map, MaleCharacter *character)
{
    unsigned int k = 0 ;
    bool is_collection_point = false ;
    double distance_min_primer_collection_point = std::numeric_limits<double>::max();
    Ground * town_hall = (character->getCharacterTeam() == 0)?map.getGroundGrid(0,0):map.getGroundGrid(map.getRowNumber() - 1, map.getColumnNumber() - 1) ;
    Ground * collection_point ;
    while (k < map.getSizeVectorGroundWithCollectionPoint())
    {
        collection_point = map.getGroundWithCollectionPoint(k);
        if ((collection_point->getGroundType() == ((TownHall *)town_hall)->lowStock()) && (Game::euclidienneDistance(collection_point->getPosition(map.getColumnNumber()), collection_point->getPosition(map.getColumnNumber())) < distance_min_primer_collection_point) && (((CollectionPoint *)collection_point)->getRessourcesNumber() > Constantes::CONFIG_SIMU["ressourceSpecialityNumber"]))
        {
            ((MaleCharacter *)character)->setDirection(collection_point->getGroundId(), map.getColumnNumber());
            is_collection_point = true;
            distance_min_primer_collection_point = Game::euclidienneDistance(collection_point->getPosition(map.getColumnNumber()), collection_point->getPosition(map.getColumnNumber()));
        }
        k++;
    }
    return is_collection_point;
}
