#include "../header/Constantes.hpp"
#include "../header/json.hpp"
#include "../header/Exception.hpp"
#include <fstream>
#include <iostream>
using json = nlohmann::json;

json Constantes::CONFIG_SIMU = R"({})"_json;
const unsigned int Constantes::MAP_NUMBER = 3;
const unsigned int Constantes::CHARACTER_NUMBER = 3;
const unsigned int Constantes::CONFIG_NUMBER = 2;

void Constantes::openingConfiguration(unsigned int config)
{
    if ((config <= 0) || (config > Constantes::CONFIG_NUMBER))
    {
        throw InvalidConfiguration(config);
    }
    std::string file_name = "./CONFIGURATIONS/Configuration.json";
    std::ifstream file(file_name);
    std::string key = "config" + std::to_string(config);
    if (!file.fail())
    {
        json configuration_simulation;
        file >> configuration_simulation;
        CONFIG_SIMU = configuration_simulation[key];
        file.close();
    }
    else
    {
        throw InvalidFile(file_name);
    }
}

void Constantes::displayConstantes(std::ostream &os) noexcept
{
    os << CONFIG_SIMU.dump(4);
    os << std::endl;
}
