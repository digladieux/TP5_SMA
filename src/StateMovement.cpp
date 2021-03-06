/**
 * \file StateMovement.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation de la classe StateMovement
 * \date 2018-12-03
 */

#include "../header/StateMovement.hpp"
#include "../header/StateAddingRessources.hpp"
#include "../header/StateWorkingCollectionPoint.hpp"
/**
 * \fn StateMovement::StateMovement()
 * \brief Constructeur par default de la classe StateMovement
 */

StateMovement::StateMovement(){}

/**
 * \fn StateMovement::~StateMovement()
 * \brief Destructeur de la classe StateMovement
 */
StateMovement::~StateMovement(){}

/**
 * \fn StateMovement* StateMovement::clone() const
 * \brief Constructeur dynamique de la classe StateMovement. C'est un moyen de construire un constructeur virtuel. Quand on ne connait pas le type de State que l'on a et que l'on veut faire une copie de ce dernier, on utilise cette methode
 */
StateMovement *StateMovement::clone()
{
    return new StateMovement();
}

/**
 * \fn void StateMovement::run(Game &, Grid &map, Ground *ground, MaleCharacter *character, unsigned int &index_ground_with_character, unsigned int &index_character, unsigned int &number_ground_with_character, unsigned int &number_character_ground, bool &is_ground_deleted) const
 * \brief Lancement de l'etat Deplacement par le personnage
 * \param &map Carte ou se trouve le personnage
 * \param *ground Terrain ou se trouve le personnage
 * \param *character Personnage en question
 * \param &index_ground_with_character Indice qui correspond a la position du terrain ou se trouve le personnage dans le vecteur de terrain
 * \param &index_character Indice qui correspond a la position du personnage dans le vecteur de personnage
 * \param &number_ground_with_character Nombre de terrain avec des personnage
 * \param &number_character_ground Nombre de personnage sur ce terrain
 * \param &is_ground_deleted Boolean pour savoir si le terrain a ete supprime
 */
void StateMovement::run(Game &, Grid &map, Ground *ground, MaleCharacter *character, unsigned int &index_ground_with_character, unsigned int &index_character, unsigned int &number_ground_with_character, unsigned int &number_character_ground, bool &is_ground_deleted) const
{
    unsigned int x, y;

    x = ground->getPosition(map.getColumnNumber()).getAbscissa();
    y = ground->getPosition(map.getColumnNumber()).getOrdinate();
    if (!movementOrdinate(map, character, ground, x, y, index_character, index_ground_with_character, number_ground_with_character, number_character_ground, is_ground_deleted))
    {
        if (!movementAbscissa(map, character, ground, x, y, index_character, index_ground_with_character, number_ground_with_character, number_character_ground, is_ground_deleted))
        {
            index_character++;
        }
    }
}

bool StateMovement::movementOrdinate(Grid &map, Character *temp_character, Ground *ground, unsigned int x, unsigned int y, unsigned int &index_character, unsigned int &index_ground_with_character, unsigned int &number_ground_with_character, unsigned int &number_character_ground, bool &is_ground_deleted) const
{
    bool movement_possible = false;
    if (y < ((static_cast<MaleCharacter*>(temp_character))->getDirection().getOrdinate()))
    {
        movement_possible = movementCharacter(map, temp_character, ground, x, y + 1, index_character, index_ground_with_character, number_ground_with_character, number_character_ground, is_ground_deleted);
    }
    else if (y > ((static_cast<MaleCharacter*>(temp_character))->getDirection().getOrdinate()))
    {
        movement_possible = movementCharacter(map, temp_character, ground, x, y - 1, index_character, index_ground_with_character, number_ground_with_character, number_character_ground, is_ground_deleted);
    }
    return movement_possible;
}

bool StateMovement::movementAbscissa(Grid &map, Character *temp_character, Ground *ground, unsigned int x, unsigned int y, unsigned int &index_character, unsigned int &index_ground_with_character, unsigned int &number_ground_with_character, unsigned int &number_character_ground, bool &is_ground_deleted) const
{
    bool movement_possible = false;
    if (x < ((static_cast<MaleCharacter*>(temp_character))->getDirection().getAbscissa()))
    {
        movement_possible = movementCharacter(map, temp_character, ground, x + 1, y, index_character, index_ground_with_character, number_ground_with_character, number_character_ground, is_ground_deleted);
    }
    else if (x > ((static_cast<MaleCharacter*>(temp_character))->getDirection().getAbscissa()))
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
        if ((static_cast<MaleCharacter*>(temp_character))->getDirection() == next_place->getPosition(map.getColumnNumber()))
        {
            GROUND_TYPE ground_type = next_place->getGroundType();
            if (ground_type == GROUND_TYPE::TOWN_HALL)
            {
                (static_cast<MaleCharacter*>(temp_character))->setCharacterCurrentState(new StateAddingRessources());
            }
            else if ( (ground_type== GROUND_TYPE::QUARRY)
            ||(ground_type== GROUND_TYPE::FOREST)
            ||(ground_type== GROUND_TYPE::FARM)
            ||(ground_type== GROUND_TYPE::LAKE))
            {
                (static_cast<MaleCharacter*>(temp_character))->setCharacterCurrentState(new StateWorkingCollectionPoint());
            }
        }
    }

    return movement_possible;
}
