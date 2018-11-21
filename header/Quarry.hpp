#ifndef QUARRY_HPP
#define QUARRY_HPP

#include "CollectionPoint.hpp"
class Quarry : public CollectionPoint
{
  public:
    Quarry(const unsigned int rock_number = 1000);
    ~Quarry();

    void display() const noexcept;
};

#endif
