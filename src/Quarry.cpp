#include "../header/Quarry.hpp"
#include <iostream>

Quarry::Quarry(const unsigned int rock_number) : CollectionPoint(GROUND_TYPE::QUARRY, rock_number) {}

Quarry::~Quarry(){}

void Quarry::display() const noexcept
{
    std::cout << " Q ";
}
