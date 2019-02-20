/**
 * \file Enum.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete contenant la liste des differentes enum
 * \date 2018-12-03
 */

#ifndef ENUM_HPP
#define ENUM_HPP
/**
 * \brief Enumeration de toutes les specialites possibles qu'un travailleur peut avoir
 */
enum class JOB
{
    NO_JOB,     /*! Sans professionnalisation (enfant) */
    QUARRY_MAN, /*! Mineur */
    LUMBERJACK, /*! Bucheron */
    FISHERMAN,   /*! Pecheur */
    FARMER     /*! Fermier */
};

/**
 * \brief Indique le type de ressources transporter par un personnage
 */
enum class TYPE_RESSOURCE_TRANSPORTED
{
    NO_RESSOURCE, /*! Pas de ressource */
    ROCK,         /*! Pierre */
    WOOD,         /*! Bois */
    FISH,         /*! Poisson */
    FOOD,         /*! Nourriture */
};

/**
 * \brief Enumeration de tous les types possibles de case sur notre terrain de jeu possible
 */
enum class GROUND_TYPE
{
    LAND,      /*! Terrain (aucune caracteristique) */
    QUARRY,    /*! Carriere de pierre */
    FOREST,    /*! Foret */
    LAKE,      /*! Lac */
    FARM,      /*! Ferme */
    TOWN_HALL, /*! Hotel de ville */
};

/**
 * \brief Enumeration qui definit le sexe
 *
 */
enum class SEX
{
    MALE,
    FEMALE
};


#endif
