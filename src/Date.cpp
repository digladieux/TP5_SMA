#include "../header/Date.hpp"
#include <exception>

Date::Date() : day(1), month(1), year(0) {}
Date::Date(const unsigned int &d, const unsigned int &m, const unsigned int &y) : day(d), month(m), year(y) {}
Date::Date(const Date& date) : day(date.day), month(date.month), year(date.year){}

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
Date Date::operator++()
{
    Date date = *this;
    if (!date.isDateValid())
    {
        throw std::invalid_argument("INVALID_DATE");
    }
    date = Date(date.getDay() + 1, date.getMonth(), date.getYear());

    if (date.isDateValid())
    {
        *this = date;
    }
    else
    {
        date = Date(1, date.getMonth() + 1, date.getYear());
        if (date.isDateValid())
        {
            *this = date;
        }
        else
        {
            *this = Date(1, 1, date.getYear() + 1);
        }
    }
    return *this;
}

void Date::display(std::ostream &os) const noexcept
{
    os << "Day " << day << ", Month " << month << ", Year " << year << std::endl;
}
