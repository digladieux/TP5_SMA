#ifndef STRUCT_COORDINATES_HPP
#define STRUCT_COORDINATES_HPP
/**
 * \struct Coordinates
 * \brief Coordonne d'un point
 */
class StructCoordinates
{
  private:
    unsigned int abscissa; /* Abscisse du point */
    unsigned int ordinate; /* Ordonnee du point */

  public:
    StructCoordinates(const StructCoordinates &);
    StructCoordinates(unsigned int abscissa = 0, unsigned int ordinate = 0);

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
