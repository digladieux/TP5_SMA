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
#include "math.h"
#include <unistd.h>
#include <limits>
using json = nlohmann::json;

Game::Game(std::vector<unsigned int> &map_choice, std::vector<unsigned int> &character_choice, unsigned int config_choice, const Date &date) : map(new Grid(map_choice, character_choice)), turn(date), number_of_birth_this_turn(0), number_of_birth_total(0), number_of_death_this_turn(0), number_of_death_total(0)
{
    Constantes::getAllJson();
    Constantes::setConfiguration(config_choice) ;
}

Game::~Game()
{
    delete map ;
}
void Game::run(unsigned int round)
{
    for (unsigned int i = 0; i < round; i++)
    {
        ++turn;
        number_of_death_this_turn = 0;
        number_of_birth_this_turn = 0;
        system("clear");
        std::cout << "Tour " << i + 1 << std::endl;
        turn.display();
        lifeOfCharacter();
        display();
        usleep(100000);
    }
}

void Game::lifeOfCharacter()
{
    Character *character;
    Ground *ground;
    unsigned int number_ground_with_character = map->getSizeVectorGroundWithCharacter(),
                 number_character_ground,
                 i = 0,
                 j = 0;
    bool is_ground_deleted;

    while (i < number_ground_with_character)
    {
        is_ground_deleted = false;
        j = 0;
        ground = map->getGroundWithCharacter(i);
        number_character_ground = ground->getVectorSize();
        while (j < number_character_ground)
        {

            character = ground->getCharacter(j);

            if (!deathOfCharacter(character, i, j))
            {
                if (character->getCharacterGender() == SEX::FEMALE 
                && !(Date() == (((FemaleCharacter *)character)->getPregnancyTime())) && (character->getCharacterAge(turn) >= Constantes::CONFIG_SIMU["majority"])) 
                {
                    if (character->getCharacterCurrentLife() < 1) 
                    {
                        if (((TownHall *)ground)->removeFishNumber(1))
                        {
                            character->giveCharacterLife((unsigned int)Constantes::CONFIG_SIMU["lifeWin"]);
                        }
                        else if (((TownHall *)ground)->removeFishNumber(1))
                        {
                            character->giveCharacterLife((unsigned int)Constantes::CONFIG_SIMU["lifeWin"]);
                        }
                    }

                    if (((FemaleCharacter *)character)->getMonthPregnancy(turn) == 9)
                    {
                        birthOfCharacter(character);
                    }
                    j++;
                }

                else if ((character->getCharacterGender() == SEX::MALE) && (character->getCharacterAge(turn) >= Constantes::CONFIG_SIMU["majority"]))
                {
                        ((MaleCharacter *)character)->executeState(*this, *map, ground, (MaleCharacter*)character, i, j, number_ground_with_character, number_character_ground, is_ground_deleted); 
                }

                else
                {
                    j++;
                }
            }
            else
            {
                number_character_ground--;
                number_of_death_total++;
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
        delete character ;
        j--;
    }
    return dead;
}
void Game::birthOfCharacter(Character *character)
{
    Character *new_character;
    for (unsigned int i = 0; i < ((FemaleCharacter *)character)->getBabyPerPregnancy(); ++i)
    {
        if (genrand_real1() < Constantes::CONFIG_SIMU["chanceMale"])
        {
            new_character = new MaleCharacter(turn, character->getCharacterTeam(), map->getColumnNumber());
        }
        else
        {
            new_character = new FemaleCharacter(turn, character->getCharacterTeam());
        }
        map->getGroundGrid(new_character->getCharacterTeam())->addCharacter(new_character);
    }
    ((FemaleCharacter *)character)->setTimePregnancy(Date());
    ((FemaleCharacter *)character)->randomBabyPerPregnancy();

    number_of_birth_this_turn += ((FemaleCharacter *)character)->getBabyPerPregnancy();
    number_of_birth_total += ((FemaleCharacter *)character)->getBabyPerPregnancy();
}

void Game::display(std::ostream &os) const noexcept
{
    map->display();
    //map->displayMap->);
    //map->displayCharacter();
    os << "Number of birth this turn : " << number_of_birth_this_turn << std::endl;
    os << "Number of death this turn : " << number_of_death_this_turn << std::endl;
    os << "Total birth : " << number_of_birth_total << std::endl;
    os << "Total death : " << number_of_death_total << std::endl;
}

Date Game::getTurn() const noexcept
{
    return turn;
}
