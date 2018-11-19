#ifndef COLLECTION_POINT_HPP
#define COLLECTION_POINT_HPP
#include "MaleCharacter.hpp"
#include "Ground.hpp"
#include <vector>

class CollectionPoint : public Ground
{
  protected:
    std::vector<MaleCharacter *> vector_worker;
    unsigned int ressources_number;

  public:
    CollectionPoint(const unsigned int ressources_nb = 1000);
    virtual ~CollectionPoint();

    unsigned int getVectorSize() const noexcept;
    void addWorker(MaleCharacter *);
    void removeWorker(const unsigned int);
    MaleCharacter* getWorker(const unsigned int);

    unsigned int getRessourcesNumber() const noexcept;
    void setRessources(const unsigned int);
    bool ressourcesNumberExtracted(const unsigned int);

    void evolutionRessources() noexcept;
};

#endif
