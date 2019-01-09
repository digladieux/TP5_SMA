#include "../header/Constantes.hpp"
#include "../header/json.hpp"
#include <fstream>
#include <iostream>
using json = nlohmann::json;

json Constantes::CONFIG_SIMU = R"({})"_json;
const unsigned int Constantes::MAP_NUMBER = 3;
const unsigned int Constantes::CHARACTER_NUMBER = 3;
const unsigned int Constantes::CONFIG_NUMBER = 2;

void Constantes::openingConfiguration(int config)
{
    if ((config < 0) || (config > 3))
    {
        std::cerr << "INVALID_CONFIGURATION" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::ifstream file("./CONFIGURATIONS/Configuration.json");
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
        std::cerr << "INVALID_FILE";
        exit(EXIT_FAILURE);
    }
}

void Constantes::displayConstantes(std::ostream &os) noexcept
{
    os << CONFIG_SIMU.dump(4);
    os << std::endl;
}
