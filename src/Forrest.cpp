#include "../header/Forest.hpp"
#include <iostream>
Forest::Forest(const unsigned int wood_number) : CollectionPoint(GROUND_TYPE::FOREST, wood_number) {}

Forest::~Forest() {}

void Forest::display(std::ostream &os) const noexcept
{
    os << "F ";
}
