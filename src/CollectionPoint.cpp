#include "../header/CollectionPoint.hpp"
#include "../header/mt19937ar.h"
#include <iostream>
#include <exception>
CollectionPoint::CollectionPoint(GROUND_TYPE type, const unsigned int ressources_nb) : Ground(type), ressources_number(ressources_nb) {}

CollectionPoint::~CollectionPoint() {}

unsigned int CollectionPoint::getRessourcesNumber() const noexcept
{
    return ressources_number;
}

void CollectionPoint::setRessources(const unsigned int new_ressources_number)
{
    ressources_number = new_ressources_number;
}

bool CollectionPoint::ressourcesNumberExtracted(const unsigned int ressources_number_extracted)
{
    bool flag = true;
    if ((int)ressources_number - (int)ressources_number_extracted < 0)
    {
        flag = false;
    }
    else
    {
        ressources_number -= ressources_number_extracted;
    }
    return flag;
}

/*TODO : methode virtuelle a definir dans les autres apres ? */
void CollectionPoint::evolutionRessources() noexcept
{
    double evolution = genrand_real1();
    double ressources_nb = genrand_int31() % 10;

    if (evolution < 0.1)
    {
        ressources_number += ressources_nb;
    }
}

void CollectionPoint::display() const noexcept
{
    std::cout << " C ";
}
