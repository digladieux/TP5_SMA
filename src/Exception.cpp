#include "../header/Exception.hpp"
#include "../header/Constantes.hpp"
#include <iostream>

Exception::Exception() {}

Exception::~Exception() throw() {}

const char *Exception::what() const throw()
{
    return "General Exception";
}

InvalidFile::InvalidFile(std::string file) : file_name_error(file) {}

InvalidFile::~InvalidFile() throw() {}

const char *InvalidFile::what() const throw()
{
    std::string message_error = "YOUR_FILE_DOES_NOT_EXIST : " + file_name_error;
    return message_error.c_str();
}

InvalidConfiguration::InvalidConfiguration(unsigned int config) : config_error(config) {}

InvalidConfiguration::~InvalidConfiguration() throw() {}

const char *InvalidConfiguration::what() const throw()
{
    std::string message_error = "MAX_CONFIGURATION " + std::to_string(Constantes::CONFIG_NUMBER) + "\n YOUR_CHOICE : " + std::to_string(config_error);
    return message_error.c_str();
}

OutOfRangeSuperior::OutOfRangeSuperior(unsigned int range_out, unsigned int range_maximum) : range_error(range_out), range_max(range_maximum) {}

OutOfRangeSuperior::~OutOfRangeSuperior() throw() {}

const char *OutOfRangeSuperior::what() const throw()
{
    std::string message_error = "MAX_RANGE_EXPECTED : " + std::to_string(range_max) + "\nYOUR_RANGE : " + std::to_string(range_error);
    return message_error.c_str();
}
