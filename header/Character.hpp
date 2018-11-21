#ifndef CHARACTER_HPP
#define CHARACTER_HPP

enum class SEX
{
    MALE_CHARACTER_ADULT,
    FEMALE_CHARACTER_ADULT,
    MALE_CHARACTER_CHILD,
    FEMALE_CHARACTER_CHILD
};

class Character
{
  protected:
    static unsigned int character_number;
    unsigned int character_id;
    unsigned int character_age;
    SEX character_gender;

  public:
    Character();
    Character(SEX, const unsigned int age = 0);
    virtual ~Character();

    const Character &operator=(const Character &);
    unsigned int getCharacterId() const noexcept;
    unsigned int getCharacterAge() const noexcept;
    SEX getCharacterGender() const noexcept;

    void incrementAge() noexcept;
    bool isDead() const noexcept;
};
#endif
