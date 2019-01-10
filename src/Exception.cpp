#include "../header/Exception.hpp"
#include "../header/Constantes.hpp"
#include <iostream>

Exception::Exception() {}

Exception::~Exception() throw() {}

const char *Exception::what() const throw()
{
    return "General Exception";
}

InvalidFile::InvalidFile(std::string file) : std::invalid_argument(""), message_error("YOUR_FILE_DOES_NOT_EXIST : " + file)
{
    std::cerr << what() << std::endl;
}

InvalidFile::~InvalidFile() throw() {}

const char *InvalidFile::what() const throw()
{
    return message_error.c_str();
}

InvalidConfiguration::InvalidConfiguration(unsigned int config) : std::invalid_argument(""), message_error("MAX_CONFIGURATION : " + std::to_string(Constantes::CONFIG_NUMBER) + "\nYOUR_CHOICE : " + std::to_string(config))
{
    std::cerr << what() << std::endl;
}

InvalidConfiguration::~InvalidConfiguration() throw() {}

const char *InvalidConfiguration::what() const throw()
{
    return message_error.c_str();
}

OutOfRangeSuperior::OutOfRangeSuperior(const unsigned int range_out, const unsigned int range_maximum) : std::out_of_range(""), message_error("MAX_RANGE_EXPECTED : " + std::to_string(range_out) + "\nYOUR_RANGE : " + std::to_string(range_maximum))
{
    std::cerr << what() << std::endl;
}

OutOfRangeSuperior::~OutOfRangeSuperior() throw() {}

const char *OutOfRangeSuperior::what() const throw()
{
    return message_error.c_str();
}

BadAllocation::BadAllocation() {}
BadAllocation::~BadAllocation() throw() {}
const char *BadAllocation::what() const throw()
{
    return "VECTOR_TOO_HIGH";
}

InvalidGender::InvalidGender(const unsigned int gender_error) : std::invalid_argument(""), message_error("GENDER_EXPECTED_0_1, HERE : " + std::to_string(gender_error))
{
    std::cerr << what() << std::endl;
}

InvalidGender::~InvalidGender() throw() {}

const char *InvalidGender::what() const throw()
{
    return message_error.c_str();
}
