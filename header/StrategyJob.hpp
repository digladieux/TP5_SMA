/**
 * \file StrategyJob.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source StrategyJob.cpp
 * \date 2018-12-03
 */

#ifndef STRATEGYJOB_HPP
#define STRATEGYJOB_HPP

#include "Strategy.hpp"

/**
 * \class StrategyJob
 * \brief La strategie employe est d'aller vers le point de collecte le plus proche et qui est de sa specialite
 */
class StrategyJob : public Strategy
{
    public:
        StrategyJob();
        ~StrategyJob();
        StrategyJob *clone();

       bool run(Grid&, MaleCharacter *) ;
};

#endif