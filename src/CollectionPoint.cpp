#include "../header/CollectionPoint.hpp"
#include "../header/mt19937ar.h"
#include <iostream>
#include <exception>
CollectionPoint::CollectionPoint(const unsigned int ressources_nb) : vector_worker(0), ressources_number(ressources_nb) {}

CollectionPoint::~CollectionPoint(){}

unsigned int CollectionPoint::getVectorSize() const noexcept
{
    return vector_worker.size();
}
void CollectionPoint::addWorker(MaleCharacter *new_worker)
{
    try
    {
        vector_worker.push_back(new_worker);
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "VECTOR_TOO_HIGH" << std::endl;
        throw e;
    }
}

void CollectionPoint::removeWorker(const unsigned int index)
{
    if (( (int)index < 0) || (index >= vector_worker.size()))
    {
        std::cerr << "[0;" << vector_worker.size()-1 << "], INDEX = " << index << std::endl;
        throw std::out_of_range("OUT_OF_RANGE_EXCEPTION");
    }
        vector_worker.erase(vector_worker.begin() + index);
}

MaleCharacter *CollectionPoint::getWorker(const unsigned int index)
{
     if (( (int)index < 0) || (index >= vector_worker.size()))
    {
        std::cerr << "[0;" << vector_worker.size()-1 << "], INDEX = " << index << std::endl;
        throw std::out_of_range("OUT_OF_RANGE_EXCEPTION");
    }

    return vector_worker[index];
}

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
