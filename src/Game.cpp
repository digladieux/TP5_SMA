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

Game::Game(std::vector<unsigned int> & map_choice, std::vector<unsigned int> &character_choice, unsigned int config_choice, const Date &date) : map(map_choice, character_choice), turn(date), number_of_birth_this_turn(0), number_of_birth_total(0), number_of_death_this_turn(0), number_of_death_total(0)
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
        if (i == 1082)
        {
            std::cout <<"kk";
        }
        lifeOfCharacter();
        display();
        usleep(10000);
    }
}

void Game::lifeOfCharacter()
{
    Character *character;
    Ground *ground;
    unsigned int number_ground_with_character = map.getSizeVectorGroundWithCharacter() , 
                    number_character_ground,
                    i = 0,
                    j = 0 ;
    bool is_ground_deleted ;

    while (i < number_ground_with_character)
    {
        is_ground_deleted = false ;
        j = 0 ;
        ground = map.getGroundWithCharacter(i);
        number_character_ground = ground->getVectorSize() ;
        while(j < number_character_ground)
        {

            character = ground->getCharacter(j);

            if (!deathOfCharacter(character, i, j))
            {
	            if (character->getCharacterGender() == SEX::FEMALE && (character->getCharacterAge(turn) >= Constantes::CONFIG_SIMU["majority"]) && (character->getCharacterAge(turn) <= Constantes::CONFIG_SIMU["menopause"]))
                {

                    if (((FemaleCharacter *)character)->getBabyPerPregnancy() == 0)
                    {
                        ((FemaleCharacter *)character)->randomBabyPerPregnancy();
                        if (((FemaleCharacter *)character)->getBabyPerPregnancy() == 0)
                        {

                            ((FemaleCharacter *)character)->setTimePregnancy(turn);
                        }
                    }
                    else if (((FemaleCharacter *)character)->getMonthPregnancy(turn) == 9)
                    {
                        birthOfCharacter(character);
                    }
                        j++ ;   
                }

                else if ((character->getCharacterGender() == SEX::MALE) && (character->getCharacterAge(turn) >= Constantes::CONFIG_SIMU["majority"]))
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
                        j++ ;   

                    }
                    else
                    {
                        turnCharacter(character, ground, i, j, number_ground_with_character, number_character_ground,is_ground_deleted);
                        
                    }
                }
                /* RECHERCHE DE COUPLE */
            }
            else
            {
                number_character_ground -- ;
                number_of_death_total++;
                number_of_death_this_turn++;
            }
        }
        if (!is_ground_deleted)
        {
            i++ ;
        }
    }
}
void Game::turnCharacter(Character *character, Ground *ground, unsigned int& index_ground_with_character, unsigned int& index_character, unsigned int& number_ground_with_character, unsigned int& number_character_ground, bool& is_ground_deleted )
{
    Character *temp_character;
    unsigned int x, y;
    temp_character = new MaleCharacter(*(MaleCharacter *)character);

    x = ground->getPosition(map.getColumnNumber()).getAbscissa();
    y = ground->getPosition(map.getColumnNumber()).getOrdinate();
    if (!movementOrdinate(temp_character, ground, x, y, index_character, index_ground_with_character,number_ground_with_character,number_character_ground, is_ground_deleted))
    {
        if(!movementAbscissa(temp_character, ground, x, y, index_character, index_ground_with_character, number_ground_with_character, number_character_ground, is_ground_deleted))
        {
            index_character ++ ;
        }
    }
}

bool Game::movementOrdinate(Character *temp_character, Ground *ground, unsigned int x, unsigned int y, unsigned int& index_character, unsigned int& index_ground_with_character, unsigned int& number_ground_with_character, unsigned int& number_character_ground, bool& is_ground_deleted )
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

bool Game::movementAbscissa(Character *temp_character, Ground *ground, unsigned int x, unsigned int y, unsigned int& index_character, unsigned int& index_ground_with_character,  unsigned int& number_ground_with_character, unsigned int& number_character_ground, bool& is_ground_deleted )
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
bool Game::movementCharacter(Character *temp_character, Ground *ground, unsigned int x, unsigned int y, unsigned int& index_character, unsigned int& index_ground_with_character,  unsigned int& number_ground_with_character, unsigned int& number_character_ground, bool& is_ground_deleted )
{
    bool movement_possible = false;
    Ground *next_place;
    next_place = map.getGroundGrid(x, y);
    if ((next_place->getVectorSize() == 0) || ((next_place->getVectorSize() != 0) && (next_place->getCharacter(0)->getCharacterTeam() == temp_character->getCharacterTeam())))
    {
        movement_possible = true;
        ground->removeCharacter(index_character);
        number_character_ground -- ;
        if (ground->getVectorSize() == 0)
        {
            is_ground_deleted = true ;
            number_ground_with_character -- ;
            map.removeGroundWithCharacter(index_ground_with_character);
        }

        next_place->addCharacter(temp_character);
        if (next_place->getVectorSize() == 1)
        {
            map.addGroundWithCharacter(next_place);
        }
    }
    else
    {
        // TODO : aller a gauche ou droite ou bas 
    }
    return movement_possible;
}
double Game::euclidienneDistance(const StructCoordinates &a, const StructCoordinates &b)
{

    double substrate_abscissa = (b.getAbscissa() > a.getAbscissa()) ? b.getAbscissa() - a.getAbscissa() : a.getAbscissa() - b.getAbscissa();
    double substrate_ordinate = (b.getOrdinate() > a.getOrdinate()) ? b.getOrdinate() - a.getOrdinate() : a.getOrdinate() - b.getOrdinate();
    return sqrt(pow(substrate_abscissa, 2) + pow(substrate_ordinate, 2));
}
void Game::caseTownHall(Character *character, Ground *ground) /* ToDO : si tout est vide ?? */
{
    Ground *collection_point, *other_collection_point = nullptr;
    unsigned int k = 0, number_ressource = Constantes::CONFIG_SIMU["ressourceSpecialityNumber"];
    double distance_min_primer_collection_point = std::numeric_limits<double>::max(), distance_min_secondary_collection_point = std::numeric_limits<double>::max();
    bool is_collection_point = false;
    if ((JOB)((MaleCharacter *)character)->getTypeRessourceTransported() != ((MaleCharacter *)character)->getSpeciality())
    {
        number_ressource = Constantes::CONFIG_SIMU["ressourceNotSpecialityNumber"];
    }
    ((TownHall *)ground)->addRessources(((MaleCharacter *)character)->getTypeRessourceTransported(), number_ressource);
/* TODO : faire utiliser le state pour un personnage masculin */
    /*unsigned int ressource_level_up = Constantes::CONFIG_SIMU["levelUp"] ;
    if((((TownHall *)ground)->getWoodNumber() >= ((TownHall *)ground)->getLevel() * ressource_level_up) && (((TownHall *)ground)->getRockNumber() >= ((TownHall *)ground)->getLevel() * ressource_level_up))
    {
        ((MaleCharacter*)character)->setCharacterCurrentState(STATE::BUILDING) ;
        ((MaleCharacter *)character)->incrementTimeAtWork();

    }


    else if ( ((MaleCharacter *)character)->getTimeAtWork() > Constantes::CONFIG_SIMU["workTimeNotSpeciality"])
    {
        ((TownHall*)ground)->removeRockNumber((((TownHall *)ground)->getLevel() *  ressource_level_up));
        ((TownHall*)ground)->removeWoodNumber((((TownHall *)ground)->getLevel() * ressource_level_up));        
        ((MaleCharacter *)character)->resetTimeAtWork();
        ((TownHall *)ground)->incrementLevel();
    
    }
    ????? switch state ?    
    else
    {*/
        while (k < map.getSizeVectorGroundWithCollectionPoint())
        { /* TODO : s'arrete si 2 ressource low */
            collection_point = map.getGroundWithCollectionPoint(k);
            if ((collection_point->getGroundType() == (GROUND_TYPE)((MaleCharacter *)character)->getSpeciality()) && (euclidienneDistance(collection_point->getPosition(map.getColumnNumber()), ground->getPosition(map.getColumnNumber())) < distance_min_primer_collection_point) && (((CollectionPoint *)collection_point)->getRessourcesNumber() > Constantes::CONFIG_SIMU["ressourceSpecialityNumber"]))
            {
                ((MaleCharacter *)character)->setDirection(collection_point->getGroundId(), map.getColumnNumber());
                is_collection_point = true;
                distance_min_primer_collection_point = euclidienneDistance(collection_point->getPosition(map.getColumnNumber()), ground->getPosition(map.getColumnNumber()));
            }
            else
            {

                if ((!is_collection_point) && (euclidienneDistance(collection_point->getPosition(map.getColumnNumber()), ground->getPosition(map.getColumnNumber())) < distance_min_secondary_collection_point) && (((CollectionPoint *)collection_point)->getRessourcesNumber() > Constantes::CONFIG_SIMU["ressourceNotSpecialityNumber"]))
                {
                    other_collection_point = collection_point;
                    distance_min_secondary_collection_point = euclidienneDistance(collection_point->getPosition(map.getColumnNumber()), ground->getPosition(map.getColumnNumber()));
                }
            }
            k++;
        }
        if (!is_collection_point)
        {
            ((MaleCharacter *)character)->setDirection(other_collection_point->getGroundId(), map.getColumnNumber());
        }
        if (other_collection_point == nullptr)
        {
            // throw plus de ressource dispo 
        }
    //}
}

void Game::caseCollectionPoint(Character *character, Ground *ground)
{
    unsigned int work_time = Constantes::CONFIG_SIMU["workTimeSpeciality"];
    if (ground->getGroundType() != (GROUND_TYPE)((MaleCharacter *)character)->getSpeciality())
    {
        work_time = Constantes::CONFIG_SIMU["workTimeNotSpeciality"];
    }
    ((MaleCharacter *)character)->incrementTimeAtWork();
    if (((MaleCharacter *)character)->getTimeAtWork() == 1)
    {

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
        if (genrand_real1() < Constantes::CONFIG_SIMU["chanceMale"])
        {
            new_character = new MaleCharacter(turn, map.getColumnNumber(), character->getCharacterTeam());
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
