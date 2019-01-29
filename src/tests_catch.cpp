#include "../header/catch.hpp"
#include "../header/TownHall.hpp"
#include "../header/Ground.hpp"
#include "../header/Character.hpp"
#include "../header/MaleCharacter.hpp"
#include "../header/FemaleCharacter.hpp"
#include "../header/CollectionPoint.hpp"
#include "../header/Farm.hpp"
#include "../header/Forest.hpp"
#include "../header/Quarry.hpp"
#include "../header/Lake.hpp"
#include "../header/Grid.hpp"
#include "../header/Game.hpp"
#include "../header/Date.hpp"
#include "../header/json.hpp"
#include "../header/Menu.hpp"
#include "../header/Constantes.hpp"
#include "../header/Exception.hpp"
#include <string>
#include <fstream>
#include <iostream>
using json = nlohmann::json;
/*TODO : test sur les strategies et state */
/*TODO : verifier tous les commentaires partout plus rien ne marche */
/*TODO : test unitaire vie */
/*TODO : Si ressource specialite 2 fois plus grande que la plus petite, changer de destination */ 
/*TODO : trouver une fonction pour les faire mourrir */
TEST_CASE("Ground")
{
    Ground ground0;
    Ground ground1(GROUND_TYPE::LAKE);

    CHECK(0 == ground0.getGroundId());
    CHECK(1 == ground1.getGroundId());
    CHECK(GROUND_TYPE::LAND == ground0.getGroundType());
    CHECK(GROUND_TYPE::LAKE == ground1.getGroundType());
}

TEST_CASE("Town Hall")
{
    TownHall *town_hall_start = new TownHall();
    CHECK(0 == town_hall_start->getLevel());
    CHECK(0 == town_hall_start->getRockNumber());
    CHECK(0 == town_hall_start->getWoodNumber());
    CHECK(0 == town_hall_start->getFoodNumber());
    CHECK(0 == town_hall_start->getFishNumber());
    CHECK(2 == town_hall_start->getGroundId());

    TownHall *town_hall_in_game = new TownHall(5, 1, 2, 3, 6);
    CHECK(5 == town_hall_in_game->getLevel());
    CHECK(1 == town_hall_in_game->getRockNumber());
    CHECK(2 == town_hall_in_game->getWoodNumber());
    CHECK(3 == town_hall_in_game->getFoodNumber());
    CHECK(6 == town_hall_in_game->getFishNumber());
    CHECK(3 == town_hall_in_game->getGroundId());

    town_hall_in_game->incrementLevel();
    CHECK(true == town_hall_in_game->addRessources(TYPE_RESSOURCE_TRANSPORTED::ROCK, 2));
    CHECK(true == town_hall_in_game->addRessources(TYPE_RESSOURCE_TRANSPORTED::WOOD, 3));
    CHECK(true == town_hall_in_game->addRessources(TYPE_RESSOURCE_TRANSPORTED::FOOD, 6));
    CHECK(true == town_hall_in_game->addRessources(TYPE_RESSOURCE_TRANSPORTED::FISH, 5));
    CHECK(6 == town_hall_in_game->getLevel());
    CHECK(3 == town_hall_in_game->getRockNumber());
    CHECK(5 == town_hall_in_game->getWoodNumber());
    CHECK(9 == town_hall_in_game->getFoodNumber());
    CHECK(11 == town_hall_in_game->getFishNumber());

    CHECK(false == town_hall_in_game->addRessources(TYPE_RESSOURCE_TRANSPORTED::ROCK, -8));
    CHECK(false == town_hall_in_game->addRessources(TYPE_RESSOURCE_TRANSPORTED::WOOD, -2));
    CHECK(false == town_hall_in_game->addRessources(TYPE_RESSOURCE_TRANSPORTED::FOOD, -10));
    CHECK(false == town_hall_in_game->addRessources(TYPE_RESSOURCE_TRANSPORTED::FISH, -20));
    CHECK(3 == town_hall_in_game->getRockNumber());
    CHECK(5 == town_hall_in_game->getWoodNumber());
    CHECK(9 == town_hall_in_game->getFoodNumber());
    CHECK(11 == town_hall_in_game->getFishNumber());

    CHECK(true == town_hall_in_game->removeRockNumber(2));
    CHECK(true == town_hall_in_game->removeWoodNumber(3));
    CHECK(true == town_hall_in_game->removeFoodNumber(1));
    CHECK(true == town_hall_in_game->removeFishNumber(5));
    CHECK(6 == town_hall_in_game->getLevel());
    CHECK(1 == town_hall_in_game->getRockNumber());
    CHECK(2 == town_hall_in_game->getWoodNumber());
    CHECK(8 == town_hall_in_game->getFoodNumber());
    CHECK(6 == town_hall_in_game->getFishNumber());

    CHECK(false == town_hall_in_game->removeRockNumber(-8));
    CHECK(false == town_hall_in_game->removeWoodNumber(-2));
    CHECK(false == town_hall_in_game->removeFoodNumber(-10));
    CHECK(false == town_hall_in_game->removeFishNumber(-20));
    CHECK(1 == town_hall_in_game->getRockNumber());
    CHECK(2 == town_hall_in_game->getWoodNumber());
    CHECK(8 == town_hall_in_game->getFoodNumber());
    CHECK(6 == town_hall_in_game->getFishNumber());

    delete town_hall_in_game;
    delete town_hall_start;
}

TEST_CASE("DateInit")
{
    Date date_init;
    CHECK(1 == date_init.getDay());
    CHECK(1 == date_init.getMonth());
    CHECK(0 == date_init.getYear());
    CHECK(Date() == date_init);
    CHECK(true == date_init.isDateValid());

    ++date_init;

    CHECK(2 == date_init.getDay());
    CHECK(1 == date_init.getMonth());
    CHECK(0 == date_init.getYear());
}

TEST_CASE("InvalidDate")
{

    REQUIRE_THROWS_AS(Date(52, 10, 2018), ConstructorDateException);
}

TEST_CASE("Date")
{
    Date date(31, 1, 0);
    ++date;
    CHECK(Date(1, 2, 0) == date);

    date = Date(31, 12, 2018);
    ++date;
    CHECK(Date(1, 1, 2019) == date);

    Date date_copy = Date(date);
    CHECK(Date(1, 1, 2019) == date_copy);
}

TEST_CASE("DateOperator<")
{
    Date date_inf1(1, 1, 1);
    Date date_sup1(1, 1, 2);

    CHECK(true == date_inf1 < date_sup1);
    CHECK(false == date_sup1 < date_inf1);

    Date date_inf2(1, 1, 1);
    Date date_sup2(1, 2, 1);

    CHECK(true == date_inf2 < date_sup2);
    CHECK(false == date_sup2 < date_inf2);

    Date date_inf3(1, 1, 1);
    Date date_sup3(2, 1, 1);

    CHECK(true == date_inf3 < date_sup3);
    CHECK(false == date_sup3 < date_inf3);
}

TEST_CASE("Character")
{
    Constantes::openingConfiguration(1) ;
    Date date_character1;
    Date date_character2(1, 1, 20);
    Character character1(date_character1);
    Character character2(SEX::FEMALE, date_character2);

    CHECK(Date() == character1.getDateOfBirth());
    CHECK(Date(1, 1, 20) == character2.getDateOfBirth());

    CHECK(0 == character1.getCharacterId());
    CHECK(1 == character2.getCharacterId());
    CHECK(SEX::FEMALE == character2.getCharacterGender());
    CHECK(0 == character1.getCharacterTeam());
    CHECK(20 == character2.getCharacterAge(Date(1, 1, 40)));
    CHECK(19 == character2.getCharacterAge(Date(2, 1, 40)));
    character1.setCharacterTeam(3);

    CHECK(3 == character1.getCharacterTeam());
    Character character_copy(character1);
    CHECK(character1.getCharacterTeam() == character_copy.getCharacterTeam());
    CHECK(character1.getDateOfBirth() == character_copy.getDateOfBirth());
    CHECK(character1.getCharacterGender() == character_copy.getCharacterGender());
    CHECK(character1.getCharacterId() == character_copy.getCharacterId());
}

TEST_CASE("MaleCharacter")
{
    Character *character1 = new MaleCharacter(Date(20, 5, 2018));
    Character *character2 = new MaleCharacter(JOB::FARMER, Date());
    CHECK(SEX::MALE == character1->getCharacterGender());
    CHECK(SEX::MALE == character2->getCharacterGender());

    // CHECK(STATE::GOING_TO_COLLECTION_POINT == ((MaleCharacter *)character1)->getCharacterCurrentState());
    CHECK(TYPE_RESSOURCE_TRANSPORTED::NO_RESSOURCE == ((MaleCharacter *)character1)->getTypeRessourceTransported());

    ((MaleCharacter *)character1)->setDirection(4, 10);
    // ((MaleCharacter *)character1)->setCharacterCurrentState(STATE::WORKING);
    ((MaleCharacter *)character1)->setTypeRessourceTransported(GROUND_TYPE::FARM);

    CHECK(((MaleCharacter *)character1)->getDirection().getAbscissa() == 0);
    CHECK(((MaleCharacter *)character1)->getDirection().getOrdinate() == 4);
    CHECK(TYPE_RESSOURCE_TRANSPORTED::FOOD == ((MaleCharacter *)character1)->getTypeRessourceTransported());
    // CHECK(STATE::WORKING == ((MaleCharacter *)character1)->getCharacterCurrentState());

    CHECK(Date(20, 5, 2018) == character1->getDateOfBirth());
    CHECK(Date() == character2->getDateOfBirth());

    CHECK(3 == character1->getCharacterId());
    CHECK(4 == character2->getCharacterId());
    CHECK(JOB::FARMER == ((MaleCharacter *)character2)->getSpeciality());

    CHECK(0 == ((MaleCharacter *)character1)->getTimeAtWork());

    // ((MaleCharacter *)character1)->setCharacterCurrentState(STATE::WORKING);
    ((MaleCharacter *)character1)->setTypeRessourceTransported(GROUND_TYPE::FARM);
    for (int i = 1; i < 4; i++)
    {
        ((MaleCharacter *)character1)->incrementTimeAtWork();
        CHECK(i % 4 == ((MaleCharacter *)character1)->getTimeAtWork());
    }

    ((MaleCharacter *)character1)->resetTimeAtWork();
    CHECK(0 == ((MaleCharacter *)character1)->getTimeAtWork());

    CHECK(TYPE_RESSOURCE_TRANSPORTED::FOOD == ((MaleCharacter *)character1)->getTypeRessourceTransported());
    // CHECK(STATE::WORKING == ((MaleCharacter *)character1)->getCharacterCurrentState());

    delete character1;
    delete character2;
}
TEST_CASE("Json")
{
    std::string file_name = "./CONFIGURATIONS/Configuration.json";
    std::ifstream file(file_name);
    if (!file.fail())
    {
        json j;
        file >> j;
        json j1 = j["config1"];
        CHECK(2 == j["maxConfig"]) ;
        CHECK(0.5 == j["config1"]["chanceMale"]);
        CHECK(0.45 == j["config2"]["chanceMale"]);
        CHECK(0.5 == j1["chanceMale"]);
        file.close();
    }
    else
    {
        throw InvalidFile(file_name);
    }
}

TEST_CASE("JsonClass")
{
    Constantes::openingConfiguration(1);
    CHECK(Constantes::CONFIG_SIMU["chanceMale"] == 0.5);
}
TEST_CASE("FemaleCharacter")
{
    Constantes::openingConfiguration(1);
    CHECK(Constantes::CONFIG_SIMU["chanceMale"] == 0.5);

    Character *character1 = new FemaleCharacter(Date());
    Character *character2 = new FemaleCharacter(Date(01, 05, 1997));
    CHECK(Date(1, 1, 0) == character1->getDateOfBirth());
    CHECK(Date(1, 5, 1997) == character2->getDateOfBirth());

    CHECK(5 == character1->getCharacterId());
    CHECK(6 == character2->getCharacterId());
    CHECK(Date() == ((FemaleCharacter *)character1)->getPregnancyTime());
    CHECK(Date() == ((FemaleCharacter *)character2)->getPregnancyTime());
    CHECK(SEX::FEMALE == character1->getCharacterGender());
    CHECK(SEX::FEMALE == character2->getCharacterGender());

    delete character1;
    delete character2;
}
TEST_CASE("MonthOfPregnancy")
{
    Character *character1 = new FemaleCharacter(Date());
    CHECK(Date() == ((FemaleCharacter *)character1)->getPregnancyTime());
    CHECK(0 == ((FemaleCharacter *)character1)->getMonthPregnancy(Date(1, 1, 0)));
    CHECK(0 == ((FemaleCharacter *)character1)->getMonthPregnancy(Date(15, 1, 0)));
    CHECK(1 == ((FemaleCharacter *)character1)->getMonthPregnancy(Date(1, 2, 0)));
    CHECK(1 == ((FemaleCharacter *)character1)->getMonthPregnancy(Date(3, 2, 0)));
    ((FemaleCharacter *)character1)->setTimePregnancy(Date(15, 6, 2018));
    CHECK(1 == ((FemaleCharacter *)character1)->getMonthPregnancy(Date(15, 7, 2018)));
    CHECK(0 == ((FemaleCharacter *)character1)->getMonthPregnancy(Date(14, 7, 2018)));
    CHECK(1 == ((FemaleCharacter *)character1)->getMonthPregnancy(Date(14, 8, 2018)));
    ((FemaleCharacter *)character1)->setTimePregnancy(Date(15, 12, 2018));
    CHECK(1 == ((FemaleCharacter *)character1)->getMonthPregnancy(Date(15, 1, 2019)));
    CHECK(0 == ((FemaleCharacter *)character1)->getMonthPregnancy(Date(14, 1, 2019)));
    ((FemaleCharacter *)character1)->setTimePregnancy(Date());
    delete character1;
}

TEST_CASE("CollectionPoint")
{
    Ground *collection_point = new CollectionPoint(GROUND_TYPE::QUARRY);

    CHECK(4 == collection_point->getGroundId());
    CHECK(0 == collection_point->getVectorSize());
    CHECK(1000 == ((CollectionPoint *)collection_point)->getRessourcesNumber());
    CHECK(GROUND_TYPE::QUARRY == collection_point->getGroundType());

    bool flag = ((CollectionPoint *)collection_point)->ressourcesNumberExtracted(2);
    CHECK(998 == ((CollectionPoint *)collection_point)->getRessourcesNumber());
    CHECK(flag == true);

    flag = ((CollectionPoint *)collection_point)->ressourcesNumberExtracted(1000);
    CHECK(998 == ((CollectionPoint *)collection_point)->getRessourcesNumber());
    CHECK(flag == false);

    ((CollectionPoint *)collection_point)->setRessources(50);
    CHECK(50 == ((CollectionPoint *)collection_point)->getRessourcesNumber());

    MaleCharacter *worker = new MaleCharacter(JOB::QUARRY_MAN, Date(20, 8, 90));
    collection_point->addCharacter(worker);

    CHECK(1 == collection_point->getVectorSize());
    CHECK(worker == collection_point->getCharacter(0));

    REQUIRE_THROWS_AS(collection_point->removeCharacter(1), OutOfRangeSuperior);
    REQUIRE_THROWS_AS(collection_point->getCharacter(5), OutOfRangeSuperior);

    collection_point->removeCharacter(0);
    CHECK(0 == collection_point->getVectorSize());

    delete collection_point;
}

TEST_CASE("Valgrind")
{
    Ground *lake = new Lake();
    Character *male = new MaleCharacter(Date());
    CHECK(5 == ((Lake *)lake)->getGroundId());
    CHECK(GROUND_TYPE::LAKE == lake->getGroundType());
    CHECK(1000 == ((Lake *)lake)->getRessourcesNumber());
    lake->addCharacter(male);
    lake->addCharacter(new MaleCharacter(Date()));

    delete lake;
}
TEST_CASE("SpecificCollectionPoint")
{
    Ground *lake = new Lake(10);
    Ground *quarry = new Quarry(5);
    Ground *forest = new Forest();
    Ground *farm = new Farm();

    Character *farmer = new MaleCharacter(JOB::FARMER, Date());
    Character *fisherman = new MaleCharacter(JOB::FISHERMAN, Date());
    Character *lumberjack = new MaleCharacter(JOB::LUMBERJACK, Date());
    Character *quarryman = new MaleCharacter(JOB::QUARRY_MAN, Date());

    CHECK(6 == ((Lake *)lake)->getGroundId());
    CHECK(7 == ((Quarry *)quarry)->getGroundId());
    CHECK(8 == ((Forest *)forest)->getGroundId());
    CHECK(9 == ((Farm *)farm)->getGroundId());

    CHECK(GROUND_TYPE::LAKE == lake->getGroundType());
    CHECK(GROUND_TYPE::QUARRY == quarry->getGroundType());
    CHECK(GROUND_TYPE::FOREST == forest->getGroundType());
    CHECK(GROUND_TYPE::FARM == farm->getGroundType());
    CHECK(1000 == ((Forest *)forest)->getRessourcesNumber());
    CHECK(1000 == ((Farm *)farm)->getRessourcesNumber());
    CHECK(10 == ((Lake *)lake)->getRessourcesNumber());
    CHECK(5 == ((Quarry *)quarry)->getRessourcesNumber());

    forest->addCharacter(lumberjack);
    quarry->addCharacter(quarryman);
    lake->addCharacter(fisherman);
    farm->addCharacter(farmer);
    farm->addCharacter(new MaleCharacter(Date()));
    CHECK(1 == forest->getVectorSize());
    CHECK(1 == quarry->getVectorSize());
    CHECK(1 == lake->getVectorSize());
    CHECK(2 == farm->getVectorSize());
    CHECK(lumberjack == forest->getCharacter(0));
    CHECK(fisherman == lake->getCharacter(0));
    CHECK(quarryman == quarry->getCharacter(0));
    CHECK(farmer == farm->getCharacter(0));
    CHECK(farmer->getDateOfBirth().getDay() == farm->getCharacter(0)->getDateOfBirth().getDay());
    CHECK(farmer->getDateOfBirth().getMonth() == farm->getCharacter(0)->getDateOfBirth().getMonth());
    CHECK(farmer->getDateOfBirth().getYear() == farm->getCharacter(0)->getDateOfBirth().getYear());
    REQUIRE_THROWS_AS(((Lake *)lake)->removeCharacter(1), OutOfRangeSuperior);
    delete farm;
    delete lake;
    delete quarry;
    delete forest;
}

TEST_CASE("Afficher")
{
    Ground *town_hall = new TownHall();
    Ground *ground = new Ground();
    Ground *quarry = new Quarry();
    Ground *forest = new Forest();
    Ground *lake = new Lake();
    Ground *farm = new Farm();

    std::cout << std::endl
              << "VERIFIER SI CORRECT" << std::endl;
    std::cout << " T = ";
    town_hall->display();
    std::cout << std::endl;
    std::cout << " . = ";
    ground->display();
    std::cout << std::endl;
    std::cout << " Q = ";
    quarry->display();
    std::cout << std::endl;
    std::cout << " F = ";
    forest->display();
    std::cout << std::endl;
    std::cout << " L = ";
    lake->display();
    std::cout << std::endl;
    std::cout << " f = ";
    farm->display();
    std::cout << std::endl
              << std::endl;

    delete ground;
    delete town_hall;
    delete quarry;
    delete forest;
    delete lake;
    delete farm;
}

TEST_CASE("InitialisationGrid")
{
    std::vector<unsigned int> vector_character = {2, 3, 8, 9, 15, 16};
    std::vector<unsigned int> vector_map = {2, 3, 8, 9, 15, 16};
    Grid grid(vector_map, vector_character);
    grid.displayMap();
    grid.displayCharacter();
    std::string file_name = "INSTANCES/map_test_write.txt";
    std::ofstream file(file_name);
    if (!file.fail())
    {
        grid.displayMap(file);
        grid.displayCharacter(file);
        file.close();
    }
    else
    {
        throw InvalidFile(file_name);
    }

    CHECK(20 == grid.getColumnNumber());
    CHECK(20 == grid.getRowNumber());
    CHECK(0 == grid.getGroundGrid(0, 0)->getGroundId());

    std::cout << "VERIFIER SI CORRECT" << std::endl;
    std::cout << " T = ";
    grid.getGroundGrid(0, 0)->display();
    std::cout << std::endl;

    std::cout << " . = ";
    grid.getGroundGrid(9, 0)->display();
    std::cout << std::endl;

    Character *character = grid.getGroundGrid(0, 0)->getCharacter(0);
    CHECK(0 == character->getCharacterTeam());
    CHECK(character->getCharacterGender() == SEX::MALE);
    CHECK(2 == grid.getSizeVectorGroundWithCharacter());
    CHECK(6 == grid.getSizeVectorGroundWithCollectionPoint());
    CHECK(grid.getGroundWithCharacter(0)->getCharacter(0)->getCharacterId() == character->getCharacterId());
    CHECK(338 == grid.getGroundWithCollectionPoint(0)->getGroundId());

     Grid grid_copy(grid);
    CHECK(20 == grid_copy.getColumnNumber());
    CHECK(20 == grid_copy.getRowNumber());
    CHECK(0 == grid_copy.getGroundGrid(0, 0)->getGroundId());

    character = grid_copy.getGroundGrid(0, 0)->getCharacter(0);
    CHECK(0 == character->getCharacterTeam());
    CHECK(character->getCharacterGender() == SEX::MALE);
    CHECK(2 == grid_copy.getSizeVectorGroundWithCharacter());
    CHECK(6 == grid_copy.getSizeVectorGroundWithCollectionPoint());
    CHECK(0 == grid_copy.getGroundGrid(0, 0)->getGroundId());
    CHECK(grid_copy.getGroundWithCharacter(0)->getCharacter(0)->getCharacterId() == character->getCharacterId());
    CHECK(166 == grid_copy.getGroundWithCollectionPoint(0)->getGroundId());
}

TEST_CASE("MethodeStatic&Comparaison")
{
    CHECK(JOB::QUARRY_MAN == (JOB)GROUND_TYPE::QUARRY);
    CHECK(JOB::LUMBERJACK == (JOB)GROUND_TYPE::FOREST);
    CHECK(JOB::FISHERMAN == (JOB)GROUND_TYPE::LAKE);
    CHECK(JOB::FARMER == (JOB)GROUND_TYPE::FARM);

    CHECK((GROUND_TYPE)JOB::QUARRY_MAN == GROUND_TYPE::QUARRY);
    CHECK((GROUND_TYPE)JOB::LUMBERJACK == GROUND_TYPE::FOREST);
    CHECK((GROUND_TYPE)JOB::FISHERMAN == GROUND_TYPE::LAKE);
    CHECK((GROUND_TYPE)JOB::FARMER == GROUND_TYPE::FARM);

    CHECK((TYPE_RESSOURCE_TRANSPORTED)JOB::QUARRY_MAN == TYPE_RESSOURCE_TRANSPORTED::ROCK);
    CHECK((TYPE_RESSOURCE_TRANSPORTED)JOB::LUMBERJACK == TYPE_RESSOURCE_TRANSPORTED::WOOD);
    CHECK((TYPE_RESSOURCE_TRANSPORTED)JOB::FISHERMAN == TYPE_RESSOURCE_TRANSPORTED::FISH);
    CHECK((TYPE_RESSOURCE_TRANSPORTED)JOB::FARMER == TYPE_RESSOURCE_TRANSPORTED::FOOD);

    CHECK(JOB::QUARRY_MAN == (JOB)TYPE_RESSOURCE_TRANSPORTED::ROCK);
    CHECK(JOB::LUMBERJACK == (JOB)TYPE_RESSOURCE_TRANSPORTED::WOOD);
    CHECK(JOB::FISHERMAN == (JOB)TYPE_RESSOURCE_TRANSPORTED::FISH);
    CHECK(JOB::FARMER == (JOB)TYPE_RESSOURCE_TRANSPORTED::FOOD);

    StructCoordinates a(0, 0);
    StructCoordinates b(2, 0);
    CHECK(2 == Game::euclidienneDistance(a, b));
}
TEST_CASE("GroundCopy")
{
    Ground *ground1 = new Ground();

    ground1->addCharacter(new MaleCharacter(Date()));
    ground1->addCharacter(new FemaleCharacter(Date()));

    Ground *ground2 = new Ground(*ground1);

    CHECK(ground1->getGroundId() == ground2->getGroundId());
    CHECK(ground1->getGroundType() == ground2->getGroundType());
    CHECK(ground1->getVectorSize() == ground2->getVectorSize());
    CHECK(ground1->getCharacter(0)->getCharacterId() == ground2->getCharacter(0)->getCharacterId());

    Character *character = ground1->getCharacter(0);
    ((MaleCharacter *)character)->getDirection().incrementAbscissa();

    CHECK(((MaleCharacter *)character)->getDirection().getAbscissa() == 1);
    delete ground1;
    delete ground2;
}

// TEST_CASE("Exception")
// {
//     Constantes::openingConfiguration(1);
//     Ground *ground1 = new Ground();
//         Character *character = new MaleCharacter(Date(20, 10, 2018));

//     std::vector<unsigned int> vector_character = {2, 3, 8, 9, 15, 16};
//     std::vector<unsigned int> vector_map = {2, 3, 8, 9, 15, 16};
//     std::vector<unsigned int> vector_map_error = {80};
//     std::vector<unsigned int> vector_character_error = {80};
    
//         Grid map(vector_map, vector_character);

//     REQUIRE_THROWS_AS(ground1->removeCharacter(8), OutOfRangeSuperior);
//     REQUIRE_THROWS_AS(Constantes::openingConfiguration(8), InvalidConfiguration);
//     REQUIRE_THROWS_AS(Grid(vector_character,vector_map_error), InvalidKey) ;
//     REQUIRE_THROWS_AS(Grid(vector_character_error,vector_map), InvalidKey) ;
//     /*REQUIRE_THROWS_AS(Grid(1, 100), InvalidGender);
//     REQUIRE_THROWS_AS(Grid(1, 101), ConstructorDateException);
//     REQUIRE_THROWS_AS(Grid(1, 102), InvalidJob);
//     REQUIRE_THROWS_AS(Grid(1,103), std::bad_alloc);
//     REQUIRE_THROWS_AS(Grid(100, 1), InvalidGroundTypeReadingFile);*/
//     REQUIRE_THROWS_AS(((MaleCharacter *)character)->setTypeRessourceTransported(GROUND_TYPE::TOWN_HALL), InvalidGroundType);

//     REQUIRE_THROWS_AS(map.getGroundGrid(24, 8), OutOfRangeSuperior);
//     REQUIRE_THROWS_AS(map.getGroundGrid(8, 111), OutOfRangeSuperior);
//     REQUIRE_THROWS_AS(map.getGroundWithCollectionPoint(20), OutOfRangeSuperior);
//     REQUIRE_THROWS_AS(map.getGroundWithCharacter(2), OutOfRangeSuperior);
//     REQUIRE_THROWS_AS(map.getDirectionCharacter(StructCoordinates(41, 11)), OutOfRangeSuperior);
//     REQUIRE_THROWS_AS(map.getGroundGrid(510), OutOfRangeSuperior);
//     REQUIRE_THROWS_AS(character->getCharacterAge(Date(1, 1, 1)), CurrentDateBeforeBirthException);
//     REQUIRE_THROWS_AS(Date(1, 155, 2), ConstructorDateException);
//     REQUIRE_THROWS_AS(Date(1, 58, 1) < Date(1, 1, 0), ConstructorDateException);
//     REQUIRE_THROWS_AS(Date(1, 2, 1) < Date(32, 1, 0), ConstructorDateException);
//     REQUIRE_THROWS_AS(++Date(1, 82, 1), ConstructorDateException);

//     delete character;
//     delete ground1;
// }

TEST_CASE("JsonCharacterValid?")
{
    std::string file_name = "./CHARACTERS/Characters.json";
    std::ifstream file(file_name);
    unsigned int male_number;
    unsigned int female_number;
    Character *test_character;
    Date date_of_birth;
    std::string character;
    if (!file.fail())
    {
        json json_character;
        file >> json_character;
        unsigned int character_number = json_character["character_number"];
        for (unsigned int i = 1; i <= character_number; i++)
        {
            character = "character" + std::to_string(i);
            date_of_birth = Date(json_character[character]["day"], json_character[character]["month"], json_character[character]["year"]);
            unsigned int sex = json_character[character]["sex"];
            switch (sex)
            {
            case 0:
                test_character = new MaleCharacter(json_character[character]["job"], date_of_birth);
                break;

            case 1:
                test_character = new FemaleCharacter(date_of_birth, (unsigned int)json_character[character]["baby"]);
                break;
            }
            delete test_character;
            file.close();
        }
    }
}

TEST_CASE("JsonMapValid?")
{
    std::string file_name = "./MAPS/Maps.json";
    std::ifstream file(file_name);
    Ground *ground;
    std::string map;
    if (!file.fail())
    {
        json json_map;
        file >> json_map;
        unsigned int collection_point_number = json_map["collection_point_number"];
        for (unsigned int i = 1; i <= collection_point_number; i++)
        {
            map = "collection_point" + std::to_string(i);
            ground = Grid::initGround(json_map[map]["type"], json_map[map]["ressource_number"]) ;
            delete ground;
        }
        file.close();
    }
}


TEST_CASE("Game")
{
    system("clear");
    std::vector<unsigned int> vector_character = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    //std::vector<unsigned int> vector_character = {2, 8, 3, 9};
    std::vector<unsigned int> vector_map = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    Game game(vector_map, vector_character, 1, Date(1, 1, 60));
    game.run(1000);
}


// TEST_CASE("Menu")
// {
//     Menu::displayWelcome();
//     Menu menu;

//     menu.displayAllCharacter();
//     std::vector<unsigned int> character_choice = menu.characterChoice();

//     menu.displayAllMap();
//     std::vector<unsigned int> map_choice = menu.mapChoice();

//     menu.displayAllConfig();
//     unsigned config_choice = menu.configChoice();
 
//     menu.displayTurnChoice();
//     unsigned turn_choice = menu.turnChoice(); 
 
//     Game game(map_choice,character_choice, config_choice, Date(1, 1, 60));
//     game.run(turn_choice);
// }