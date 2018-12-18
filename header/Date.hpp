#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>

class Date
{
  protected:
    unsigned int day;
    unsigned int month;
    unsigned int year;

  public:
    Date();
    Date(const unsigned int &, const unsigned int &, const unsigned int &);

    int getDay() const noexcept;
    int getMonth() const noexcept;
    int getYear() const noexcept;

    bool isDateValid() const noexcept;

    Date operator++();
    Date &operator=(const Date &) noexcept;

    void display(std::ostream &os = std::cout) const noexcept;
};

#endif
