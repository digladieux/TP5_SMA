/**
 * \file MaleCharacter.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source MaleCharacter.cpp
 * \date 2018-12-03
 */

#ifndef MALE_CHARACTER_HPP
#define MALE_CHARACTER_HPP
#include "Enum.hpp"
#include "Character.hpp"
#include "Ground.hpp"
#include "StructCoordinates.hpp"
#include "MaleCharacter.hpp"

/**
 * \class MaleCharacter
 * \brief Un personnage masculin herite des attributs et methodes d'un personnage. Le but du personnage masculin est de travailler pour recolter des ressources/
 */
class MaleCharacter : public Character
{
  private:
    StructCoordinates direction;
    State* character_current_state;
    TYPE_RESSOURCE_TRANSPORTED type_ressource_transported;
    JOB speciality;            /*! Specialite du personnage */
    unsigned int time_at_work; /*! Temps de travail effectue dans un point de collecte */

  public:
    MaleCharacter(const Date &, unsigned int team = 0, unsigned column_number = 0);
    MaleCharacter(JOB, const Date &,  unsigned int team = 0, unsigned column_number = 0, unsigned int life = 200);
    MaleCharacter(const MaleCharacter &);
    ~MaleCharacter();

    STATE getCharacterCurrentState() const noexcept; //TODO virer le getState et faire fonctionner le nouveau type de state
    TYPE_RESSOURCE_TRANSPORTED getTypeRessourceTransported() const noexcept;
    JOB getSpeciality() const noexcept;
    unsigned int getTimeAtWork() const noexcept;
    StructCoordinates &getDirection() noexcept;
    void setDirection(unsigned int, unsigned int) noexcept;

    void setCharacterCurrentState(STATE) noexcept;
    void setTypeRessourceTransported(GROUND_TYPE);

    void incrementTimeAtWork() noexcept;
    void resetTimeAtWork() noexcept;
    void setSpeciality(JOB job) noexcept;
    const MaleCharacter &operator=(const MaleCharacter &new_character);
    static JOB jobIdToJob(unsigned int);

    void executeState(Ground *, Character *);
};
#endif
