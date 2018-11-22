#ifndef COLLECTION_POINT_HPP
#define COLLECTION_POINT_HPP
#include "MaleCharacter.hpp"
#include "Ground.hpp"
#include <vector>

class CollectionPoint : public Ground
{
  protected:
    unsigned int ressources_number;

  public:
    CollectionPoint(GROUND_TYPE type, const unsigned int ressources_nb = 1000);
    virtual ~CollectionPoint();

    unsigned int getRessourcesNumber() const noexcept;
    void setRessources(const unsigned int);
    bool ressourcesNumberExtracted(const unsigned int);
    void evolutionRessources() noexcept;

    virtual void display(std::ostream &os) const noexcept;
};

#endif
