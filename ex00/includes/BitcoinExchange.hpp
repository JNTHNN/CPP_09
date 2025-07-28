#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>


class   BitcoinExchange
{
    private:
        std::map<std::string, double>   _map;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& copied);
        ~BitcoinExchange();
        BitcoinExchange& operator=(const BitcoinExchange& base);

        void    setMap(std::string& date, std::string& value);
        double  getExchange(std::string& date);
        void    initDB(std::ifstream& db);

        class FileMissing: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};


#endif