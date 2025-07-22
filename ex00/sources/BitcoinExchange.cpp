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