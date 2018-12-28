#include "../header/Game.hpp"
#include "../header/FemaleCharacter.hpp"
#include "../header/TownHall.hpp"
#include "../header/mt19937ar.h"
#include <unistd.h>

Game::Game(const Grid &grid, const Date &date) : map(grid), turn(date) {}

void Game::run(unsigned int round)
{
    system("clear");
    std::cout << "Tour 0" << std::endl;
    map.displayMap();
    map.displayCharacter();
    sleep(1);
    for (unsigned int i = 0; i < round; i++)
    {
        system("clear");
        std::cout << "Tour " << i + 1 << std::endl;
        lifeOfCharacter();
        map.displayMap();
        map.displayCharacter();
        sleep(1);
    }
}

void Game::lifeOfCharacter()
{
    Character *character;
    Ground *ground;
    for (unsigned int i = 0; i < map.getSizeVectorGroundWithCharacter(); i++)
    {
        ground = map.getGroundWithCharacter(i);
        for (unsigned int j = 0; j < ground->getVectorSize(); j++)
        {

            character = ground->getCharacter(j);

            if (!deathOfCharacter(character, i, j))
            {
                if (character->getCharacterGender() == SEX::FEMALE) /* pas enfant a faire */
                {
                    if (((FemaleCharacter *)character)->getMonthNumberPregnancy() == 9)
                    {
                        birthOfCharacter(character);
                    }
                    incrementMonthGestationIfPregnant(character);
                }

                else if (character->getCharacterGender() == SEX::MALE) /* pas enfant a gerer */
                {
                    if (((MaleCharacter *)character)->getDirection() == ground->getPosition(map.getColumnNumber()))
                    {
                        switch (ground->getGroundType())
                        {
                        case GROUND_TYPE::TOWN_HALL:
                            caseTownHall(character, ground);
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
                    }
                    else
                    {
                        movementCharacter(character, ground, i, j);
                    }
                }
                /* RECHERCHE DE COUPLE */
            }
        }
    }
}
void Game::movementCharacter(Character *character, Ground *ground, unsigned int index_ground_with_character, unsigned int index_character)
{
    Character *temp_character;
    Ground *next_place;
    unsigned int x, y;
    temp_character = new MaleCharacter(*(MaleCharacter *)character);
    ground->removeCharacter(index_character);
    if (ground->getVectorSize() == 0)
    {
        map.removeGroundWithCharacter(index_ground_with_character);
    }

    x = ground->getPosition(map.getColumnNumber()).getAbscissa();
    y = ground->getPosition(map.getColumnNumber()).getOrdinate();
    if (((MaleCharacter *)temp_character)->getDirection().getAbscissa() == x)
    {
        if (y < (((MaleCharacter *)temp_character)->getDirection().getOrdinate()))
        {
            next_place = map.getGroundGrid(x, y + 1);
            next_place->addCharacter(temp_character);
            map.addGroundWithCharacter(next_place);
        }
        else
        {
            next_place = map.getGroundGrid(x, y - 1);
            next_place->addCharacter(temp_character);
            map.addGroundWithCharacter(next_place);
        }
    }
    else if (x < (((MaleCharacter *)temp_character)->getDirection().getAbscissa()))
    {
        next_place = map.getGroundGrid(x + 1, y);
        next_place->addCharacter(temp_character);
        map.addGroundWithCharacter(next_place);
    }
    else
    {
        next_place = map.getGroundGrid(x - 1, y);
        next_place->addCharacter(temp_character);
        map.addGroundWithCharacter(next_place);
    }
}
void Game::caseTownHall(Character *character, Ground *ground)
{
    Ground *collection_point, *low_stock_collection_point;
    unsigned int k;
    bool is_collection_point;
    GROUND_TYPE low_stock;

    ((TownHall *)ground)->addRessources(((MaleCharacter *)character)->getTypeRessourceTransported(), 2); /* RAND */
    k = 0;
    is_collection_point = false;
    low_stock = ((TownHall *)ground)->lowStock();

    while ((!is_collection_point) && (k < map.getSizeVectorGroundWithCollectionPoint()))
    {
        collection_point = map.getGroundWithCollectionPoint(k);
        if (compare(collection_point->getGroundType(), ((MaleCharacter *)character)->getSpeciality()))
        {
            ((MaleCharacter *)character)->setDirection(collection_point->getGroundId(), map.getColumnNumber());
            is_collection_point = true;
        }
        else
        {
            if (low_stock == collection_point->getGroundType()) /* TODO : distance plus courte */
            {
                low_stock_collection_point = collection_point;
            }
            k++;
        }
    }
    if (!is_collection_point)
    {
        ((MaleCharacter *)character)->setDirection(low_stock_collection_point->getGroundId(), map.getColumnNumber());
    }
}

void Game::caseCollectionPoint(Character *character, Ground *ground)
{
    ((MaleCharacter *)character)->incrementTimeAtWork();
    if (((MaleCharacter *)character)->getTimeAtWork() == 1)
    {
        ((MaleCharacter *)character)->setTypeRessourceTransported(ground->getGroundType());
    }
    else if (((MaleCharacter *)character)->getTimeAtWork() > 5) /* RAND */
    {

        ((MaleCharacter *)character)->resetTimeAtWork();
        ((MaleCharacter *)character)->setDirection(character->getCharacterTeam(), map.getColumnNumber());
    }
}
bool Game::deathOfCharacter(Character *character, unsigned int i, unsigned int &j)
{
    bool dead = false;
    if (character->isDead(turn))
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
        if (genrand_real1() < 0.5)
        {
            new_character = new MaleCharacter(turn);
        }
        else
        {
            new_character = new FemaleCharacter(turn);
        }
        map.getGroundGrid(character->getCharacterTeam())->addCharacter(new_character);
    }
}

void Game::incrementMonthGestationIfPregnant(Character *character)
{
    if (((FemaleCharacter *)character)->getMonthNumberPregnancy() != 0)
    {
        ((FemaleCharacter *)character)->setMonthPregnancy();
    }
}

bool Game::compare(GROUND_TYPE ground_type, JOB job)
{
    return (((ground_type == GROUND_TYPE::FARM) && (job == JOB::FARMER)) || ((ground_type == GROUND_TYPE::LAKE) && (job == JOB::FISHERMAN)) || ((ground_type == GROUND_TYPE::FOREST) && (job == JOB::LUMBERJACK)) || ((ground_type == GROUND_TYPE::QUARRY) && (job == JOB::QUARRY_MAN)));
}
