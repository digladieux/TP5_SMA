/**
 * \file StrategyLowRessources.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation de la classe StrategyLowRessources
 * \date 2018-12-03
 */

#include "../header/StrategyLowRessources.hpp"
#include "../header/Game.hpp"
#include "../header/Constantes.hpp"
#include "../header/Ground.hpp"
#include "../header/CollectionPoint.hpp"
#include "../header/TownHall.hpp"
/**
 * \fn StrategyLowRessources::StrategyLowRessources()
 * \brief Constructeur par default de la classe StrategyLowRessources
 */

StrategyLowRessources::StrategyLowRessources(){}

/**
 * \fn StrategyLowRessources* StrategyLowRessources::clone() const
 * \brief Constructeur dynamique de la classe StrategyLowRessources. C'est un moyen de construire un constructeur virtuel. Quand on ne connait pas le type de Strategy que l'on a et que l'on veut faire une copie de ce dernier, on utilise cette methode
 */
StrategyLowRessources* StrategyLowRessources::clone()
{
    return new StrategyLowRessources();
}
/**
 * \fn StrategyLowRessources::~StrategyLowRessources()
 * \brief Destructeur de la classe StrategyLowRessources
 */
StrategyLowRessources::~StrategyLowRessources(){}

/**
 * \fn bool StrategyLowRessources::run(Grid& map, MaleCharacter *character)
 * \brief Lancement de la strategie de la ressource la moins grande dans l'hotel de ville du personnage
 * \param &map Carte ou se trouve le personnage
 * \param *character Personnage que l'on veut affecter a un point de collecte
 * \return True si il a trouve un point de collecte disponible, faux sinon
 */
bool StrategyLowRessources::run(Grid& map, MaleCharacter *character)
{
    unsigned int k = 0 ;
    bool is_collection_point = false ;
    double distance_min_primer_collection_point = std::numeric_limits<double>::max();
    Ground * town_hall = (character->getCharacterTeam() == 0)?map.getGroundGrid(0,0):map.getGroundGrid(map.getRowNumber() - 1, map.getColumnNumber() - 1) ;
    GROUND_TYPE ground_type = (static_cast<TownHall*>(town_hall))->lowStock() ;
    while (k < map.getSizeVectorGroundWithCollectionPoint())
    {
        Ground * collection_point = map.getGroundWithCollectionPoint(k);
        double tmp_distance = Game::euclidienneDistance(map.getGroundGrid(character->getCharacterTeam())->getPosition(map.getColumnNumber()), collection_point->getPosition(map.getColumnNumber()));
        if ((collection_point->getGroundType() == ground_type) && (tmp_distance < distance_min_primer_collection_point) && ((static_cast<CollectionPoint*>(collection_point))->getRessourcesNumber() > Constantes::CONFIG_SIMU["ressourceSpecialityNumber"]))
        {
            character->setDirection(collection_point->getGroundId(), map.getColumnNumber());
            character->setTypeRessourceTransported(collection_point->getGroundType());

            is_collection_point = true;
            distance_min_primer_collection_point =  tmp_distance ;
        }
        k++;
    }
    return is_collection_point;
}
