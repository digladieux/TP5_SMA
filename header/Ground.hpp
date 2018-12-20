/**
 * \file Ground.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source Ground.cpp
 * \date 2018-12-03
 */

#ifndef GROUND_HPP
#define GROUND_HPP

#include "Character.hpp"
#include <vector>
#include <iostream>

/**
 * \enum class
 * \brief Enumeration de tous les types possibles de case sur notre terrain de jeu possible
 */
enum class GROUND_TYPE
{
    LAND,       /*! Terrain (aucune caracteristique) */
    TOWN_HALL,  /*! Hotel de ville */
    QUARRY,     /*! Carriere de pierre */
    LAKE,       /*! Lac */
    FARM,       /*! Ferme */
    FOREST,     /*! Foret */
};

/**
 * \class Ground
 * \brief Une case de notre terrain de jeu
 */
class Ground
{
  protected:
    static unsigned int ground_number;          /*! Nombre de terrain sur la carte au total */
    unsigned int ground_id;                     /*! Identifiant unique du terrain */
    GROUND_TYPE ground_type;                    /*! Type de terrain */
    std::vector<Character *> vector_character;  /*! Tableau dynamique de la liste des personnages sur le terrain */

  public:
    Ground(GROUND_TYPE type = GROUND_TYPE::LAND);
    Ground(const Ground &);
    virtual ~Ground();

    unsigned int getGroundId() const noexcept;
    GROUND_TYPE getGroundType() const noexcept;

    unsigned int getVectorSize() const noexcept;
    void addCharacter(Character *);
    void removeCharacter(const unsigned int);
    Character *getCharacter(const unsigned int) const;

    bool operator==(const Ground &);

    static void resetGroundNumber() noexcept;
    virtual void display(std::ostream &os = std::cout) const noexcept;
};

#endif
