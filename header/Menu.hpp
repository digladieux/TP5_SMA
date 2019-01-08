#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
class Menu
{
  public:
    static void displayWelcome(std::ostream &os = std::cout) noexcept;
    static unsigned int displayMapChoice(std::ostream &os = std::cout) noexcept;
    static unsigned int displayCharacterChoice(std::ostream &os = std::cout) noexcept;
    static unsigned int displayConfigChoice(std::ostream &os = std::cout) noexcept;
};
void displayAllMap(std::ostream &);
void displayAllConfig(std::ostream &);
void displayAllCharacter(std::ostream &os);
void displayMapFile(std::ostream &, std::string);
void displayCharacterFile(std::ostream &, std::string);

#endif
