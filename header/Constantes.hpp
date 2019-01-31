#ifndef CONSTANTES_HPP
#define CONSTANTES_HPP
#include "json.hpp"
#include <iostream>
using json = nlohmann::json;
class Constantes
{
  public:
    static json CONFIG_SIMU;
    static json CHARACTERS ;
    static json MAPS ;
    static void getAllJson() ;
    static void setConfiguration(unsigned int) ;
    static void displayConfiguration(unsigned int, std::ostream &os = std::cout);
};

#endif
