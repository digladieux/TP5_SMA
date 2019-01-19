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

InvalidJob::InvalidJob(unsigned int job_error) : std::invalid_argument(""), message_error("JOB_MAX_EXPECTED : 4\nHERE : " + std::to_string(job_error))
{
    std::cerr << what() << std::endl;
}

InvalidJob::~InvalidJob() throw() {}

const char *InvalidJob::what() const throw()
{
    return message_error.c_str();
}

OutOfRangeSuperior::OutOfRangeSuperior(const unsigned int range_maximum, const unsigned int range_out) : std::out_of_range("")
{
    setValueOutOfRange(range_out, range_maximum);
    std::cerr << what() << std::endl;
}

OutOfRangeSuperior::~OutOfRangeSuperior() throw() {}

const char *OutOfRangeSuperior::what() const throw()
{
    return message_error.c_str();
}
void OutOfRangeSuperior::setValueOutOfRange(const unsigned int range_out, const unsigned int range_maximum)
{
    message_error = "MAX_RANGE_EXPECTED : " + std::to_string(range_out) + "\nYOUR_RANGE : " + std::to_string(range_maximum);
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

CurrentDateBeforeBirthException::CurrentDateBeforeBirthException(const Date &current_date, const Date &date_of_birth) : std::invalid_argument(""), message_error("CURRENT_DATE : " + current_date.to_string() + "DATE_OF_BIRTH : " + date_of_birth.to_string())
{
    std::cerr << what() << std::endl;
}

CurrentDateBeforeBirthException::~CurrentDateBeforeBirthException() throw() {}

const char *CurrentDateBeforeBirthException::what() const throw()
{
    return message_error.c_str();
}

ConstructorDateException::ConstructorDateException(const unsigned int day, const unsigned int month, const unsigned int year) : std::invalid_argument(""), message_error("DATE_INVALID : " + std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year))
{
    std::cerr << what() << std::endl;
}

ConstructorDateException::~ConstructorDateException() throw() {}

const char *ConstructorDateException::what() const throw()
{
    return message_error.c_str();
}

InvalidGroundType::InvalidGroundType(unsigned int ground_type_error) : std::invalid_argument(""), message_error("GROUND_TYPE_MAX_EXPECTED : 4\nHERE : " + std::to_string(ground_type_error))
{
    std::cerr << what() << std::endl;
}

InvalidGroundType::~InvalidGroundType() throw() {}

const char *InvalidGroundType::what() const throw()
{
    return message_error.c_str();
}

InvalidGroundTypeReadingFile::InvalidGroundTypeReadingFile(char ground_type_error) : std::invalid_argument(""), message_error("GROUND_TYPE_MUST_BE : ., T, F, f, L, Q\nHERE : " + std::to_string(ground_type_error))
{
    std::cerr << what() << std::endl;
}

InvalidGroundTypeReadingFile::~InvalidGroundTypeReadingFile() throw() {}

const char *InvalidGroundTypeReadingFile::what() const throw()
{
    return message_error.c_str();
}

InvalidDirection::InvalidDirection(const unsigned int x, const unsigned int y, const unsigned int row_number, const unsigned int column_number) : std::invalid_argument("")
{
    setValueDirectionException(x, y, row_number, column_number);
}
InvalidDirection::~InvalidDirection() throw() {}

const char *InvalidDirection::what() const throw()
{
    return message_error.c_str();
}

void InvalidDirection::setValueDirectionException(const unsigned int x, const unsigned int y, const unsigned int row_number, const unsigned int column_number)
{
    message_error = "MAP : [" + std::to_string(row_number) + "][" + std::to_string(column_number) + "]\nHERE_DIRECTION : [" + std::to_string(x) + "][" + std::to_string(y) + "]\n";
}

InvalidNumberOfCharacter::InvalidNumberOfCharacter(const unsigned int index_out, const unsigned int index_max) : std::invalid_argument(""), message_error("MAXIMUM_EXPECTED : " + std::to_string(index_max) + "\nHERE : " + std::to_string(index_out)) 
{
        std::cerr << what() << std::endl;
}
InvalidNumberOfCharacter::~InvalidNumberOfCharacter() throw() {}

const char *InvalidNumberOfCharacter::what() const throw()
{
    return message_error.c_str();
}


InvalidNumberOfMap::InvalidNumberOfMap(const unsigned int index_out, const unsigned int index_max) : std::invalid_argument(""), message_error("MAXIMUM_EXPECTED : " + std::to_string(index_max) + "\nHERE : " + std::to_string(index_out)) 
{
        std::cerr << what() << std::endl;
}
InvalidNumberOfMap::~InvalidNumberOfMap() throw() {}

const char *InvalidNumberOfMap::what() const throw()
{
    return message_error.c_str();
}


InvalidKey::InvalidKey(const unsigned int index_out, const unsigned int index_max) : std::invalid_argument(""), message_error("INVALID_KEY_MAXIMUM_EXPECTED : " + std::to_string(index_max) + "\nHERE : " + std::to_string(index_out)) 
{
        std::cerr << what() << std::endl;

}
InvalidKey::~InvalidKey() throw() {}

const char *InvalidKey::what() const throw()
{
    return message_error.c_str();
}

InvalidTeam::InvalidTeam(const unsigned int index_out) : std::invalid_argument(""), message_error("MAXIMUM_TEAM_EXPECTED : 1\nHERE : " + std::to_string(index_out)) 
{
        std::cerr << what() << std::endl;

}
InvalidTeam::~InvalidTeam() throw() {}

const char *InvalidTeam::what() const throw()
{
    return message_error.c_str();
}