/**
 * \file Game.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation de la classe Game
 * \date 2018-12-03
 */

#include "../header/Game.hpp"
#include "../header/Grid.hpp"
#include "../header/FemaleCharacter.hpp"
#include "../header/TownHall.hpp"
#include "../header/mt19937ar.h"
#include "../header/CollectionPoint.hpp"
#include "../header/Constantes.hpp"
#include "../header/json.hpp"
#include "../header/StrategyJob.hpp"
#include "../header/StrategyLowRessources.hpp"
#include "../header/StrategyClosestCollectionPoint.hpp"
#include "../header/StateWorkingCollectionPoint.hpp"
#include "../header/StateAddingRessources.hpp"
#include "../header/Exception.hpp"
#include "../header/Report.hpp"
#include "math.h"
#include <unistd.h>
#include <limits>

/**
 * \brief Redefinission du type nlohmann (son auteur)::json par json
 */
using json = nlohmann::json;

/**
 * \fn Game::Game(std::vector<unsigned int> &vector_map, std::vector<unsigned int> &vector_character, unsigned int config_choice, const Date &date, const unsigned int display_choice, const unsigned int strategy_choice) 
 * \brief Constructeur de la classe Game
 * \param &vector_map Vecteur contenant la liste des points de collecte
 * \param &vector_character Vecteur contenant la liste des personnages
 * \param config_choice Entier definissant le choix de la configuration de la simulation
 * \param &date Date de depart de la simulation
 * \param display_choice Entier definissant le choix d'affichage de la simulation
 * \param strategy_choice Entier definissant le choix de la strategie de chaque personnage
 */
Game::Game(std::vector<unsigned int> &vector_map, std::vector<unsigned int> &vector_character, unsigned int config_choice, const Date &date, const unsigned int display_choice, const unsigned int strategy_choice) : map(new Grid(vector_map, vector_character, strategy_choice)), turn(date), number_of_birth_this_turn(0), number_of_death_this_turn(0), how_to_display(display_choice), strategy(strategy_choice), map_choice(vector_map), character_choice(vector_character)
{

    report = new Report *[2]();
    report[0] = new Report();
    report[1] = new Report();

    Constantes::getAllJson();
    Constantes::setConfiguration(config_choice);
    if (display_choice > 2)
    {
        throw InvalidDisplayChoice(display_choice);
    }
}

/**
 * \fn Game::~Game()
 * \brief Destructeur de la classe Game
 */
Game::~Game()
{
    delete map;
    delete report[0];
    delete report[1] ;
    delete [] report ;
}

/**
 * \fn Game::Game(const Game& game) :
 * \brief Constructeur de copie de la classe Game
 * \param &game Jeu que l'on veut copier
 */
Game::Game(const Game& game) : map(game.map), turn(game.turn), number_of_birth_this_turn(game.number_of_birth_this_turn), number_of_death_this_turn(game.number_of_death_this_turn), how_to_display(game.how_to_display), strategy(game.strategy), map_choice(game.map_choice), character_choice (game.character_choice) 
{
    report = new Report *[2]();
    for (unsigned int i = 0 ; i < 2 ; i ++)
    {
        report[i] = game.report[i] ;
    }
}

/**
 * \fn Game &Game::operator=(const Game &new_game)
 * \brief Surcharge de l'operateur d'affectation
 * \param &new_game Jeu que l'on veut copier
 * \return Le nouveau jeu
 */
Game &Game::operator=(const Game &new_game)
{
    if (this != &new_game) /* On verifie que le jeu n'est pas le meme que l'on veut copier */
    {
        map = new_game.map;
        turn = new_game.turn;
        number_of_birth_this_turn = new_game.number_of_birth_this_turn;
        number_of_death_this_turn = new_game.number_of_death_this_turn;
        how_to_display = new_game.how_to_display;
        strategy = new_game.strategy;
        map_choice = new_game.map_choice;
        character_choice = new_game.character_choice;
        report = new Report *[2]();
        for (unsigned int i = 0 ; i < 2 ; i ++)
        {
            report[i] = new_game.report[i] ;
        }
    }
    return *this;
}

/**
 * \fn void Game::reset(const unsigned int new_strategy) noexcept
 * \brief Remise a  de la simulation 
 * \param new_strategy Changement de strategy pour les joueurs
 */
void Game::reset(const unsigned int new_strategy) noexcept
{
    turn = Date(1, 1, 60); 
    delete map;
    strategy = new_strategy;
    map = new Grid(map_choice, character_choice, strategy);
}

/**
 * \fn void Game::run(unsigned int round)
 * \brief Lancement de la simulation
 * \param round Nombre de tour de la simulation
 */
void Game::run(unsigned int round)
{
    bool flag = true ;
    unsigned int i = 0 ; 
    while ( (flag) && (i < round))
    {
        ++turn;
        number_of_death_this_turn = 0;
        number_of_birth_this_turn = 0;
        lifeOfCharacter();
        switch (how_to_display)
        {
        case 0:
            system("clear");
            std::cout << "Tour " << i + 1 << std::endl;
            turn.display();
            display();
            usleep(1000);
            break;
        case 1:
            system("clear");
            std::cout << "Tour " << i + 1 << std::endl;
            turn.display();
            display();
            std::getchar();
            break;
        case 2:
            break;
        default:
            throw InvalidDisplayChoice(how_to_display);
        }
        if (map-> getSizeVectorGroundWithCharacter() == 0)
        {
            flag = false ;
        }
        i++ ;
    }
    writingReport();
}

/**
 * \fn void Game::writingReport() noexcept
 * \brief Ecriture du rapport pour les 2 equipes
 */
void Game::writingReport() noexcept
{
    
    TownHall *townhall = static_cast<TownHall*>(map->getGroundGrid(0, 0));
    writingReportTownHall(townhall, 0);
    townhall = static_cast<TownHall*>(map->getGroundGrid(map->getRowNumber() - 1, map->getColumnNumber() - 1));
    writingReportTownHall(townhall, 1);
}

/**
 * \fn void Game::writingReportTownHall(TownHall *townhall, unsigned int i) noexcept
 * \brief Ecriture du rapport pour 1 equipe
 * \param townhall Hotel de ville
 * \param i Numero de l'equipe auquel l'hotel de ville appartient
 */
void Game::writingReportTownHall(TownHall *townhall, unsigned int i) noexcept
{
    report[i]->setLevel(townhall->getLevel());
    (townhall->getGroundId() == 0) ? report[i]->setTeam(0) : report[i]->setTeam(1);
    report[i]->setRockNumber(townhall->getRockNumber());
    report[i]->setWoodNumber(townhall->getWoodNumber());
    report[i]->setFishNumber(townhall->getFishNumber());
    report[i]->setFoodNumber(townhall->getFoodNumber());
}

/**
 * \fn void Game::lifeOfCharacter()
 * \brief Lancement de la simulation pour un tour
 */
void Game::lifeOfCharacter()
{
    Character *character;
    Ground *ground;
    unsigned int number_ground_with_character = map->getSizeVectorGroundWithCharacter(),
                 i = 0,
                 team;
    while (i < number_ground_with_character) /* On regarde la liste de tous les terrains qui contiennent des personnages */
    {
        bool is_ground_deleted = false;
        unsigned int j = 0;
        ground = map->getGroundWithCharacter(i);
        unsigned int number_character_ground = ground->getVectorSize();
        while (j < number_character_ground) /* On regarde la liste de tous les personnages sur ce terrain */
        {

            character = ground->getCharacter(j);
            team = character->getCharacterTeam();

            if (!deathOfCharacter(character, i, j)) /* Si le personnage ne meurt pas (plus de vie ou vieilesse) */
            { 
                if (character->getCharacterGender() == SEX::FEMALE) /* Si le personnage est feminin est majeur */
                {
                    if (character->getCharacterCurrentLife() < 1) /* Si il ne va plus avoir de vie, on le fait manger */
                    {
                        if ((static_cast<TownHall*>(ground))->removeFishNumber(1))
                        {
                            character->giveCharacterLife((unsigned int)Constantes::CONFIG_SIMU["lifeWin"]);
                        }
                        else if ((static_cast<TownHall*>(ground))->removeFishNumber(1))
                        {
                            character->giveCharacterLife((unsigned int)Constantes::CONFIG_SIMU["lifeWin"]);
                        }
                    }
                    else if ((static_cast<FemaleCharacter*>(character))->getMonthPregnancy(turn) == Constantes::CONFIG_SIMU["monthPregnancy"]) /* Si le personnage peut accoucher */
                    {
                        birthOfCharacter(character);
                    }
                    j++;
                }

                else if ((character->getCharacterGender() == SEX::MALE) && (character->getCharacterAge(turn) >= Constantes::CONFIG_SIMU["majority"])) /* Si le personnage est masculin */
                {
                    (static_cast<MaleCharacter*>(character))->executeState(*this, *map, ground, static_cast<MaleCharacter*>(character), i, j, number_ground_with_character, number_character_ground, is_ground_deleted);
                }

                else
                {
                    j++;
                }
            }
            else /* Si le personnage est mort on actualise le rapport */
            {
                number_character_ground--;
                (team == 0) ? report[0]->incrementNumberOfDeath() : report[1]->incrementNumberOfDeath();
                number_of_death_this_turn++;
            }
        }
        if (!is_ground_deleted) /* Si un terrain contient encore des personnages, alors on regarde le suivant */
        {
            i++;
        }
    }
    /* Le nombre de ressource evolue dans un point de collecte */
    unsigned int number_collection_point = map->getSizeVectorGroundWithCollectionPoint() ;
    for(unsigned int i = 0 ; i < number_collection_point ; i ++)
    {
        CollectionPoint * collection_point = (static_cast<CollectionPoint*>(map->getGroundWithCollectionPoint(i))) ;
        collection_point->evolutionRessources() ;
    }
}

/**
 * \fn double Game::euclidienneDistance(const StructCoordinates &a, const StructCoordinates &b)
 * \brief Calcul la distance euclidienne entre 2 points de la carte 
 * \param a Premier point de la carte
 * \param b Deuxieme point de la carte
 * \return La distance entre ces 2 points
 */
double Game::euclidienneDistance(const StructCoordinates &a, const StructCoordinates &b)
{

    double substrate_abscissa = (b.getAbscissa() > a.getAbscissa()) ? b.getAbscissa() - a.getAbscissa() : a.getAbscissa() - b.getAbscissa();
    double substrate_ordinate = (b.getOrdinate() > a.getOrdinate()) ? b.getOrdinate() - a.getOrdinate() : a.getOrdinate() - b.getOrdinate();
    return sqrt(pow(substrate_abscissa, 2) + pow(substrate_ordinate, 2));
}

/**
 * \fn bool Game::deathOfCharacter(Character *character, unsigned int i, unsigned int &j)
 * \brief Methode qui va tester si le personnage restera en vie a ce tour
 * \param *character Personnage qui va potentiellement mourrir 
 * \param i Indice du terrain dans le vecteur
 * \param j Indice du personnage sur ce terrain
 * \return True si le personnage meurt, false sinon 
 */
bool Game::deathOfCharacter(Character *character, unsigned int i, unsigned int &j)
{
    bool dead = false;
    if (character->isDead(turn) || character->decrementCharacterLife()) /* Si le personnage meurt de vieillesse ou de faim */
    {
        dead = true;
        map->getGroundWithCharacter(i)->removeCharacter(j);
        delete character;
        j--;
    }
    return dead;
}

/**
 * \fn void Game::birthOfCharacter(Character *character)
 * \brief Methode qui donne naissance a des personnages
 * \param *character Personnage Feminin qui va donner naissance a des enfants 
 */
void Game::birthOfCharacter(Character *character)
{
    Character *new_character;
    for (unsigned int i = 0; i < (static_cast<FemaleCharacter*>(character))->getBabyPerPregnancy(); ++i)
    {
        if (genrand_real1() < Constantes::CONFIG_SIMU["chanceMale"])
        {
            new_character = new MaleCharacter(turn, character->getCharacterTeam(), map->getColumnNumber(), strategy);
        }
        else
        {
            new_character = new FemaleCharacter(turn, character->getCharacterTeam());
        }
        map->getGroundGrid(new_character->getCharacterTeam())->addCharacter(new_character);
        (new_character->getCharacterTeam() == 0) ? report[0]->incrementNumberOfBirth() : report[1]->incrementNumberOfBirth();
    }
    (static_cast<FemaleCharacter*>(character))->setTimePregnancy(Date());
    (static_cast<FemaleCharacter*>(character))->randomBabyPerPregnancy();

    number_of_birth_this_turn += (static_cast<FemaleCharacter*>(character))->getBabyPerPregnancy();
}

/**
 * \fn void Game::display(std::ostream &os) const noexcept
 * \brief Affichage de la simulation a l'ecran 
 * \param &os Flux ou l'on va afficher la simulation
 */
void Game::display(std::ostream &os) const noexcept
{
    map->display();
    os << "Number of birth this turn : " << number_of_birth_this_turn << std::endl;
    os << "Number of death this turn : " << number_of_death_this_turn << std::endl;
}

/**
 * \fn Date Game::getTurn() const noexcept
 * \brief Getteur sur la date du tour actuelle
 * \return Le date du tour actuelle
 */
Date Game::getTurn() const noexcept
{
    return turn;
}

/**
 * \fn Report **Game::getReport() const noexcept
 * \brief Getteur sur la liste des rapports de la simulations
 * \return Les rapports des 2 equipes
 */
Report **Game::getReport() const noexcept
{
    return report;
}