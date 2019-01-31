#include "../header/StateMovement.hpp"
#include "../header/StateAddingRessources.hpp"
#include "../header/StateWorkingCollectionPoint.hpp"

StateMovement::StateMovement()
{
}

StateMovement::~StateMovement()
{
}
StateMovement *StateMovement::clone()
{
    return new StateMovement();
}
void StateMovement::run(Game &, Grid &map, Ground *ground, MaleCharacter *character, unsigned int &index_ground_with_character, unsigned int &index_character, unsigned int &number_ground_with_character, unsigned int &number_character_ground, bool &is_ground_deleted) const
{
    Character *temp_character;
    unsigned int x, y;
    temp_character = new MaleCharacter(*character);

    x = ground->getPosition(map.getColumnNumber()).getAbscissa();
    y = ground->getPosition(map.getColumnNumber()).getOrdinate();
    if (!movementOrdinate(map, temp_character, ground, x, y, index_character, index_ground_with_character, number_ground_with_character, number_character_ground, is_ground_deleted))
    {
        if (!movementAbscissa(map, temp_character, ground, x, y, index_character, index_ground_with_character, number_ground_with_character, number_character_ground, is_ground_deleted))
        {
            index_character++;
        }
    }
}

bool StateMovement::movementOrdinate(Grid &map, Character *temp_character, Ground *ground, unsigned int x, unsigned int y, unsigned int &index_character, unsigned int &index_ground_with_character, unsigned int &number_ground_with_character, unsigned int &number_character_ground, bool &is_ground_deleted) const
{
    bool movement_possible = false;
    if (y < (((MaleCharacter *)temp_character)->getDirection().getOrdinate()))
    {
        movement_possible = movementCharacter(map, temp_character, ground, x, y + 1, index_character, index_ground_with_character, number_ground_with_character, number_character_ground, is_ground_deleted);
    }
    else if (y > (((MaleCharacter *)temp_character)->getDirection().getOrdinate()))
    {
        movement_possible = movementCharacter(map, temp_character, ground, x, y - 1, index_character, index_ground_with_character, number_ground_with_character, number_character_ground, is_ground_deleted);
    }
    return movement_possible;
}

bool StateMovement::movementAbscissa(Grid &map, Character *temp_character, Ground *ground, unsigned int x, unsigned int y, unsigned int &index_character, unsigned int &index_ground_with_character, unsigned int &number_ground_with_character, unsigned int &number_character_ground, bool &is_ground_deleted) const
{
    bool movement_possible = false;
    if (x < (((MaleCharacter *)temp_character)->getDirection().getAbscissa()))
    {
        movement_possible = movementCharacter(map, temp_character, ground, x + 1, y, index_character, index_ground_with_character, number_ground_with_character, number_character_ground, is_ground_deleted);
    }
    else if (x > (((MaleCharacter *)temp_character)->getDirection().getAbscissa()))
    {
        movement_possible = movementCharacter(map, temp_character, ground, x - 1, y, index_character, index_ground_with_character, number_ground_with_character, number_character_ground, is_ground_deleted);
    }
    return movement_possible;
}
bool StateMovement::movementCharacter(Grid &map, Character *temp_character, Ground *ground, unsigned int x, unsigned int y, unsigned int &index_character, unsigned int &index_ground_with_character, unsigned int &number_ground_with_character, unsigned int &number_character_ground, bool &is_ground_deleted) const
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
        if (((MaleCharacter *)temp_character)->getDirection() == next_place->getPosition(map.getColumnNumber()))
        {
            GROUND_TYPE ground_type = next_place->getGroundType();
            if (ground_type == GROUND_TYPE::TOWN_HALL)
            {
                ((MaleCharacter *)temp_character)->setCharacterCurrentState(new StateAddingRessources());
            }
            else if ( (ground_type== GROUND_TYPE::QUARRY)
            ||(ground_type== GROUND_TYPE::FOREST)
            ||(ground_type== GROUND_TYPE::FARM)
            ||(ground_type== GROUND_TYPE::LAKE))
            {
                ((MaleCharacter *)temp_character)->setCharacterCurrentState(new StateWorkingCollectionPoint());
            }
        }
    }

    return movement_possible;
}
