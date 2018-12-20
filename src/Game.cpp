#include "../header/Game.hpp"
#include "../header/FemaleCharacter.hpp"
#include "../header/mt19937ar.h"

Game::Game(const Grid &grid, const Date &date) : map(grid), turn(date){}

void Game::run(Grid &grid, unsigned int round)
{
    for (unsigned int i = 0; i < round; i++)
    {
        lifeOfCharacter(grid);
    }
}

void Game::lifeOfCharacter(Grid &grid)
{
    Character *character;
    for (unsigned int i = 0; i < grid.getSizeVectorGroundWithCharacter(); i++)
    {
        for (unsigned int j = 0; j < grid.getGroundWithCharacter(i)->getVectorSize(); j++)
        {
            character = grid.getGroundWithCharacter(i)->getCharacter(j);

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
                    if (((((MaleCharacter *)character)->getDirection().getAbscissa() == -1) && (((MaleCharacter *)character)->getDirection().getOrdinate() == -1)) || (grid.getDirectionCharacter(((MaleCharacter *)character)->getDirection()) == grid.getGroundGrid(grid.getGroundWithCharacter(i)->getGroundId())))
                    {
                        /*LE DEPLACEMENT */
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
