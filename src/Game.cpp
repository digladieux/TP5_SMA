#include "../header/Game.hpp"
#include "../header/FemaleCharacter.hpp"
#include "../header/mt19937ar.h"
void run(Grid &grid, unsigned int round)
{
    for (unsigned int i = 0; i < round; i++)
    {
        game(grid);
    }
}

void game(Grid &grid)
{
    /* On teste si les gens meurent */
    lifeOfCharacter(grid);
}

void lifeOfCharacter(Grid &grid)
{
    Character *character;
    for (unsigned int i = 0; i < grid.getSizeVectorGroundWithCharacter(); i++)
    {
        for (unsigned int j = 0; j < grid.getGroundWithCharacter(i)->getVectorSize(); j++)
        {
            character = grid.getGroundWithCharacter(i)->getCharacter(j);

            if (!deathOfCharacter(grid, character, i, j))
            {
                transitionToAdult(character);
                if (character->getCharacterGender() == SEX::FEMALE_CHARACTER_ADULT)
                {
                    if (((FemaleCharacter *)character)->getMonthNumberPregnancy() == 9)
                    {
                        birthOfCharacter(grid, character);
                    }
                    incrementMonthGestationIfPregnant(character);
                }

                if (character->getCharacterGender() == SEX::MALE_CHARACTER_ADULT)
                {
                    if (((((MaleCharacter *)character)->getDirection().abscissa == -1) && (((MaleCharacter *)character)->getDirection().ordinate == -1)) || (grid.getDirectionCharacter(((MaleCharacter *)character)->getDirection()) == grid.getGroundGrid(grid.getGroundWithCharacter(i)->getGroundId())))
                    {
                        /*LE DEPLACEMENT */
                    }
                }
                /* RECHERCHE DE COUPLE */
            }
        }
    }
}

bool deathOfCharacter(Grid &grid, Character *character, unsigned int i, unsigned int &j)
{
    bool dead = false;
    if (character->isDead())
    {
        dead = true;
        grid.getGroundWithCharacter(i)->removeCharacter(j);
        j--;
    }
    return dead;
}

void birthOfCharacter(Grid &grid, Character *character)
{
    Character *new_character;
    for (unsigned int i = 0; i < ((FemaleCharacter *)character)->getBabyPerPregnancy(); ++i)
    {
        if (genrand_real1() < 0.5)
        {
            new_character = new MaleCharacter();
        }
        else
        {
            new_character = new FemaleCharacter();
        }
        grid.getGroundGrid(character->getCharacterTeam())->addCharacter(new_character);
    }
}

void transitionToAdult(Character *character)
{
    character->incrementAge();
    if (character->getCharacterAge() == 18)
    {
        character->setCharacterGenderAdult();
    }
}

void incrementMonthGestationIfPregnant(Character *character)
{
    if (((FemaleCharacter *)character)->getMonthNumberPregnancy() != 0)
    {
        ((FemaleCharacter *)character)->setMonthPregnancy();
    }
}
