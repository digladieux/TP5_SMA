#include "../header/Date.hpp"

Date::Date() : day(0), month(0), year(0) {}
Date::Date(const unsigned int &d, const unsigned int &m, const unsigned int &y) : day(d), month(m), year(y) {}

int Date::getDay() const noexcept
{
    return day;
}
int Date::getMonth() const noexcept
{
    return month;
}
int Date::getYear() const noexcept
{
    return year;
}
void Date::setDay(const int &d) noexcept
{
    day = d;
}
void Date::setMonth(const int &m) noexcept
{
    month = m;
}
void Date::setYear(const int &y) noexcept
{
    year = y;
}
bool Date::isDateValid() const noexcept
{
    bool valid = true;
    if (year < 0)
    {
        valid = false;
    }
    else if ((month > 12) || (month < 1))
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
    return true;
}
Date Date::operator++() noexcept
{
    Date date = *this;
    date.setDay
}
Date Date::operator++(int) noexcept
{
}
