#ifndef CONSTANTES_HPP
#define CONSTANTES_HPP
#include "json.hpp"
#include <iostream>
using json = nlohmann::json;
class Constantes
{
  public:
    static json CONFIG_SIMU;
    static const unsigned int MAP_NUMBER;
    static const unsigned int CHARACTER_NUMBER;
    static const unsigned int CONFIG_NUMBER;
    static void openingConfiguration(unsigned int);
    static void displayConstantes(std::ostream &os = std::cout) noexcept;
};

#endif
