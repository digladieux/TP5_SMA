/**
 * \file Constantes.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source Constantes.cpp
 * \date 2018-12-03
 */

#ifndef CONSTANTES_HPP
#define CONSTANTES_HPP
#include "json.hpp"
#include <iostream>

/**
 * \brief Redefinission du type nlohmann (son auteur)::json par json
 */
using json = nlohmann::json;

/**
 * \class Constantes
 * \brief Classe contenant les differents json necessaires pour la simulation
 */
class Constantes
{
  public:
    static json CONFIG_SIMU;    /*! Json de la configuration actuelle */
    static json CHARACTERS ;    /*! Json de tous les personnages */
    static json MAPS ;          /*! Json de toutes les points de collectes */
    static void getAllJson() ;
    static void setConfiguration(unsigned int) ;
    static void displayConfiguration(unsigned int, std::ostream &os = std::cout);
};

#endif
