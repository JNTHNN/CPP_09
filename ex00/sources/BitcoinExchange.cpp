#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
    return;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copied)
{
    (void)copied;
    return;
}

BitcoinExchange::~BitcoinExchange(void)
{
    return;
}

// BitcoinExchange&    BitcoinExchange::operator=(const BitcoinExchange& base)
// {
//     (void)base;
// }

const char* BitcoinExchange::FileMissing::what(void) const throw()
{
    return "Error: File missing.";
}

void    BitcoinExchange::setMap(std::string& date, std::string& value) // voir si je peux envoyer direct le double en value
{
    // std::cout << "value = " << value.c_str() << std::endl;
    if (value.empty()) // checker si la valeur est un digit/nombre
        this->_map[date] = -1;
    else
        this->_map[date] = std::atoi(value.c_str());
}

double  BitcoinExchange::getExchange(std::string& date)
{
    std::map<std::string, double>::iterator it = _map.find(date);
    if (it != _map.end())
        return it->second;
    return -1;
}

void    BitcoinExchange::initDB(std::ifstream& db)
{
    std::string line;
    std::cout << line << std::endl;
    std::getline(db, line);
    while (std::getline(db, line))
    {
        size_t pos = line.find(',');
        if (pos != std::string::npos)
        {
            std::string date = line.substr(0, pos);
            // std::cout << date << std::endl;
            std::string exchange_rate = line.substr(pos + 1, line.size());
            // std::cout << exchange_rate << std::endl;
            setMap(date, exchange_rate);
        }
    }
    std::string date("2009-01-02");
    std::cout << "le rate est de : " << getExchange(date) << std::endl;   
    std::string date2("2000-01-02");
    std::cout << "le rate est de : " << getExchange(date2) << std::endl;
}

// parsing de zinzin a base de std::lexicogramatical_compare year>month>day ?