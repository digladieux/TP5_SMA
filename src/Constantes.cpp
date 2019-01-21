#include "../header/Constantes.hpp"
#include "../header/json.hpp"
#include "../header/Exception.hpp"
#include <fstream>
#include <iostream>
using json = nlohmann::json;

json Constantes::CONFIG_SIMU = R"({})"_json;

void Constantes::openingConfiguration(unsigned int config)
{
    std::string file_name = "./CONFIGURATIONS/Configuration.json";
    std::ifstream file(file_name);
    if (!file.fail())
    {
        json configuration_simulation;
        file >> configuration_simulation;
        if ((config <= 0) || (config > configuration_simulation["maxConfig"]))
        {
            throw InvalidConfiguration(config);
        }

        std::string key = "config" + std::to_string(config);
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
