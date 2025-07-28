#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
    return;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copied): _map(copied._map)
{
    return;
}

BitcoinExchange::~BitcoinExchange(void)
{
    return;
}

BitcoinExchange&    BitcoinExchange::operator=(const BitcoinExchange& base)
{
    if (this != &base)
        _map = base._map;
    return *this;
}

const char* BitcoinExchange::FileMissing::what(void) const throw()
{
    return "Error: File missing.";
}

const char* BitcoinExchange::FileExtension::what(void) const throw()
{
    return "Error: File/DB extension.";
}

const char* BitcoinExchange::NoValue::what(void) const throw()
{
    return "No Value.";
}

void    BitcoinExchange::setMap(std::string& date, std::string& value) // voir si je peux envoyer direct le double en value
{
    // std::cout << "value = " << value.c_str() << std::endl;
    if (value.empty()) // checker si la valeur est un digit/nombre
        this->_map[date] = -1;
    else
        this->_map[date] = std::atoi(value.c_str());
}

double  BitcoinExchange::getExchange(const std::string& date)
{
    std::map<std::string, double>::iterator it = _map.find(date);
    if (it != _map.end())
        return it->second;
    throw NoValue();
}

void    BitcoinExchange::initDB(void)
{

    // trouver moyen de le placer dans une fonction
    std::ifstream   db("./db/data.csv");
    if (!db.is_open())
        throw FileMissing();
    // else if (db.size() < 4 || db.substr(db.size() - 4) != ".csv")
    //     throw BitcoinExchange::FileExtension();

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


void    BitcoinExchange::check_arg(int arg)
{
    if (arg != 2)
        throw BitcoinExchange::FileMissing();
}


void    BitcoinExchange::initInput(char* file)
{
    std::ifstream   input(file); // checker que c'est pas un dossier
    if (!input.is_open())
        throw FileMissing();
    std::string line;
    std::cout << line << std::endl;
    std::getline(input, line);
    while (std::getline(input, line))
    {
        size_t pos = line.find('|');
        if (pos != std::string::npos)
        {
            std::string date = line.substr(0, pos - 1); // gestion des spaces 
            std::cout << date << " ";
            std::string value = line.substr(pos + 2, line.size()); // gestion des spaces 
            std::cout << value << std::endl;
            setMap(date, value);
        }
    }
    
}

void    BitcoinExchange::getValue(BitcoinExchange& db)
{
    std::map<std::string, double>::iterator it = _map.find("2009-01-02"); // voir pour l'espace en fin de string
    if (it != _map.end())
        std::cout << "wallet = " << (it->second * db.getExchange("2009-01-02")) << std::endl;
}
