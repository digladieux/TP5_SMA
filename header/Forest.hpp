#ifndef FOREST_HPP
#define FOREST_HPP

#include "CollectionPoint.hpp"
class Forest : public CollectionPoint
{
  public:
    Forest(const unsigned int wood_number = 1000);
    ~Forest();
    void display(std::ostream &os = std::cout) const noexcept;
};

#endif
