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
    std::map<std::string, double>::iterator it = _map.lower_bound(date);
    
    // Si on trouve la date exacte
    if (it != _map.end() && it->first == date)
        return it->second;
    
    // Sinon, chercher la date antérieure la plus proche
    if (it == _map.begin())
        throw NoValue(); // Aucune date antérieure
    
    --it; // Date antérieure la plus proche
	std::cout << "la date la plus proche : " << it->first << std::endl;
    return it->second;
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
    std::string date("2011-01-03");
    std::cout << "le rate est de : " << getExchange(date) << std::endl;   
    std::string date2("2011-01-03");
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
    std::ifstream   input(file);
    if (!input.is_open())
        throw FileMissing();
    
    std::string line;
    std::getline(input, line); // Skip header line
    
    while (std::getline(input, line))
    {
        size_t pos = line.find('|');
        if (pos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        // Extract date and value with proper trimming
        std::string date = line.substr(0, pos);
        std::string value = line.substr(pos + 1);
        
        // Trim spaces
        while (!date.empty() && date.back() == ' ') date.pop_back();
        while (!value.empty() && value.front() == ' ') value.erase(0, 1);
        
        // Validate date format (YYYY-MM-DD)
        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        
        // Validate value (0-1000, positive number)
        if (!isValidValue(value))
        {
            std::cerr << "Error: bad input => " << value << std::endl;
            continue;
        }
        
        // Process valid line - need to pass db reference
        // This will be called from main with the db instance
    }
}

void    BitcoinExchange::getValue(BitcoinExchange& db)
{
    std::map<std::string, double>::iterator it = _map.find("2009-01-02"); // voir pour l'espace en fin de string
    if (it != _map.end())
        std::cout << "wallet = " << (it->second * db.getExchange("2009-01-02")) << std::endl;
}

bool    BitcoinExchange::isValidDate(const std::string& date)
{
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;
    
    // Check if year, month, day are digits
    for (int i = 0; i < 10; i++) {
        if (i != 4 && i != 7 && !isdigit(date[i])) return false;
    }
    
    // Extract year, month, day
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    
    // Basic range validation
    if (year < 1000 || year > 9999) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;
    
    return true;
}

bool    BitcoinExchange::isValidValue(const std::string& value)
{
    if (value.empty()) return false;
    
    char* endptr;
    double val = std::strtod(value.c_str(), &endptr);
    
    // Check if conversion was successful
    if (*endptr != '\0') return false;
    
    // Check range (0 to 1000)
    if (val < 0 || val > 1000) return false;
    
    return true;
}

void    BitcoinExchange::processLine(const std::string& line, BitcoinExchange& db)
{
    size_t pos = line.find('|');
    if (pos == std::string::npos)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }
    
    // Extract date and value with proper trimming
    std::string date = line.substr(0, pos);
    std::string value = line.substr(pos + 1);
    
    // Trim spaces
    while (!date.empty() && date.back() == ' ') date.pop_back();
    while (!value.empty() && value.front() == ' ') value.erase(0, 1);
    
    // Validate date format (YYYY-MM-DD)
    if (!isValidDate(date))
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return;
    }
    
    // Validate value (0-1000, positive number)
    if (!isValidValue(value))
    {
        std::cerr << "Error: bad input => " << value << std::endl;
        return;
    }
    
    try {
        double val = std::strtod(value.c_str(), NULL);
        double rate = db.getExchange(date);
        std::cout << date << " => " << val << " = " << (val * rate) << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void    BitcoinExchange::processInputFile(char* file, BitcoinExchange& db)
{
    std::ifstream   input(file);
    if (!input.is_open())
        throw FileMissing();
    
    std::string line;
    std::getline(input, line); // Skip header line
    
    while (std::getline(input, line))
    {
        processLine(line, db);
    }
}
