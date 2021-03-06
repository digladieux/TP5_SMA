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
#include "Strategy.hpp"
#include "Game.hpp"
#include "Grid.hpp"

class State;
class Ground;
class Game;
class Grid;

class Grid ;
class Strategy ;
/**
 * \class MaleCharacter
 * \brief Un personnage masculin herite des attributs et methodes d'un personnage. Le but du personnage masculin est de travailler pour recolter des ressources/
 */
class MaleCharacter : public Character
{
  private:
    StructCoordinates direction;                              /*! Direction du personnage masculin */
    State * character_current_state;                          /*! Etat actuel du personnage */
    TYPE_RESSOURCE_TRANSPORTED type_ressource_transported;    /*! Type de ressource transporte par le personnage */
    JOB speciality;                                           /*! Specialite du personnage */
    Strategy * character_strategy ;                           /*! Strategie adopte par le personnage */
    unsigned int time_at_work;                                /*! Temps de travail effectue dans un point de collecte */

  public:
    MaleCharacter(const Date &, unsigned int team = 0, unsigned int column_number = 0, const unsigned int strategy = 0);
    MaleCharacter(JOB, const Date &,  unsigned int team = 0, unsigned int column_number = 0, unsigned int life = 200, const unsigned int strategy = 0);
    MaleCharacter(const MaleCharacter &);
    ~MaleCharacter();

    TYPE_RESSOURCE_TRANSPORTED getTypeRessourceTransported() const noexcept;
    JOB getSpeciality() const noexcept;
    unsigned int getTimeAtWork() const noexcept;
    StructCoordinates &getDirection() noexcept;

    void setDirection(unsigned int, unsigned int) noexcept;
    void setCharacterCurrentState(State*) noexcept;
    void setTypeRessourceTransported(GROUND_TYPE);
    void setCharacterStrategy(Strategy *) ;
    bool runStrategy(Grid& map) ;


    void incrementTimeAtWork() noexcept;
    void resetTimeAtWork() noexcept;
    void setSpeciality(JOB job) noexcept;
    MaleCharacter &operator=(const MaleCharacter &new_character);
    static JOB jobIdToJob(unsigned int);
    static Strategy * strategyIdToStrategy(const unsigned int) ;
    void executeState(Game &, Grid &, Ground *, MaleCharacter *, unsigned int &, unsigned int &, unsigned int &, unsigned int &, bool &) const;


};
#endif
