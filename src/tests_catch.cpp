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
#include <fstream>
#include <iostream> /*TODO : test:8 A enlever plus tard */

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
    CHECK(2 == town_hall_start->getGroundId());

    TownHall *town_hall_in_game = new TownHall(5, 1, 2, 3);
    CHECK(5 == town_hall_in_game->getLevel());
    CHECK(1 == town_hall_in_game->getRockNumber());
    CHECK(2 == town_hall_in_game->getWoodNumber());
    CHECK(3 == town_hall_in_game->getFoodNumber());
    CHECK(3 == town_hall_in_game->getGroundId());

    town_hall_in_game->incrementLevel();
    CHECK(true == town_hall_in_game->setRockNumber(2));
    CHECK(true == town_hall_in_game->setWoodNumber(-1));
    CHECK(true == town_hall_in_game->setFoodNumber(6));
    CHECK(6 == town_hall_in_game->getLevel());
    CHECK(3 == town_hall_in_game->getRockNumber());
    CHECK(1 == town_hall_in_game->getWoodNumber());
    CHECK(9 == town_hall_in_game->getFoodNumber());

    CHECK(false == town_hall_in_game->setRockNumber(-8));
    CHECK(false == town_hall_in_game->setWoodNumber(-2));
    CHECK(false == town_hall_in_game->setFoodNumber(-10));
    CHECK(3 == town_hall_in_game->getRockNumber());
    CHECK(1 == town_hall_in_game->getWoodNumber());
    CHECK(9 == town_hall_in_game->getFoodNumber());

    delete town_hall_in_game;
    delete town_hall_start;
}

TEST_CASE("Character")
{
    Character character1;
    Character character2(SEX::FEMALE_CHARACTER_ADULT, 20);

    CHECK(0 == character1.getCharacterAge());
    CHECK(20 == character2.getCharacterAge());
    CHECK(0 == character1.getCharacterId());
    CHECK(1 == character2.getCharacterId());
    CHECK(SEX::FEMALE_CHARACTER_ADULT == character2.getCharacterGender());
    character1.incrementAge();
    character2.incrementAge();

    CHECK(1 == character1.getCharacterAge());
    CHECK(21 == character2.getCharacterAge());
}

TEST_CASE("MaleCharacter")
{
    MaleCharacter *character1 = new MaleCharacter();
    MaleCharacter *character2 = new MaleCharacter(JOB::FARMER, SEX::MALE_CHARACTER_ADULT, 20);

    CHECK(0 == character1->getCharacterAge());
    CHECK(20 == character2->getCharacterAge());
    CHECK(2 == character1->getCharacterId());
    CHECK(3 == character2->getCharacterId());
    CHECK(JOB::NO_JOB == character1->getSpeciality());
    CHECK(JOB::FARMER == character2->getSpeciality());
    CHECK(SEX::MALE_CHARACTER_CHILD == character1->getCharacterGender());
    CHECK(SEX::MALE_CHARACTER_ADULT == character2->getCharacterGender());

    character1->incrementAge();
    character2->incrementAge();

    CHECK(1 == character1->getCharacterAge());
    CHECK(21 == character2->getCharacterAge());

    delete character1;
    delete character2;
}

TEST_CASE("FemaleCharacter")
{
    FemaleCharacter *character1 = new FemaleCharacter();
    FemaleCharacter *character2 = new FemaleCharacter(SEX::FEMALE_CHARACTER_ADULT, 20);

    CHECK(0 == character1->getCharacterAge());
    CHECK(20 == character2->getCharacterAge());
    CHECK(4 == character1->getCharacterId());
    CHECK(5 == character2->getCharacterId());
    CHECK(0 == character1->getMonthNumberPregnancy());
    CHECK(0 == character2->getMonthNumberPregnancy());
    CHECK(SEX::FEMALE_CHARACTER_CHILD == character1->getCharacterGender());
    CHECK(SEX::FEMALE_CHARACTER_ADULT == character2->getCharacterGender());

    character1->setMonthPregnancy();

    for (unsigned int i = 1; i < 11; i++)
    {
        character2->setMonthPregnancy();
        CHECK(i % 10 == character2->getMonthNumberPregnancy());
    }
    CHECK(1 == character1->getMonthNumberPregnancy());
    CHECK(0 == character2->getMonthNumberPregnancy());

    delete character1;
    delete character2;
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

    MaleCharacter *worker = new MaleCharacter(JOB::QUARRY_MAN, SEX::MALE_CHARACTER_ADULT, 18);
    collection_point->addCharacter(worker);

    CHECK(1 == collection_point->getVectorSize());
    CHECK(worker == collection_point->getCharacter(0));

    REQUIRE_THROWS_AS(collection_point->removeCharacter(1), std::out_of_range);
    REQUIRE_THROWS_AS(collection_point->getCharacter(5), std::out_of_range);

    collection_point->removeCharacter(0);
    CHECK(0 == collection_point->getVectorSize());

    collection_point->clearVector();
    delete collection_point;
}

TEST_CASE("Valgrind")
{
    Ground *lake = new Lake();
    Character *male = new MaleCharacter();
    CHECK(5 == ((Lake *)lake)->getGroundId());
    CHECK(GROUND_TYPE::LAKE == lake->getGroundType());
    CHECK(1000 == ((Lake *)lake)->getRessourcesNumber());
    lake->addCharacter(male);
    lake->addCharacter(new MaleCharacter());
    lake->clearVector();

    delete lake;
}
TEST_CASE("SpecificCollectionPoint")
{
    Ground *lake = new Lake(10);
    Ground *quarry = new Quarry(5);
    Ground *forest = new Forest();
    Ground *farm = new Farm();

    Character *farmer = new MaleCharacter(JOB::FARMER, SEX::MALE_CHARACTER_ADULT, 20);
    Character *fisherman = new MaleCharacter(JOB::FISHERMAN, SEX::MALE_CHARACTER_ADULT, 45);
    Character *lumberjack = new MaleCharacter(JOB::LUMBERJACK, SEX::MALE_CHARACTER_ADULT, 10);
    Character *quarryman = new MaleCharacter(JOB::QUARRY_MAN, SEX::MALE_CHARACTER_ADULT, 20);

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
    farm->addCharacter(new MaleCharacter());
    CHECK(1 == forest->getVectorSize());
    CHECK(1 == quarry->getVectorSize());
    CHECK(1 == lake->getVectorSize());
    CHECK(2 == farm->getVectorSize());
    CHECK(lumberjack == forest->getCharacter(0));
    CHECK(fisherman == lake->getCharacter(0));
    CHECK(quarryman == quarry->getCharacter(0));
    CHECK(farmer == farm->getCharacter(0));
    CHECK(farmer->getCharacterAge() == farm->getCharacter(0)->getCharacterAge());
    REQUIRE_THROWS_AS(((Lake *)lake)->removeCharacter(1), std::out_of_range);
    std::cout << farm->getCharacter(1)->getCharacterAge() << std::endl;
    farm->clearVector();
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
    Grid grid("map_test_read.txt");
    grid.displayMap();
    grid.displayCharacter();

    std::ofstream file("INSTANCES/map_test_write.txt");
    if (!file.fail())
    {
        grid.displayMap(file);
        grid.displayCharacter(file);
        file.close();
    }
    else
    {
        std::cerr << "INVALID_FILE";
    }

    CHECK(10 == grid.getColumnNumber());
    CHECK(10 == grid.getRowNumber());

    std::cout << "VERIFIER SI CORRECT" << std::endl;
    std::cout << " T = ";
    grid.getGroundGrid(0, 0)->display();
    std::cout << std::endl;

    std::cout << " . = ";
    grid.getGroundGrid(2, 0)->display();
    std::cout << std::endl;

    Character *character = grid.getGroundGrid(0, 0)->getCharacter(0);
    CHECK(character->getCharacterGender() == SEX::MALE_CHARACTER_ADULT);
    CHECK(2 == grid.getSizeVector());
    CHECK(grid.getGroundWithCharacter(0)->getCharacter(0)->getCharacterId() == character->getCharacterId());
}

TEST_CASE("GroundCopy")
{
    Ground *ground1 = new Ground();
    Ground *ground2 = new Ground(ground1);

    CHECK(ground1->getGroundId() == ground2->getGroundId());
    CHECK(ground1->getGroundType() == ground2->getGroundType());
    CHECK(ground1->getVectorSize() == ground2->getVectorSize());

    delete ground1;
    delete ground2;
}
