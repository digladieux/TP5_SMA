/**
 * \file Menu.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source Menu.cpp
 * \date 2018-12-03
 */
#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include "json.hpp"

/**
 * \brief Redefinission du type nlohmann (son auteur)::json par json
 */
using json = nlohmann::json;

/**
 * \class Menu
 * \brief Classe pour l'affichage et le choix des caracteristiques de notre simulation
 */
class Menu
{

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

  void displayAllDisplay(std::ostream &os = std::cout) const noexcept;
  unsigned int displayChoice() const noexcept;

  static void displayStrategies(unsigned int, std::ostream &os = std::cout) ;
  static void displaySex(unsigned int, std::ostream &os = std::cout) ;
  static void displayJob(unsigned int, std::ostream &os = std::cout) ;
  static void displayGroundType(unsigned int, std::ostream &os = std::cout) ;
};

#endif
