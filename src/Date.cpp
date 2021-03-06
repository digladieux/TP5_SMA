/**
 * \file Date.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation de la classe Date
 * \date 2018-12-03
 */

#include "../header/Date.hpp"
#include "../header/Exception.hpp"

/**
 * \fn Date::Date()
 * \brief Constructeur par default de la date 
 */
Date::Date() : day(1), month(1), year(0) {}

/**
 * \fn Date::Date(const unsigned int &d, const unsigned int &m, const unsigned int &y)
 * \brief Construteur de la classe Date initialisant la date par celle en parametre
 * \param &d Jour de la date
 * \param &m Moi de la date
 * \param &y Annee de la date
 */
Date::Date(const unsigned int &d, const unsigned int &m, const unsigned int &y) : day(d), month(m), year(y)
{
    if (!this->isDateValid())
    {
        throw ConstructorDateException(d, m, y);
    }
}

/**
 * \fn Date::Date(const Date &date)
 * \brief Construteur de copie de la classe Date
 * \param &date Date a copier
 */
Date::Date(const Date &date) : day(date.day), month(date.month), year(date.year) {}


/**
 * \fn Date::getDay()
 * \brief Getter sur le jour de la date
 * \return Journee de la date
 */
unsigned int Date::getDay() const noexcept
{
    return day;
}

/**
 * \fn Date::getMonth()
 * \brief Getter sur le mois de la date
 * \return month Mois de la date
 */
unsigned int Date::getMonth() const noexcept
{
    return month;
}

/**
 * \fn Date::getYear()
 * \brief Getter sur l'annee de la date
 * \return year Annee de la date
 */
unsigned int Date::getYear() const noexcept
{
    return year;
}


/**
 * \fn bool Date::operator<(const Date &date) const
 * \brief Operateur de comparaison entre 2 dates
 * \return Vrai si la date de gauche est plus petite, faux sinon
 */
bool Date::operator<(const Date &date) const 
{
    bool current_date_inferior ;
    if (this->getYear() < date.getYear())
    {
        current_date_inferior = true;
    }
    else if (this->getYear() > date.getYear())
    {
        current_date_inferior = false;
    }
    else if (this->getMonth() < date.getMonth())
    {
        current_date_inferior = true;
    }
    else if (this->getMonth() > date.getMonth())
    {
        current_date_inferior = false;
    }
    else if (this->getDay() < date.getDay())
    {
        current_date_inferior = true;
    }
    else
    {
        current_date_inferior = false;
    }
    return current_date_inferior ;
}


/**
 * \fn bool Date::isDateValid() const noexcept
 * \brief Verifie que la date est valide
 * \return True si la date est valide, faux sinon
 */
bool Date::isDateValid() const noexcept
{
    bool valid = true;
    if ((month > 12) || (month < 1))
    {
        valid = false;
    }
    else if ((day > 31) || (day < 1))
    {
        valid = false;
    }
    else if ((day == 31) && ((month == 2) || (month == 4) || (month == 6) || (month == 9) || (month == 11)))
    {
        valid = false;
    }
    else if ((day == 30) && (month == 2))
    {
        valid = false;
    }
    else if (year < 2000)
    {
        if (((day == 29) && (month == 2)) && !(((year - 1900) % 4) == 0))
        {
            valid = false;
        }
    }
    else
    {
        if (((day == 29) && (month == 2)) && !(((year - 2000) % 4) == 0))
        {
            valid = false;
        }
    }
    return valid;
}

/**
 * \fn Date &Date::operator=(const Date &date) noexcept
 * \brief Surcharge de l'operateur d'affectation
 * \param &date Date que l'on veut copier
 */
Date &Date::operator=(const Date &date) noexcept
{
    if (this != &date)
    {
        day = date.day;
        month = date.month;
        year = date.year;
    }
    return *this;
}

/**
 * \fn bool Date::operator==(const Date &date) const noexcept
 * \brief Surchage de l'operateur de comparaison
 * \param &date Date que l'on veut compararer
 */
bool Date::operator==(const Date &date) const noexcept
{
    bool valid = false;
    if ((this->isDateValid()) && (date.isDateValid()))
    {
        if ((this->getDay() == date.getDay()) &&
            (this->getMonth() == date.getMonth()) &&
            (this->getYear() == date.getYear()))
        {
            valid = true;
        }
    }
    return valid;
}

/**
 * \fn Date Date::operator++()
 * \brief Surchage de l'operateur de pre-incrementation
 */
Date Date::operator++()
{
    Date date = *this;
    try
    {
        date = Date(date.getDay() + 1, date.getMonth(), date.getYear());
    }
    catch (const ConstructorDateException &)
    {
        try
        {
            date = Date(1, date.getMonth() + 1, date.getYear());
        }
        catch (const ConstructorDateException &)
        {
            date = Date(1, 1, date.getYear() + 1);
        }
    }
    *this = date;
    return *this;
}

/**
 * \fn std::string Date::to_string() const noexcept
 * \brief Convertit la date actuelle en string
 * \return La Date actuelle en chaine de charactere
 */
std::string Date::to_string() const noexcept
{
    return "Day " + std::to_string(day) + ", Month " + std::to_string(month) + ", Year : " + std::to_string(year) + "\n";
}

/**
 * \fn void Date::display(std::ostream &os) const noexcept
 * \brief Affichage la date
 * \param &os Flux dans lequel on veut afficher la date
 */
void Date::display(std::ostream &os) const noexcept
{
    os << "Day " << day << ", Month " << month << ", Year " << year << std::endl;
}

/**
 * \fn unsigned int Date::getAge(const Date &current_date) const
 * \brief Calcul le temps passe entre 2 dates (en annee)
 * \param &current_date Date actuelle
 * \return Nombre d'annee passe en 2 date
 */
unsigned int Date::getAge(const Date &current_date) const
{
    unsigned int age;
    if (current_date == *this)
    {
        age = 0;
    }
    else if (!(*this < current_date))
    {
        throw CurrentDateBeforeBirthException(current_date, *this);
    }

    else if (this->getYear() == current_date.getYear())
    {
        age = 0;
    }
    else if (Date(this->getDay(), this->getMonth(), 0) < Date(current_date.getDay(), current_date.getMonth(), 0))
    {
        age = current_date.getYear() - this->getYear() - 1;
    }
    else
    {
        age = current_date.getYear() - this->getYear();
    }

    return age;
}