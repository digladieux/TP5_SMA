#include "../header/Report.hpp"
unsigned int Report::counter = 0 ;

Report::Report() : id(counter), people_number_init(0), death_number(0), birth_number(0), level(0), rock_number(0), wood_number(0), food_number(0), fish_number(0), team(0) 
{
    counter ++ ;
}
Report::Report(const Report& report) : people_number_init(report.people_number_init), death_number(report.death_number), birth_number(report.birth_number), level(report.level), rock_number(report.rock_number), wood_number(report.wood_number), food_number(report.food_number), fish_number(report.fish_number), team(report.team){} 

Report::~Report() {}

void Report::incrementNumberOfDeath() noexcept
{
    death_number++;
}
void Report::incrementNumberOfBirth() noexcept
{
    birth_number++;
}
void Report::setLevel(const unsigned int current_level) noexcept
{
    level = current_level;
}
void Report::setRockNumber(const unsigned int current_rock) noexcept
{
    rock_number = current_rock;
}
void Report::setWoodNumber(const unsigned int current_wood) noexcept
{
    wood_number = current_wood;
}
void Report::setFoodNumber(const unsigned int current_food) noexcept
{
    food_number = current_food;
}
void Report::setFishNumber(const unsigned int current_fish) noexcept
{
    fish_number = current_fish;
}

unsigned int Report::getNumberOfDeath() const noexcept
{
    return death_number;
}
unsigned int Report::getNumberOfBirth() const noexcept
{
    return birth_number;
}
unsigned int Report::getLevel() const noexcept
{
    return level;
}
unsigned int Report::getRockNumber() const noexcept
{
    return rock_number;
}
unsigned int Report::getWoodNumber() const noexcept
{
    return wood_number;
}
unsigned int Report::getFoodNumber() const noexcept
{
    return food_number;
}
unsigned int Report::getFishNumber() const noexcept
{
    return fish_number;
}
unsigned int Report::getTeam() const noexcept
{
    return team;
}
unsigned int Report::getNumberOfCharacter() const noexcept
{
    return people_number_init;
}

void Report::display(std::ostream &os) const noexcept
{
    os << "TEAM : " << team << "\tLEVEL : " << level << std::endl << std::endl ;

    os << "POPULATION" << std::endl ;
    os << "NUMBER OF BIRTH : " << birth_number << "\tNUMBER OF DEATH : " << death_number << std::endl ;
    os << "POPULATION BEGIN : " << people_number_init << "\tPOPULATION END : " << people_number_init + birth_number - death_number << std::endl << std::endl ;

    os << "RESSOURCES" << std::endl ;
    os << "ROCK NUMBER : " << rock_number << "\tWOOD NUMBER : " << wood_number << std::endl ;
    os << "FISH NUMBER : " << fish_number << "\tFOOD NUMBER : " << food_number << std::endl ;
}
  void Report::setTeam(const unsigned int current_team) noexcept
  {
      team = current_team ;

  }
  void Report::setNumberOfCharacter(const unsigned int current_population) noexcept
  {
      people_number_init = current_population ;
  }

