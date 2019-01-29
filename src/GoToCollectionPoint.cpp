#include "../header/GoToCollectionPoint.hpp"

GoToCollectionPoint::GoToCollectionPoint()
{
}

GoToCollectionPoint::~GoToCollectionPoint()
{
}


void GoToCollectionPoint::run(Ground* ground; Character* character)
{
    Ground *collection_point, *other_collection_point = nullptr;
    unsigned int k = 0;
    double distance_min_primer_collection_point = std::numeric_limits<double>::max(), distance_min_secondary_collection_point = std::numeric_limits<double>::max();
    bool is_collection_point = false;

    while (k < map.getSizeVectorGroundWithCollectionPoint())
    {
        /* TODO : s'arrete si 2 ressource low */
        collection_point = map.getGroundWithCollectionPoint(k);
        if ((collection_point->getGroundType() == (GROUND_TYPE)((MaleCharacter *)character)->getSpeciality()) && (euclidienneDistance(collection_point->getPosition(map.getColumnNumber()), ground->getPosition(map.getColumnNumber())) < distance_min_primer_collection_point) && (((CollectionPoint *)collection_point)->getRessourcesNumber() > Constantes::CONFIG_SIMU["ressourceSpecialityNumber"]))
        {
            ((MaleCharacter *)character)->setDirection(collection_point->getGroundId(), map.getColumnNumber());
            is_collection_point = true;
            distance_min_primer_collection_point = euclidienneDistance(collection_point->getPosition(map.getColumnNumber()), ground->getPosition(map.getColumnNumber()));
        }
        else
        {

            if ((!is_collection_point) && (euclidienneDistance(collection_point->getPosition(map.getColumnNumber()), ground->getPosition(map.getColumnNumber())) < distance_min_secondary_collection_point) && (((CollectionPoint *)collection_point)->getRessourcesNumber() > Constantes::CONFIG_SIMU["ressourceNotSpecialityNumber"]))
            {
                other_collection_point = collection_point;
                distance_min_secondary_collection_point = euclidienneDistance(collection_point->getPosition(map.getColumnNumber()), ground->getPosition(map.getColumnNumber()));
            }
        }
        k++;
    }
    if (!is_collection_point)
    {
        ((MaleCharacter *)character)->setDirection(other_collection_point->getGroundId(), map.getColumnNumber());
    }
    if (other_collection_point == nullptr)
    {
        // throw plus de ressource dispo
    }
}