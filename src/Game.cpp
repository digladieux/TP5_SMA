#include "../header/Game.hpp"
#include "../header/FemaleCharacter.hpp"
#include "../header/mt19937ar.h"
#include <unistd.h>

Game::Game(const Grid &grid, const Date &date) : map(grid), turn(date) {}

void Game::run(Grid &grid, unsigned int round)
{
    system("clear");
    std::cout << "Tour 0" << std::endl;
    grid.displayMap();
    grid.displayCharacter();
    sleep(1);
    for (unsigned int i = 0; i < round; i++)
    {
        system("clear");
        std::cout << "Tour " << i + 1 << std::endl;
        lifeOfCharacter(grid);
        grid.displayMap();
        grid.displayCharacter();
        sleep(1);
    }
}

void Game::lifeOfCharacter(Grid &grid)
{
    Character *character , *temp_character;
    Ground *ground;
    unsigned int x, y;
    for (unsigned int i = 0; i < grid.getSizeVectorGroundWithCharacter(); i++)
    {
        ground = grid.getGroundWithCharacter(i);
        for (unsigned int j = 0; j < ground->getVectorSize(); j++)
        {

            character = ground->getCharacter(j);

            if (!deathOfCharacter(grid, character, i, j))
            {
                if (character->getCharacterGender() == SEX::FEMALE) /* pas enfant a faire */
                {
                    if (((FemaleCharacter *)character)->getMonthNumberPregnancy() == 9)
                    {
                        birthOfCharacter(grid, character);
                    }
                    incrementMonthGestationIfPregnant(character);
                }

                else if (character->getCharacterGender() == SEX::MALE) /* pas enfant a gerer */
                {
                    if (((MaleCharacter *)character)->getDirection() == ground->getPosition(grid.getColumnNumber()))
                    {

                        ((MaleCharacter *)character)->setDirection(5, 5);
                    }
                    else
                    {
                        temp_character = new MaleCharacter(*(MaleCharacter *)character);
                        ground->removeCharacter(j);

                        x = ground->getPosition(grid.getColumnNumber()).getAbscissa();
                        y = ground->getPosition(grid.getColumnNumber()).getOrdinate();
                        if (((MaleCharacter *)temp_character)->getDirection().getAbscissa() == ground->getPosition(grid.getColumnNumber()).getAbscissa())
                        {
                            if (ground->getPosition(grid.getColumnNumber()).getOrdinate() < (((MaleCharacter *)temp_character)->getDirection().getOrdinate()))
                            {
                                map.getGroundGrid(x + 1, y)->addCharacter(temp_character);
                            }
                            else
                            {
                                map.getGroundGrid(x - 1, y)->addCharacter(temp_character);
                            }
                        }
                        else if (ground->getPosition(grid.getColumnNumber()).getAbscissa() < (((MaleCharacter *)temp_character)->getDirection().getAbscissa()))
                        {
                            map.getGroundGrid(x, y + 1)->addCharacter(temp_character);
                        }
                        else
                        {
                            map.getGroundGrid(x, y - 1)->addCharacter(temp_character);
                        }
                    }
                }
                /* RECHERCHE DE COUPLE */
            }
        }
    }
}

bool Game::deathOfCharacter(Grid &grid, Character *character, unsigned int i, unsigned int &j)
{
    bool dead = false;
    if (character->isDead(turn))
    {
        dead = true;
        grid.getGroundWithCharacter(i)->removeCharacter(j);
        j--;
    }
    return dead;
}

void Game::birthOfCharacter(Grid &grid, Character *character)
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
        grid.getGroundGrid(character->getCharacterTeam())->addCharacter(new_character);
    }
}

void Game::incrementMonthGestationIfPregnant(Character *character)
{
    if (((FemaleCharacter *)character)->getMonthNumberPregnancy() != 0)
    {
        ((FemaleCharacter *)character)->setMonthPregnancy();
    }
}
