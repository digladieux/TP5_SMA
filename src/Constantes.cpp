/**
 * \file Constantes.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation de la classe Constantes
 * \date 2018-12-03
 */

#include "../header/Constantes.hpp"
#include "../header/json.hpp"
#include "../header/Exception.hpp"
#include <fstream>
#include <iostream>
using json = nlohmann::json;

/**
 * \brief Variable statique contenant la configuration de notre simulation
 */
json Constantes::CONFIG_SIMU = R"({})"_json;

/**
 * \brief Variable statique contenant la liste de tous les personnages
 */
json Constantes::CHARACTERS = R"({})"_json;

/**
 * \brief Variable statique contenant la liste de toutes les cartes
 */
json Constantes::MAPS = R"({})"_json;


/**
 * \fn void Constantes::getAllJson()
 * \brief Permet de recuperer toutes les informations de tous les fichiers json
 */
void Constantes::getAllJson()
{
    std::string file_name_map = "./MAPS/Maps.json";
    std::string file_name_character = "./CHARACTERS/Characters.json";
    std::string file_name_configuration = "./CONFIGURATIONS/Configuration.json";
    std::ifstream file_map(file_name_map);
    std::ifstream file_character(file_name_character);
    std::ifstream file_configuration(file_name_configuration);
    if (file_map.fail())
    {
        throw InvalidFile(file_name_map);
    }
    else if (file_character.fail())
    {
        throw InvalidFile(file_name_character);
    }
    else if (file_configuration.fail())
    {
        throw InvalidFile(file_name_configuration);
    }
    file_map >> Constantes::MAPS;
    file_character >> Constantes::CHARACTERS;
    file_configuration >> Constantes::CONFIG_SIMU;
    file_map.close();
    file_character.close();
    file_configuration.close();
}


/**
 * \fn void Constantes::displayConfiguration(unsigned int config_number, std::ostream &os)
 * \brief Affichage d'une configuration possible de la simulation
 * \param config_number Numero de la configuration souhaitee
 * \param &os Flux sur lequel on envoie l'affichage
 */
void Constantes::displayConfiguration(unsigned int config_number, std::ostream &os)
{
    json config;
    if ((config_number <= 0) || (config_number > CONFIG_SIMU["maxConfig"]))
    {
        throw InvalidConfiguration(config);
    }
    config = CONFIG_SIMU["config" + std::to_string(config_number)] ;
    os << config.dump(4);
    os << std::endl;
}


/**
 * \fn void Constantes::setConfiguration(unsigned int config_number) 
 * \brief Definir la configuration valable sur toute la simulation
 * \param config_number Numero de la configuration souhaitee
 * \param &os Flux sur lequel on envoie l'affichage
 */
void Constantes::setConfiguration(unsigned int config_number) 
{
    if ((config_number <= 0) || (config_number > CONFIG_SIMU["maxConfig"]))
    {
        throw InvalidConfiguration(config_number);
    }
    CONFIG_SIMU = CONFIG_SIMU["config" + std::to_string(config_number)] ;
}

