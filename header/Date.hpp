#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>

class Date
{
  protected:
    unsigned int year;
    unsigned int month;
    unsigned int day;

  public:
    Date();
    Date(const unsigned int &, const unsigned int &, const unsigned int &);

    int getDay() const noexcept ;
    int getMonth() const noexcept ;
    int getYear() const noexcept ;

    void setDay(const int &) noexcept;
    void setMonth(const int &) noexcept;
    void setYear(const int &) noexcept;

    bool isDateValid() const noexcept;
    
    Date operator++();
    Date operator++(int);
};

std::ostream &operator<<(std::ostream &, const Date &);
#endif
