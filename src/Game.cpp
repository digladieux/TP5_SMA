#include "../header/Game.hpp"
#include "../header/FemaleCharacter.hpp"
#include "../header/mt19937ar.h"

Game::Game(const Grid &grid, const Date &date) : map(grid), turn(date) {}

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
    Ground *ground;
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
                        /*LE DEPLACEMENT */
                    }
                    else
                    {
                        move(grid, character, ground);
                    }
                }
                /* RECHERCHE DE COUPLE */
            }
        }
    }
}
// C'est pas la direction qu'on doit inc c'est supprimer dans le vect
void Game::move(Grid &grid, Character *character, Ground *ground)
{
    if (((MaleCharacter *)character)->getDirection().getAbscissa() == ground->getPosition(grid.getColumnNumber()).getAbscissa())
    {
        if ((((MaleCharacter *)character)->getDirection().getOrdinate()) < ground->getPosition(grid.getColumnNumber()).getOrdinate())
        {
            ((MaleCharacter *)character)->getDirection().incrementOrdinate();
        }
        else
        {
            ((MaleCharacter *)character)->getDirection().decrementOrdinate();
        }
    }
    else if ((((MaleCharacter *)character)->getDirection().getAbscissa()) < ground->getPosition(grid.getColumnNumber()).getAbscissa())
    {
        ((MaleCharacter *)character)->getDirection().incrementAbscissa();
    }
    else
    {
        ((MaleCharacter *)character)->getDirection().decrementAbscissa();
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
