/**
 * \file StrategyJob.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation de la classe StrategyJob
 * \date 2018-12-03
 */

#include "../header/StrategyJob.hpp"
#include "../header/Game.hpp"
#include "../header/Constantes.hpp"
#include "../header/Ground.hpp"
#include "../header/CollectionPoint.hpp"
/**
 * \fn StrategyJob::StrategyJob()
 * \brief Constructeur par default de la classe StrategyJob
 */

StrategyJob::StrategyJob(){}
/**
 * \fn StrategyJob* StrategyJob::clone() const
 * \brief Constructeur dynamique de la classe StrategyJob. C'est un moyen de construire un constructeur virtuel. Quand on ne connait pas le type de Strategy que l'on a et que l'on veut faire une copie de ce dernier, on utilise cette methode
 */
StrategyJob* StrategyJob::clone()
{
    return new StrategyJob();
}
/**
 * \fn StrategyJob::~StrategyJob()
 * \brief Destructeur de la classe StrategyJob
 */
StrategyJob::~StrategyJob(){}

/**
 * \fn bool StrategyJob::run(Grid& map, MaleCharacter *character)
 * \brief Lancement de la strategie du point de collecte de la specialite du personnage
 * \param &map Carte ou se trouve le personnage
 * \param *character Personnage que l'on veut affecter a un point de collecte
 * \return True si il a trouve un point de collecte disponible, faux sinon
 */
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
