#ifndef GROUND_HPP
#define GROUND_HPP

#include "Character.hpp"
#include <vector>
#include <iostream>
enum class GROUND_TYPE
{
    LAND,
    TOWN_HALL,
    QUARRY,
    LAKE,
    FARM,
    FOREST,
};
class Ground
{
  protected:
    static unsigned int ground_number;
    unsigned int ground_id;
    GROUND_TYPE ground_type;
    std::vector<Character *> vector_character;

  public:
    Ground(GROUND_TYPE type = GROUND_TYPE::LAND);
    Ground(const Ground *);
    virtual ~Ground();

    unsigned int getGroundId() const noexcept;
    GROUND_TYPE getGroundType() const noexcept;

    unsigned int getVectorSize() const noexcept;
    void addCharacter(Character *);
    void removeCharacter(const unsigned int);
    Character *getCharacter(const unsigned int);

    Ground &operator=(const Ground &);

    static void resetGroundNumber() noexcept;
    void clearVector() noexcept;
    virtual void display(std::ostream &os = std::cout) const noexcept;
};

#endif
