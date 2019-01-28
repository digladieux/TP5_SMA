#include "../header/Game.hpp"
#include "../header/FemaleCharacter.hpp"
#include "../header/TownHall.hpp"
#include "../header/mt19937ar.h"
#include "../header/CollectionPoint.hpp"
#include "../header/Constantes.hpp"
#include "../header/json.hpp"
#include "math.h"
#include <unistd.h>
#include <limits>
using json = nlohmann::json;

Game::Game(std::vector<unsigned int> &map_choice, std::vector<unsigned int> &character_choice, unsigned int config_choice, const Date &date) : map(map_choice, character_choice), turn(date), number_of_birth_this_turn(0), number_of_birth_total(0), number_of_death_this_turn(0), number_of_death_total(0)
{
    Constantes::openingConfiguration(config_choice);
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
        usleep(10);
    }
}

void Game::lifeOfCharacter()
{
    Character *character;
    Ground *ground;
    unsigned int number_ground_with_character = map.getSizeVectorGroundWithCharacter(),
                 number_character_ground,
                 i = 0,
                 j = 0;
    bool is_ground_deleted;

    while (i < number_ground_with_character)
    {
        is_ground_deleted = false;
        j = 0;
        ground = map.getGroundWithCharacter(i);
        number_character_ground = ground->getVectorSize();
        while (j < number_character_ground)
        {

            character = ground->getCharacter(j);

            if (!deathOfCharacter(character, i, j))
            {
                if (character->getCharacterGender() == SEX::FEMALE && !(Date() == (((FemaleCharacter *)character)->getPregnancyTime())))
                {
                    if (character->getCharacterCurrentLife() < 50) /* TODO RAND */
                    {
                        caseEating(ground, character) ;
                    }

                    if (((FemaleCharacter *)character)->getMonthPregnancy(turn) == 9)
                    {
                        birthOfCharacter(character);
                    }
                    j++;
                }

                else if ((character->getCharacterGender() == SEX::MALE) && (character->getCharacterAge(turn) >= Constantes::CONFIG_SIMU["majority"]))
                {
                    if (((MaleCharacter *)character)->getDirection() == ground->getPosition(map.getColumnNumber()))
                    {
                        switch (ground->getGroundType())
                        {
                        case GROUND_TYPE::TOWN_HALL:
                            ((MaleCharacter *)character)->executeState();
                            break;
                        case GROUND_TYPE::QUARRY:
                        case GROUND_TYPE::LAKE:
                        case GROUND_TYPE::FOREST:
                        case GROUND_TYPE::FARM:
                            caseCollectionPoint(character, ground);
                            break;
                        default:
                            break;
                        }
                        j++;
                    }
                    else
                    {
                        turnCharacter(character, ground, i, j, number_ground_with_character, number_character_ground, is_ground_deleted);
                    }
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
void Game::turnCharacter(Character *character, Ground *ground, unsigned int &index_ground_with_character, unsigned int &index_character, unsigned int &number_ground_with_character, unsigned int &number_character_ground, bool &is_ground_deleted)
{
    Character *temp_character;
    unsigned int x, y;
    temp_character = new MaleCharacter(*(MaleCharacter *)character);

    x = ground->getPosition(map.getColumnNumber()).getAbscissa();
    y = ground->getPosition(map.getColumnNumber()).getOrdinate();
    if (!movementOrdinate(temp_character, ground, x, y, index_character, index_ground_with_character, number_ground_with_character, number_character_ground, is_ground_deleted))
    {
        if (!movementAbscissa(temp_character, ground, x, y, index_character, index_ground_with_character, number_ground_with_character, number_character_ground, is_ground_deleted))
        {
            index_character++;
        }
    }
}

bool Game::movementOrdinate(Character *temp_character, Ground *ground, unsigned int x, unsigned int y, unsigned int &index_character, unsigned int &index_ground_with_character, unsigned int &number_ground_with_character, unsigned int &number_character_ground, bool &is_ground_deleted)
{
    bool movement_possible = false;
    if (y < (((MaleCharacter *)temp_character)->getDirection().getOrdinate()))
    {
        movement_possible = movementCharacter(temp_character, ground, x, y + 1, index_character, index_ground_with_character, number_ground_with_character, number_character_ground, is_ground_deleted);
    }
    else if (y > (((MaleCharacter *)temp_character)->getDirection().getOrdinate()))
    {
        movement_possible = movementCharacter(temp_character, ground, x, y - 1, index_character, index_ground_with_character, number_ground_with_character, number_character_ground, is_ground_deleted);
    }
    return movement_possible;
}

bool Game::movementAbscissa(Character *temp_character, Ground *ground, unsigned int x, unsigned int y, unsigned int &index_character, unsigned int &index_ground_with_character, unsigned int &number_ground_with_character, unsigned int &number_character_ground, bool &is_ground_deleted)
{
    bool movement_possible = false;
    if (x < (((MaleCharacter *)temp_character)->getDirection().getAbscissa()))
    {
        movement_possible = movementCharacter(temp_character, ground, x + 1, y, index_character, index_ground_with_character, number_ground_with_character, number_character_ground, is_ground_deleted);
    }
    else if (x > (((MaleCharacter *)temp_character)->getDirection().getAbscissa()))
    {
        movement_possible = movementCharacter(temp_character, ground, x - 1, y, index_character, index_ground_with_character, number_ground_with_character, number_character_ground, is_ground_deleted);
    }
    return movement_possible;
}
bool Game::movementCharacter(Character *temp_character, Ground *ground, unsigned int x, unsigned int y, unsigned int &index_character, unsigned int &index_ground_with_character, unsigned int &number_ground_with_character, unsigned int &number_character_ground, bool &is_ground_deleted)
{
    bool movement_possible = false;
    Ground *next_place;
    next_place = map.getGroundGrid(x, y);
    if ((next_place->getVectorSize() == 0) || ((next_place->getVectorSize() != 0) && (next_place->getCharacter(0)->getCharacterTeam() == temp_character->getCharacterTeam())))
    {
        movement_possible = true;
        ground->removeCharacter(index_character);
        number_character_ground--;
        if (ground->getVectorSize() == 0)
        {
            is_ground_deleted = true;
            number_ground_with_character--;
            map.removeGroundWithCharacter(index_ground_with_character);
        }

        next_place->addCharacter(temp_character);
        if (next_place->getVectorSize() == 1)
        {
            map.addGroundWithCharacter(next_place);
        }
    }

    return movement_possible;
}
double Game::euclidienneDistance(const StructCoordinates &a, const StructCoordinates &b)
{

    double substrate_abscissa = (b.getAbscissa() > a.getAbscissa()) ? b.getAbscissa() - a.getAbscissa() : a.getAbscissa() - b.getAbscissa();
    double substrate_ordinate = (b.getOrdinate() > a.getOrdinate()) ? b.getOrdinate() - a.getOrdinate() : a.getOrdinate() - b.getOrdinate();
    return sqrt(pow(substrate_abscissa, 2) + pow(substrate_ordinate, 2));
}




void Game::caseCollectionPoint(Character *character, Ground *ground) /* ToDO : si tout est vide ?? */
{
    unsigned int work_time = Constantes::CONFIG_SIMU["workTimeSpeciality"];
    if (ground->getGroundType() != (GROUND_TYPE)((MaleCharacter *)character)->getSpeciality())
    {
        work_time = Constantes::CONFIG_SIMU["workTimeNotSpeciality"];
    }

    ((MaleCharacter *)character)->incrementTimeAtWork();
    if (((MaleCharacter *)character)->getTimeAtWork() == 1)
    {
        ((MaleCharacter *)character)->setCharacterCurrentState(STATE::GOING_TO_TOWN_HALL);
        ((MaleCharacter *)character)->setTypeRessourceTransported(ground->getGroundType());
    }
    else if (((MaleCharacter *)character)->getTimeAtWork() > work_time)
    {
        ((MaleCharacter *)character)->resetTimeAtWork();
        ((MaleCharacter *)character)->setDirection(character->getCharacterTeam(), map.getColumnNumber());
    }
}
bool Game::deathOfCharacter(Character *character, unsigned int i, unsigned int &j)
{
    bool dead = false;
    if (character->isDead(turn) || character->decrementCharacterLife())
    {
        dead = true;
        map.getGroundWithCharacter(i)->removeCharacter(j);
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
            new_character = new MaleCharacter(turn, character->getCharacterTeam(), map.getColumnNumber());
        }
        else
        {
            new_character = new FemaleCharacter(turn, character->getCharacterTeam());
        }
        map.getGroundGrid(new_character->getCharacterTeam())->addCharacter(new_character);
    }
    ((FemaleCharacter *)character)->setTimePregnancy(Date());
    ((FemaleCharacter *)character)->randomBabyPerPregnancy();

    number_of_birth_this_turn += ((FemaleCharacter *)character)->getBabyPerPregnancy();
    number_of_birth_total += ((FemaleCharacter *)character)->getBabyPerPregnancy();
}

void Game::display(std::ostream &os) const noexcept
{
    map.display();
    //map.displayMap();
    //map.displayCharacter();
    os << "Number of birth this turn : " << number_of_birth_this_turn << std::endl;
    os << "Number of death this turn : " << number_of_death_this_turn << std::endl;
    os << "Total birth : " << number_of_birth_total << std::endl;
    os << "Total death : " << number_of_death_total << std::endl;
}


