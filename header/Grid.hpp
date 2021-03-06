/**
 * \file Grid.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source Grid.cpp
 * \date 2018-12-03
 */

#ifndef GRID_HPP
#define GRID_HPP

#include "MaleCharacter.hpp"
#include <string>
#include <iostream>
#include <vector>
class Ground;
/**
 * \class Grid
 * \brief Carte de notre terrain de jeux
 */
class Grid
{
private:
  unsigned int row_number;                            /*! Nombre de ligne sur le plateau */
  unsigned int column_number;                         /*! Nombre de colonne sur le plateau */
  Ground ***ground_grid;                              /*! Matrice de tous les terrains */
  std::vector<Ground *> ground_with_character;        /*! Tableau dynamique de l'emplacement des joueurs sur le terrain de jeux */
  std::vector<Ground *> ground_with_collection_point; /*! Tableau dynamique de l'emplacement des lieux interessants sur le terrain de jeux */

  void initialisationCharacter(std::vector<unsigned int>&, std::vector<Character *> &,  const unsigned int);
  void initialisationMap(std::vector<unsigned int>& , std::vector<Character *> &);

public:
  Grid(std::vector<unsigned int>&, std::vector<unsigned int>&, const unsigned int strategy_choice = 0);
  Grid(const Grid &);
  Grid &operator=(const Grid &) ;
  ~Grid();
  void displayMap(std::ostream &os = std::cout) const noexcept;
  void displayCharacter(std::ostream &os = std::cout) const noexcept;
  void display(std::ostream &os = std::cout) const noexcept;

  static JOB choiceJob(unsigned int);
  static Ground *initGround(unsigned int, unsigned int);
  static Ground * initGround(Ground *, unsigned int, const unsigned int) ;

  static void push_backGround(std::vector<Ground *> &, Ground *);

  SEX choiceGender(unsigned int);

  unsigned int getRowNumber() const noexcept;
  unsigned int getColumnNumber() const noexcept;

  unsigned int getSizeVectorGroundWithCharacter() const noexcept;
  unsigned int getSizeVectorGroundWithCollectionPoint() const noexcept;

  Ground *getDirectionCharacter(StructCoordinates);

  Ground *getGroundWithCharacter(unsigned int) const;
  Ground *getGroundWithCollectionPoint(unsigned int) const;
  Ground *getGroundGrid(unsigned int, unsigned int) const;
  Ground *getGroundGrid(unsigned int);

  void addGroundWithCharacter(Ground *);
  void removeGroundWithCharacter(const unsigned int);
};

#endif
