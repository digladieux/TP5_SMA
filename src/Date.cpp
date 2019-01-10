#include "../header/Date.hpp"
#include "../header/Exception.hpp"

Date::Date() : day(1), month(1), year(0) {}
Date::Date(const unsigned int &d, const unsigned int &m, const unsigned int &y) : day(d), month(m), year(y)
{
    if (!this->isDateValid())
    {
        throw ConstructorDateException(d, m, y);
    }
}
Date::Date(const Date &date) : day(date.day), month(date.month), year(date.year) {}

unsigned int Date::getDay() const noexcept
{
    return day;
}
unsigned int Date::getMonth() const noexcept
{
    return month;
}
unsigned int Date::getYear() const noexcept
{
    return year;
}

bool Date::operator<(const Date &date) const
{
    if (this->getYear() < date.getYear())
    {
        return true;
    }
    else if (this->getYear() > date.getYear())
    {
        return false;
    }
    else if (this->getMonth() < date.getMonth())
    {
        return true;
    }
    else if (this->getMonth() > date.getMonth())
    {
        return false;
    }
    else if (this->getDay() < date.getDay())
    {
        return true;
    }
    else
    {
        return false;
    }
}
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

std::string Date::to_string() const noexcept
{
    return "Day " + std::to_string(day) + ", Month " + std::to_string(month) + ", Year : " + std::to_string(year) + "\n";
}
void Date::display(std::ostream &os) const noexcept
{
    os << "Day " << day << ", Month " << month << ", Year " << year << std::endl;
}
