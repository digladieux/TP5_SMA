#include "../header/Farm.hpp"
#include <iostream>

Farm::Farm(const unsigned int wood_number) : CollectionPoint(GROUND_TYPE::FARM, wood_number) {}

Farm::~Farm() {}

void Farm::display(std::ostream &os) const noexcept
{
    os << " f ";
}
