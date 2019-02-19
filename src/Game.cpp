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
using json = nlohmann::json;

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

Game::~Game()
{
    delete map;
    delete report;
}

void Game::reset(const unsigned int new_strategy) noexcept
{
    turn = Date(1, 1, 60); /* CONSTANTE */
    delete map;
    strategy = new_strategy;
    map = new Grid(map_choice, character_choice, strategy);
}
void Game::run(unsigned int round)
{
    for (unsigned int i = 0; i < round; i++)
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
            usleep(10000);
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
    }
    writingReport();
}
void Game::writingReport() noexcept
{
    
    TownHall *townhall = static_cast<TownHall*>(map->getGroundGrid(0, 0));
    writingReportTownHall(townhall, 0);
    townhall = static_cast<TownHall*>(map->getGroundGrid(map->getRowNumber() - 1, map->getColumnNumber() - 1));
    writingReportTownHall(townhall, 1);
}

void Game::writingReportTownHall(TownHall *townhall, unsigned int i) noexcept
{
    report[i]->setLevel(townhall->getLevel());
    (townhall->getGroundId() == 0) ? report[i]->setTeam(0) : report[i]->setTeam(1);
    report[i]->setRockNumber(townhall->getRockNumber());
    report[i]->setWoodNumber(townhall->getWoodNumber());
    report[i]->setFishNumber(townhall->getFishNumber());
    report[i]->setFoodNumber(townhall->getFoodNumber());
}

void Game::lifeOfCharacter()
{
    Character *character;
    Ground *ground;
    unsigned int number_ground_with_character = map->getSizeVectorGroundWithCharacter(),
                 i = 0,
                 team;
    while (i < number_ground_with_character)
    {
        bool is_ground_deleted = false;
        unsigned int j = 0;
        ground = map->getGroundWithCharacter(i);
        unsigned int number_character_ground = ground->getVectorSize();
        while (j < number_character_ground)
        {

            character = ground->getCharacter(j);
            team = character->getCharacterTeam();

            if (!deathOfCharacter(character, i, j))
            {
                if (character->getCharacterGender() == SEX::FEMALE && !(Date() == ((static_cast<FemaleCharacter*>(character))->getPregnancyTime())) && (character->getCharacterAge(turn) >= Constantes::CONFIG_SIMU["majority"]))
                {
                    if (character->getCharacterCurrentLife() < 1)
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

                    if ((static_cast<FemaleCharacter*>(character))->getMonthPregnancy(turn) == 9)
                    {
                        birthOfCharacter(character);
                    }
                    j++;
                }

                else if ((character->getCharacterGender() == SEX::MALE) && (character->getCharacterAge(turn) >= Constantes::CONFIG_SIMU["majority"]))
                {
                    (static_cast<MaleCharacter*>(character))->executeState(*this, *map, ground, static_cast<MaleCharacter*>(character), i, j, number_ground_with_character, number_character_ground, is_ground_deleted);
                }

                else
                {
                    j++;
                }
            }
            else
            {
                number_character_ground--;
                (team == 0) ? report[0]->incrementNumberOfDeath() : report[1]->incrementNumberOfDeath();
                number_of_death_this_turn++;
            }
        }
        if (!is_ground_deleted)
        {
            i++;
        }
    }
}
double Game::euclidienneDistance(const StructCoordinates &a, const StructCoordinates &b)
{

    double substrate_abscissa = (b.getAbscissa() > a.getAbscissa()) ? b.getAbscissa() - a.getAbscissa() : a.getAbscissa() - b.getAbscissa();
    double substrate_ordinate = (b.getOrdinate() > a.getOrdinate()) ? b.getOrdinate() - a.getOrdinate() : a.getOrdinate() - b.getOrdinate();
    return sqrt(pow(substrate_abscissa, 2) + pow(substrate_ordinate, 2));
}

bool Game::deathOfCharacter(Character *character, unsigned int i, unsigned int &j)
{
    bool dead = false;
    if (character->isDead(turn) || character->decrementCharacterLife())
    {
        dead = true;
        map->getGroundWithCharacter(i)->removeCharacter(j);
        delete character;
        j--;
    }
    return dead;
}
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

void Game::display(std::ostream &os) const noexcept
{
    map->display();
    //map->displayMap->);
    //map->displayCharacter();
    os << "Number of birth this turn : " << number_of_birth_this_turn << std::endl;
    os << "Number of death this turn : " << number_of_death_this_turn << std::endl;
}

Date Game::getTurn() const noexcept
{
    return turn;
}

Report **Game::getReport() const noexcept
{
    return report;
}