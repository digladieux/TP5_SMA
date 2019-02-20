/**
 * \file StructCoordinates.hpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'en-tete du fichier source StructCoordinates.cpp
 * \date 2018-12-03
 */

#ifndef STRUCT_COORDINATES_HPP
#define STRUCT_COORDINATES_HPP
/**
 * \class StructCoordinates
 * \brief Coordonne d'un point
 */
class StructCoordinates
{
  private:
    unsigned int abscissa; /*! Abscisse du point */
    unsigned int ordinate; /*! Ordonnee du point */

  public:
    StructCoordinates(const StructCoordinates &);
    StructCoordinates(unsigned int abscissa = 0, unsigned int ordinate = 0);
StructCoordinates &operator=(const StructCoordinates &) ;

    void setAbcissa(unsigned int) noexcept;
    void setOrdinate(unsigned int) noexcept;

    void incrementAbscissa() noexcept;
    void decrementAbscissa() noexcept;
    void incrementOrdinate() noexcept;
    void decrementOrdinate() noexcept;

    unsigned int getAbscissa() const noexcept;
    unsigned int getOrdinate() const noexcept;

    bool operator==(const StructCoordinates &);
};

#endif
