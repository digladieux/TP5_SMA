#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include "json.hpp"

using json = nlohmann::json;
class Menu
{
private:
  json json_characters;
  json json_maps;
  void openningCharacters();
  void openningMaps();

public:
  Menu();
  static void displayWelcome(std::ostream &os = std::cout) noexcept;

  void displayAllMap(std::ostream &os = std::cout) const;
  std::vector<unsigned int> mapChoice() const;

  void displayAllCharacter(std::ostream &os = std::cout) const;
  std::vector<unsigned int> characterChoice() const;

  void displayAllConfig(std::ostream &os = std::cout) const;
  unsigned int configChoice() const noexcept;

  void displayTurnChoice(std::ostream &os = std::cout) const noexcept;
  unsigned int turnChoice() const noexcept;

  static void displaySex(std::ostream &, unsigned int);
  static void displayJob(std::ostream &, unsigned int);
  static void displayGroundType(std::ostream &, unsigned int);
};

#endif
