/**
 * \file StrategyLowRessources.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source StrategyLowRessources.cpp
 * \date 2018-12-03
 */

#ifndef STRATEGYLOWRESSOURCES_HPP
#define STRATEGYLOWRESSOURCES_HPP

#include "Strategy.hpp"

/**
 * \class StrategyLowRessources
 * \brief La strategie employe est d'aller vers le point de collecte le plus proche et celui dont les ressources sont les plus insuffisantes dans l'hotel de ville
 * 
 */
class StrategyLowRessources : public Strategy
{
    public:
        StrategyLowRessources();
        ~StrategyLowRessources();
        StrategyLowRessources *clone();

       bool run(Grid&, MaleCharacter *) ;
};

#endif
