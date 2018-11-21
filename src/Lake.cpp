#include "../header/Lake.hpp"
#include <iostream>

Lake::Lake(const unsigned int fish_number) : CollectionPoint(GROUND_TYPE::LAKE, fish_number) {}

Lake::~Lake() {}

void Lake::display() const noexcept
{
    std::cout << " L ";
}
