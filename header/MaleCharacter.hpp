/**
 * \file MaleCharacter.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source MaleCharacter.cpp
 * \date 2018-12-03
 */

#ifndef MALE_CHARACTER_HPP
#define MALE_CHARACTER_HPP

#include "Character.hpp"

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
 * \struct Coordinates
 * \brief Coordonne d'un point
 */
class StructCoordinates
{
  private:
    unsigned int abscissa; /* Abscisse du point */
    unsigned int ordinate; /* Ordonnee du point */

  public:
    StructCoordinates(const StructCoordinates &);
    StructCoordinates(unsigned int, unsigned int);

    void setAbcissa(unsigned int) noexcept;
    void setOrdinate(unsigned int) noexcept;

    void incrementAbscissa() noexcept;
    void decrementAbscissa() noexcept;
    void incrementOrdinate() noexcept;
    void decrementOrdinate() noexcept;

    unsigned int getAbscissa() const noexcept;
    unsigned int getOrdinate() const noexcept;

    bool operator==(const StructCoordinates &);
};

/**
 * \class MaleCharacter
 * \brief Un personnage masculin herite des attributs et methodes d'un personnage. Le but du personnage masculin est de travailler pour recolter des ressources/
 */
class MaleCharacter : public Character
{
  private:
    StructCoordinates direction;
    STATE character_current_state;
    TYPE_RESSOURCE_TRANSPORTED type_ressource_transported;
    JOB speciality;            /*! Specialite du personnage */
    unsigned int time_at_work; /*! Temps de travail effectue dans un point de collecte */

  public:
    MaleCharacter(const Date &);
    MaleCharacter(JOB, const Date &);
    MaleCharacter(const MaleCharacter &);
    ~MaleCharacter();

    STATE getCharacterCurrentState() const noexcept;
    TYPE_RESSOURCE_TRANSPORTED getTypeRessourceTransported() const noexcept;
    JOB getSpeciality() const noexcept;
    unsigned int getTimeAtWork() const noexcept;
    StructCoordinates &getDirection() noexcept;
    void setDirection(unsigned int, unsigned int) noexcept;

    void setCharacterCurrentState(STATE) noexcept;
    void setTypeRessourceTransported(TYPE_RESSOURCE_TRANSPORTED) noexcept;
    void setTimeAtWork() noexcept;
    void setSpeciality(JOB job) noexcept;

    const MaleCharacter &operator=(const MaleCharacter &new_character);
};
#endif
