#include "../header/StrategyJob.hpp"
#include "../header/Game.hpp"
#include "../header/Constantes.hpp"
#include "../header/Ground.hpp"
#include "../header/CollectionPoint.hpp"

StrategyJob::StrategyJob(){}
StrategyJob* StrategyJob::clone()
{
    return new StrategyJob();
}
StrategyJob::~StrategyJob(){}
bool StrategyJob::run(Grid& map, MaleCharacter *character)
{
    unsigned int k = 0 ;
    bool is_collection_point = false ;
    double distance_min_primer_collection_point = std::numeric_limits<double>::max();
    double tmp_distance ;
    Ground * collection_point ;
    GROUND_TYPE ground_type = (GROUND_TYPE)character->getSpeciality() ;
    
    while (k < map.getSizeVectorGroundWithCollectionPoint())
    {
        collection_point = map.getGroundWithCollectionPoint(k);
        tmp_distance = Game::euclidienneDistance(map.getGroundGrid(character->getCharacterTeam())->getPosition(map.getColumnNumber()), collection_point->getPosition(map.getColumnNumber()));
        if ((collection_point->getGroundType() == ground_type ) && (tmp_distance < distance_min_primer_collection_point) && (((CollectionPoint *)collection_point)->getRessourcesNumber() > Constantes::CONFIG_SIMU["ressourceSpecialityNumber"]))
        {
            character->setDirection(collection_point->getGroundId(), map.getColumnNumber());
            character->setTypeRessourceTransported(collection_point->getGroundType());
            is_collection_point = true;
            distance_min_primer_collection_point = tmp_distance ;

        }
        k++;
    }
    return is_collection_point;
}
