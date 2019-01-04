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
    Date(const Date &date);

    unsigned int getDay() const noexcept;
    unsigned int getMonth() const noexcept;
    unsigned int getYear() const noexcept;

    bool isDateValid() const noexcept;
    bool operator<(const Date &) const;

    Date operator++();
    Date &operator=(const Date &) noexcept;
    bool operator==(const Date &) const noexcept;
    void display(std::ostream &os = std::cout) const noexcept;
};

#endif
