#ifndef CONSTANTES_HPP
#define CONSTANTES_HPP
#include "json.hpp"

using json = nlohmann::json;
class Constantes
{
  public:
    static json CONFIG_SIMU;
    static void openingConfiguration(int);
    static void displayConstantes(std::ostream &, json &) noexcept;
};

#endif
