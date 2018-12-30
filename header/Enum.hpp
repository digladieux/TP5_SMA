#ifndef ENUM_HPP
#define ENUM_HPP
/**
 * \enum class JOB
 * \brief Enumeration de toutes les specialites possibles qu'un travailleur peut avoir
 */
enum class JOB
{
    NO_JOB,     /*! Sans professionnalisation (enfant) */
    FARMER,     /*! Fermier */
    LUMBERJACK, /*! Bucheron */
    QUARRY_MAN, /*! Mineur */
    FISHERMAN   /*! Pecheur */
};
/**
 * \enum class STATE
 * \brief Enumeration de tous les etats possibles d'un personnage
 *
 */
enum class STATE
{
    NO_STATE,                  /*! Pas d'etat (etat initial) */
    GOING_TO_COLLECTION_POINT, /*! Se diriger vers un point de collecte */
    GOING_TO_TOWN_HALL,        /*! Se dirige vers l'hotel de ville */
    WORKING,                   /*! Travaille sur le point de collecte */
    BUILDING,                  /*! Ameliore l'hotel de ville */
    HAVING_SEX                 /*! Fait l'amour avec sa compagne */
};

/**
 * \enum class TYPE_RESSOURCE_TRANSPORTED
 * \brief Indique le type de ressources transporter par un personnage
 */
enum class TYPE_RESSOURCE_TRANSPORTED
{
    NO_RESSOURCE, /*! Pas de ressource */
    ROCK,         /*! Pierre */
    FISH,         /*! Poisson */
    WOOD,         /*! Bois */
    FOOD,         /*! Nourriture */
};

/**
 * \enum class SEX
 * \brief Enumeration qui definit la majorite d'un personnage, ainsi que son sexe
 *
 */
enum class SEX
{
    MALE,
    FEMALE
};

/**
 * \enum class
 * \brief Enumeration de tous les types possibles de case sur notre terrain de jeu possible
 */
enum class GROUND_TYPE
{
    LAND,      /*! Terrain (aucune caracteristique) */
    TOWN_HALL, /*! Hotel de ville */
    QUARRY,    /*! Carriere de pierre */
    LAKE,      /*! Lac */
    FARM,      /*! Ferme */
    FOREST,    /*! Foret */
};

#endif
