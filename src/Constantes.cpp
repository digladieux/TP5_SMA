#include "../header/Constantes.hpp"
#include "../header/json.hpp"
#include <fstream>
#include <iostream>
using json = nlohmann::json;

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
        Constantes::displayConstantes(std::cout, CONFIG_SIMU);
        file.close();
    }
    else
    {
        std::cerr << "INVALID_FILE";
        exit(EXIT_FAILURE);
    }
}

void Constantes::displayConstantes(std::ostream &os, json &config) noexcept
{
    os << config.dump(4);
}
