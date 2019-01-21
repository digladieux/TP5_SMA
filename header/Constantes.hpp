#ifndef CONSTANTES_HPP
#define CONSTANTES_HPP
#include "json.hpp"
#include <iostream>
using json = nlohmann::json;
class Constantes
{
  public:
    static json CONFIG_SIMU;
    static void openingConfiguration(unsigned int);
    static void displayConstantes(std::ostream &os = std::cout) noexcept;
};

#endif
