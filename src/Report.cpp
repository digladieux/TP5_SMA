#include "../header/Report.hpp"
#include "../header/Color.hpp"
unsigned int Report::counter = 0 ;

/**
 * \fn Report::Report()
 * \brief Constructeur de rapport de fin de partie pour une equipe 
*/
Report::Report() : id(counter), people_number_init(0), death_number(0), birth_number(0), level(0), rock_number(0), wood_number(0), food_number(0), fish_number(0), team(0) 
{
    counter ++ ; //compte le nombre de rapport cree
}


/**
 * \fn Report::Report(const Report& report)
 * \brief Constructeur de copie d'un rapport
 * \param report Rapport a copier
 */

Report::Report(const Report& report) : people_number_init(report.people_number_init), death_number(report.death_number), birth_number(report.birth_number), level(report.level), rock_number(report.rock_number), wood_number(report.wood_number), food_number(report.food_number), fish_number(report.fish_number), team(report.team){} 


/**
 * \fn Report::~Report()
 * \brief Destructeur de la classe Report
 */

Report::~Report() {}


/**
 * \fn void Report::incrementNumberOfDeath() noexecpt
 * \brief Incremente de 1 l'attribut death_number
 */

void Report::incrementNumberOfDeath() noexcept
{
    death_number++;
}

/**
 * \fn Report::incrementNumberOfBirth() noexcept
 * \brief Incremente de 1 l'attribut birth_number
 */

void Report::incrementNumberOfBirth() noexcept
{
    birth_number++;
}


/**
 * \fn Report::setLevel(const unsigned int current_level) noexcept
 * \brief Modifie la valeur de l'attribut par la valeur en parametre
 * \param current_level Nouvelle valeur de l'attribut
 */

void Report::setLevel(const unsigned int current_level) noexcept
{
    level = current_level;
}

/**
 * \fn Report::setRockNumber(const unsigned int current_rock) noexcept
 * \brief Modifie la valeur de l'attribut par la valeur en parametre
 * \param current_rock Nouvelle valeur de l'attribut
 */

void Report::setRockNumber(const unsigned int current_rock) noexcept
{
    rock_number = current_rock;
}

/**
 * \fn Report::setWoodNumber(const unsigned int current_wood) noexcept
 * \brief Modifie la valeur de l'attribut par la valeur en parametre
 * \param current_wood Nouvelle valeur de l'attribut
 */
void Report::setWoodNumber(const unsigned int current_wood) noexcept
{
    wood_number = current_wood;
}

/**
 * \fn Report::setFoodNumber(const unsigned int current_food) noexcept
 * \brief Modifie la valeur de l'attribut par la valeur en parametre
 * \param current_food Nouvelle valeur de l'attribut
 */
void Report::setFoodNumber(const unsigned int current_food) noexcept
{
    food_number = current_food;
}

/**
 * \fn Report::setFishNumber(const unsigned int current_fish) noexcept
 * \brief Modifie la valeur de l'attribut par la valeur en parametre
 * \param current_fish Nouvelle valeur de l'attribut
 */
void Report::setFishNumber(const unsigned int current_fish) noexcept
{
    fish_number = current_fish;
}


/**
 * \fn Report::getNumberOfDeath() const noexcept
 * \brief Renvoie la valeur de l'attribut death_number
 * \return Nombre de mort
 */
unsigned int Report::getNumberOfDeath() const noexcept
{
    return death_number;
}

/**
 * \fn Report::getNumberOfBirth() const noexcept
 * \brief Renvoie la valeur de l'attribut birth_number
 * \return Nombre de naissance
 */
unsigned int Report::getNumberOfBirth() const noexcept
{
    return birth_number;
}


/**
 * \fn Report::getLevel() const noexcept
 * \brief Renvoie la valeur de l'attribut level
 * \return Niveau de l'Hotel de ville
 */
unsigned int Report::getLevel() const noexcept
{
    return level;
}

/**
 * \fn Report::getRockNumber() const noexcept
 * \brief Renvoie la valeur de l'attribut rock_number
 * \return Nombre de pierre
 */
unsigned int Report::getRockNumber() const noexcept
{
    return rock_number;
}

/**
 * \fn Report::getWoodNumber() const noexcept
 * \brief Renvoie la valeur de l'attribut wood_number
 * \return Nombre de bois
 */
unsigned int Report::getWoodNumber() const noexcept
{
    return wood_number;
}

/**
 * \fn Report::getFoodNumber() const noexcept
 * \brief Renvoie la valeur de l'attribut food_number
 * \return Nombre de nourriture
 */
unsigned int Report::getFoodNumber() const noexcept
{
    return food_number;
}

/**
 * \fn Report::getFishNumber() const noexcept
 * \brief Renvoie la valeur de l'attribut fish_number
 * \return Nombre de poisson
 */
unsigned int Report::getFishNumber() const noexcept
{
    return fish_number;
}

/**
 * \fn Report::geTeam() const noexcept
 * \brief Renvoie la valeur de l'attribut team
 * \return Equipe de l'hotel ville
 */
unsigned int Report::getTeam() const noexcept
{
    return team;
}

/**
 * \fn Report::getNumberOfCharacter() const noexcept
 * \brief Renvoie la valeur de l'attribut people_number_init
 * \return Nombre d'habitant
 */
unsigned int Report::getNumberOfCharacter() const noexcept
{
    return people_number_init;
}

/**
 * \fn Report::display(std::ostream &os) const noexcept
 * \brief Fonction d'affichage 
 * \param &os Flux où on envoie l'affichage
 */

void Report::display(std::ostream &os) const noexcept
{
    team == 0? os << BOLDRED : os << BOLDMAGENTA ;
    os << "TEAM : " << team << "\tLEVEL : " << level << std::endl << std::endl ;

    os << "POPULATION" << std::endl ;
    os << "NUMBER OF BIRTH : " << birth_number << "\tNUMBER OF DEATH : " << death_number << std::endl ;
    os << "POPULATION BEGIN : " << people_number_init << "\tPOPULATION END : " << people_number_init + birth_number - death_number << std::endl << std::endl ;

    os << "RESSOURCES" << std::endl ;
    os << "ROCK NUMBER : " << rock_number << "\tWOOD NUMBER : " << wood_number << std::endl ;
    os << "FISH NUMBER : " << fish_number << "\tFOOD NUMBER : " << food_number << std::endl << std::endl;
    os << RESET ; 
}

/**
 * \fn Report::setTeam(const unsigned int current_team) noexcept
 * \brief Modifie l'equipe du rapport
 * \param current_team Identifiant de la nouvelle equipe
 */

  void Report::setTeam(const unsigned int current_team) noexcept
  {
      team = current_team ;

  }

  /**
 * \fn Report::getNumberOfDeath(const unsigned int current_population)  noexcept
 * \brief Modifie la valeur de l'attribut people_number_init
 * \param current_population Nouveau nombre d'habitant
 */
  void Report::setNumberOfCharacter(const unsigned int current_population) noexcept
  {
      people_number_init = current_population ;
  }

