#ifndef CHARACTER_HPP
#define CHARACTER_HPP

enum class SEX
{
    MALE_CHARACTER_ADULT,
    FEMALE_CHARACTER_ADULT,
    MALE_CHARACTER_CHILD,
    FEMALE_CHARACTER_CHILD
};

enum class STATE
{
    NO_STATE,
    GOING_TO_COLLECTION_POINT,
    GOING_TO_TOWN_HALL,
    WORKING,
    BUILDING,
    HAVING_SEX
};

enum class TYPE_RESSOURCE_TRANSPORTED
{
    NO_RESSOURCE,
    ROCK,
    FISH,
    WOOD,
    FOOD,
};

typedef struct StructCoordinates
{
    unsigned int abscissa;
    unsigned int ordinate;

} Coordinates;

class Character
{
  protected:
    static unsigned int character_number;
    unsigned int character_id;
    unsigned int character_age;
    SEX character_gender;
    STATE character_current_state;
    TYPE_RESSOURCE_TRANSPORTED type_ressource_transported;
    StructCoordinates direction;

  public:
    Character();
    Character(SEX, const unsigned int age = 0);
    virtual ~Character();

    const Character &operator=(const Character &);
    unsigned int getCharacterId() const noexcept;
    unsigned int getCharacterAge() const noexcept;
    SEX getCharacterGender() const noexcept;
    STATE getCharacterCurrentState() const noexcept;
    TYPE_RESSOURCE_TRANSPORTED getTypeRessourceTransported() const noexcept;
    StructCoordinates getDirection() const noexcept;

    void setCharacterCurrentState(STATE) noexcept;
    void setTypeRessourceTransported(TYPE_RESSOURCE_TRANSPORTED) noexcept;
    void setCharacterGenderAdult() noexcept;
    void setDirection(unsigned int, unsigned int) noexcept;

    void incrementAge() noexcept;
    bool isDead() const noexcept;
};
#endif
