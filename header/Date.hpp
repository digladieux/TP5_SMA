/**
 * \file Date.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source Date.cpp
 * \date 2018-12-03
 */

#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>

/**
 * \class Date
 * \brief Implemente un objet Date avec un jour, un mois et une annee. Il respecte les annees bisextiles, les mois a 30 - 31 jours, ainsi que le mois de fevrier.
 */
class Date
{
  protected:
    unsigned int day;     /*! Jour */
    unsigned int month;   /*! Mois */
    unsigned int year;    /*! Annee */

  public:
    Date();
    Date(const unsigned int &, const unsigned int &, const unsigned int &);
    Date(const Date &date);

    unsigned int getDay() const noexcept;
    unsigned int getMonth() const noexcept;
    unsigned int getYear() const noexcept;
    unsigned int getAge(const Date&) const ;

    bool isDateValid() const noexcept;
    bool operator<(const Date &) const;

    Date operator++();
    Date &operator=(const Date &) noexcept;
    bool operator==(const Date &) const noexcept;

    std::string to_string() const noexcept;
    void display(std::ostream &os = std::cout) const noexcept;
};
#endif
