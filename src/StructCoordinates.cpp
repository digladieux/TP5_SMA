/**
 * \file StructCoordinates.cpp
 * \author Gladieux Cunha Dimitri & Gonzales Florian
 * \brief Fichier d'implementation de la classe StructCoordinates
 * \date 2018-12-03
 */


#include "../header/StructCoordinates.hpp"
/**
 * \fn StructCoordinates::StructCoordinates(const StructCoordinates &direction)
 * \brief Constructeur de copie de la classe StructeurCoordinates
 * \param &direction Direction du personnage actuelle 
 */
StructCoordinates::StructCoordinates(const StructCoordinates &direction) : abscissa(direction.abscissa), ordinate(direction.ordinate) {}

/**
 * \fn StructCoordinates::StructCoordinates(unsigned int x, unsigned int y)
 * \brief Constructeur de la classe StructeurCoordinates
 * \param x Coordonne x de la direction du personnage 
 * \param y Coordonne y de la direction du personnage 
 */
StructCoordinates::StructCoordinates(unsigned int x, unsigned int y) : abscissa(x), ordinate(y) {}

/**
 * \fn void StructCoordinates::setAbcissa(unsigned int x) noexcept
 * \brief Setteur sur l'abscisse
 * \param x Coordonne x a changer
 */
void StructCoordinates::setAbcissa(unsigned int x) noexcept
{
    abscissa = x;
}

/**
 * \fn void StructCoordinates::setOrdinate(unsigned int y) noexcept
 * \brief Setteur sur l'ordonne
 * \param y Coordonne y a changer
 */
void StructCoordinates::setOrdinate(unsigned int y) noexcept
{
    ordinate = y;
}

/**
 * \fn unsigned int StructCoordinates::getAbscissa() const noexcept
 * \brief Getteur sur l'abscisse
 * \return Abscisse de la direction du personnage
 */
unsigned int StructCoordinates::getAbscissa() const noexcept
{
    return abscissa;
}

/**
 * \fn unsigned int StructCoordinates::getOrdinate() const noexcept
 * \brief Getteur sur l'ordonnee
 * \return Ordonnee de la direction du personnage
 */
unsigned int StructCoordinates::getOrdinate() const noexcept
{
    return ordinate;
}

/**
 * \fn void StructCoordinates::incrementAbscissa() noexcept
 * \brief Incremente l'abscisse de 1
 */
void StructCoordinates::incrementAbscissa() noexcept
{
    abscissa++;
}

/**
 * \fn void StructCoordinates::decrementAbscissa() noexcept
 * \brief Decrement l'abscisse de 1
 */
void StructCoordinates::decrementAbscissa() noexcept
{
    abscissa--;
}

/**
 * \fn void StructCoordinates::incrementOrdinate() noexcept
 * \brief Incremente l'ordonne de 1
 */
void StructCoordinates::incrementOrdinate() noexcept
{
    ordinate++;
}

/**
 * \fn void StructCoordinates::decrementOrdinate() noexcept
 * \brief Decrement l'ordonne de 1
 */
void StructCoordinates::decrementOrdinate() noexcept
{
    ordinate--;
}

/**
 * \fn bool StructCoordinates::operator==(const StructCoordinates &coordinate) 
 * \brief Surchage de l'operateur d'egalite pour la direction d'un personnage.
 * \param &coordinate Coordonne a comparer 
 * \return True si les points x et y sont similaires, false sinon 
 */
bool StructCoordinates::operator==(const StructCoordinates &coordinate)
{
    return ((this->getAbscissa() == coordinate.getAbscissa()) && (this->getOrdinate() == coordinate.getOrdinate()));
}
