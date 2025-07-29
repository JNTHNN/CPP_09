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

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& base)
{
	if (this != &base)
		_map = base._map;
	return *this;
}

const char*	BitcoinExchange::ErrorFile::what(void) const throw()
{
	return "Error: could not open file.";
}

const char*	BitcoinExchange::FileExtension::what(void) const throw()
{
	return "Error: File/DB extension.";
}

const char*	BitcoinExchange::NoValue::what(void) const throw()
{
	return "No Value.";
}

void	BitcoinExchange::setMap(std::string& date, std::string& value)
{
	if (value.empty()) // checker si la valeur est un digit/nombre
		this->_map[date] = -1;
	else
		this->_map[date] = std::strtod(value.c_str(), NULL);
}

double  BitcoinExchange::getExchange(const std::string& date)
{
	std::map<std::string, double>::iterator it = _map.lower_bound(date);
	if (it != _map.end() && it->first == date)
		return it->second;
	if (it == _map.begin())
		throw NoValue();
	--it;
	// std::cout << "la date la plus proche : " << it->first << std::endl;
	return it->second;
}

void    BitcoinExchange::initDB(void)
{
	std::ifstream   db("./db/data.csv");
	if (!db.is_open())
		throw ErrorFile();
	std::string line;
	std::getline(db, line);
	while (std::getline(db, line))
	{
		size_t pos = line.find(',');
		if (pos != std::string::npos)
		{
			std::string date = line.substr(0, pos);
			std::string exchange_rate = line.substr(pos + 1, line.size());
			setMap(date, exchange_rate);
		}
	}
}

void    BitcoinExchange::check_arg(int arg)
{
	if (arg != 2)
		throw BitcoinExchange::ErrorFile();
}

bool    BitcoinExchange::isValidDate(const std::string& date)
{
	if (date.length() != 10)
		return std::cerr << "Error: bad date => " << date << std::endl, false;
	if (date[4] != '-' || date[7] != '-')
		return std::cerr << "Error: bad date => " << date << std::endl, false;
	
	for (int i = 0; i < 10; i++)
		if (i != 4 && i != 7 && !isdigit(date[i]))
			return std::cerr << "Error: bad date => " << date << std::endl, false;

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	
	if (year < 2008 || year > 9999)
	{
		if (year < 2008)
			return std::cerr << "Error: date before bitcoin creation (2008) => " << date << std::endl, false;
		else
			return std::cerr << "Error: bad date, so far so good => " << date << std::endl, false;
	}
	if (month < 1 || month > 12)
		return std::cerr << "Error: bad date => " << date << std::endl, false;
	if ((month == 2 && !isBisexYear(year) && (day < 1 || day > 28)) || (month == 2 && isBisexYear(year) && (day < 1 || day > 29)))
		return std::cerr << "Error: bad date (february) => " << date << std::endl, false;
	if ((day < 1 || day > 31))
		return std::cerr << "Error: bad date => " << date << std::endl, false;
	return true;
}

bool    BitcoinExchange::isValidValue(const std::string& value)
{
	if (value.empty())
		return std::cerr << "Error: bad value => " << value << std::endl, false;   
	char* endptr;
	double val = std::strtod(value.c_str(), &endptr);
	if (*endptr != '\0')
		return std::cerr << "Error: bad value => " << value << std::endl, false;
	if (val < 0 || val > 1000)
	{
		if (val < 0)
			return std::cerr << "Error: not a positive number."<< std::endl, false;
		else
			return std::cerr << "Error: too large a number." << std::endl, false;
	}
	return true;
}

void    BitcoinExchange::initInput(const std::string& line, BitcoinExchange& db)
{
	size_t pos = line.find('|');
	if (pos == std::string::npos)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return;
	}
	std::string date = line.substr(0, pos);
	std::string value = line.substr(pos + 1);
	
	while (!date.empty() && date[date.size() - 1] == ' ')
		date.erase(date.size() - 1, 1);
	while (!value.empty() && value[0] == ' ')
		value.erase(0, 1);

	if (!isValidDate(date) || !isValidValue(value))
		return;
	
	try
	{
		double val = std::strtod(value.c_str(), NULL);
		double rate = db.getExchange(date);
		std::cout << date << " => " << val << " = " << (val * rate) << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void    BitcoinExchange::exchange(char* file, BitcoinExchange& db)
{
	std::ifstream   input(file);
	if (!input.is_open())
		throw ErrorFile();
	
	std::string line;
	std::getline(input, line); // Skip header line
	while (std::getline(input, line))
		initInput(line, db);
}

bool    BitcoinExchange::isBisexYear(int year)
{
	return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}
