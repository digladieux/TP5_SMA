/**
 * \file Game.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source Game.cpp
 * \date 2018-12-03
 */

#ifndef GAME_HPP
#define GAME_HPP
#include <vector>
#include "Ground.hpp"
#include "Grid.hpp"
#include "Report.hpp"
class Grid;
class Ground;
class Report;
class TownHall ;
class Game
{
private:
  Grid *map;
  Date turn;
  Report **report;
  unsigned int number_of_birth_this_turn;
  unsigned int number_of_death_this_turn;
  const unsigned int how_to_display;
  std::vector<unsigned int> map_choice;
  std::vector<unsigned int> character_choice;

  void turnCharacter(Character *, Ground *, unsigned int &, unsigned int &, unsigned int &, unsigned int &, bool &);
  bool movementCharacter(Character *, Ground *, unsigned int, unsigned int, unsigned int &, unsigned int &, unsigned int &, unsigned int &, bool &);
  bool movementOrdinate(Character *, Ground *, unsigned int, unsigned int, unsigned int &, unsigned int &, unsigned int &, unsigned int &, bool &);
  bool movementAbscissa(Character *, Ground *, unsigned int, unsigned int, unsigned int &, unsigned int &, unsigned int &, unsigned int &, bool &);
  void writingReport() noexcept;
  void writingReportTownHall(TownHall *, unsigned int) noexcept;

public:
  Game(std::vector<unsigned int> &, std::vector<unsigned int> &, unsigned int, const Date &, const unsigned int);
  ~Game();
  void run(unsigned int);
  void reset() noexcept;
  void lifeOfCharacter();
  bool deathOfCharacter(Character *, unsigned int, unsigned int &);
  void birthOfCharacter(Character *);
  static double euclidienneDistance(const StructCoordinates &, const StructCoordinates &);
  Date getTurn() const noexcept;

  void display(std::ostream &os = std::cout) const noexcept;
};

#endif
