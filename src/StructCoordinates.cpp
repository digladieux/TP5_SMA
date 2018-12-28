#include "../header/StructCoordinates.hpp"

StructCoordinates::StructCoordinates(const StructCoordinates &direction) : abscissa(direction.abscissa), ordinate(direction.ordinate) {}
StructCoordinates::StructCoordinates(unsigned int x, unsigned int y) : abscissa(x), ordinate(y) {}

void StructCoordinates::setAbcissa(unsigned int x) noexcept
{
    abscissa = x;
}
void StructCoordinates::setOrdinate(unsigned int y) noexcept
{
    ordinate = y;
}
unsigned int StructCoordinates::getAbscissa() const noexcept
{
    return abscissa;
}
unsigned int StructCoordinates::getOrdinate() const noexcept
{
    return ordinate;
}
void StructCoordinates::incrementAbscissa() noexcept
{
    abscissa++;
}
void StructCoordinates::decrementAbscissa() noexcept
{
    abscissa--;
}
void StructCoordinates::incrementOrdinate() noexcept
{
    ordinate++;
}
void StructCoordinates::decrementOrdinate() noexcept
{
    ordinate--;
}
bool StructCoordinates::operator==(const StructCoordinates &coordinate)
{
    return ((this->getAbscissa() == coordinate.getAbscissa()) && (this->getOrdinate() == coordinate.getOrdinate()));
}
