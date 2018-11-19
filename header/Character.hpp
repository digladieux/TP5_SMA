#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Ground.hpp"

class Character : public Ground
{
  protected:
    static unsigned int character_number;
    unsigned int character_id;
    unsigned int character_age;

  public:
    Character(const unsigned int age = 0);
    virtual ~Character();

    const Character &operator=(const Character &);
    unsigned int getCharacterId() const noexcept;
    unsigned int getCharacterAge() const noexcept;

    void incrementAge() noexcept;
    bool isDead() const noexcept;
};
#endif
