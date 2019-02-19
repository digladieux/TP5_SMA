/**
 * \file StrategyClosestCollectionPoint.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation de la classe StrategyClosestCollectionPoint
 * \date 2018-12-03
 */

#include "../header/StrategyClosestCollectionPoint.hpp"
#include "../header/Game.hpp"
#include "../header/Constantes.hpp"
#include "../header/Ground.hpp"
#include "../header/CollectionPoint.hpp"
/**
 * \fn StrategyClosestCollectionPoint::StrategyClosestCollectionPoint()
 * \brief Constructeur par default de la classe StrategyClosestCollectionPoint
 */

StrategyClosestCollectionPoint::StrategyClosestCollectionPoint(){}

/**
 * \fn StrategyClosestCollectionPoint* StrategyClosestCollectionPoint::clone() const
 * \brief Constructeur dynamique de la classe StrategyClosestCollectionPoint. C'est un moyen de construire un constructeur virtuel. Quand on ne connait pas le type de Strategy que l'on a et que l'on veut faire une copie de ce dernier, on utilise cette methode
 */
StrategyClosestCollectionPoint* StrategyClosestCollectionPoint::clone()
{
    return new StrategyClosestCollectionPoint();
}

/**
 * \fn StrategyClosestCollectionPoint::~StrategyClosestCollectionPoint()
 * \brief Destructeur de la classe StrategyClosestCollectionPoint
 */
StrategyClosestCollectionPoint::~StrategyClosestCollectionPoint(){}

/**
 * \fn bool StrategyClosestCollectionPoint::run(Grid& map, MaleCharacter *character)
 * \brief Lancement de la strategie du plus pres point de collecte
 * \param &map Carte ou se trouve le personnage
 * \param *character Personnage que l'on veut affecter a un point de collecte
 * \return True si il a trouve un point de collecte disponible, faux sinon
 */
bool StrategyClosestCollectionPoint::run(Grid& map, MaleCharacter *character)
{
    unsigned int k = 0 ;
    bool is_collection_point = false ;
    double distance_min_primer_collection_point = std::numeric_limits<double>::max();

    while (k < map.getSizeVectorGroundWithCollectionPoint())
    {
        Ground * collection_point = map.getGroundWithCollectionPoint(k);
        double tmp_distance = Game::euclidienneDistance(map.getGroundGrid(character->getCharacterTeam())->getPosition(map.getColumnNumber()), collection_point->getPosition(map.getColumnNumber()));
        if ( (tmp_distance < distance_min_primer_collection_point) 
        && ((static_cast<CollectionPoint*>(collection_point))->getRessourcesNumber() > Constantes::CONFIG_SIMU["ressourceNotSpecialityNumber"])) 
        {
            character->setDirection(collection_point->getGroundId(), map.getColumnNumber());
            character->setTypeRessourceTransported(collection_point->getGroundType());
            is_collection_point = true;
            distance_min_primer_collection_point = tmp_distance;
        }
        k++;
    }
    return is_collection_point;
}
