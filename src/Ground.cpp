#include "../header/Ground.hpp"

unsigned int Ground::ground_number = 0;

Ground::Ground() : ground_id(ground_number)
{
    ground_number++;
}
Ground::~Ground(){}
unsigned int Ground::getGroundId() const noexcept
{
    return ground_id;
}

void Ground::setGroundId(const unsigned int new_ground_id) noexcept
{
    ground_id = new_ground_id;
}
/*TODO : Ground:15 Verifier si l'id est correct en fonction de la taille de la map */

