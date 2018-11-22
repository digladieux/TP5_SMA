#ifndef FARM_HPP
#define FARM_HPP

#include "CollectionPoint.hpp"
class Farm : public CollectionPoint
{
  public:
    Farm(const unsigned int food_number = 1000);
    ~Farm();

    void display(std::ostream &os = std::cout) const noexcept;
};

#endif
