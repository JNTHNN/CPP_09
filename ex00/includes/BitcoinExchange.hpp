#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>

class   BitcoinExchange
{
    private:

    // utiliser std::map(date, valeur)

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& copied);
        ~BitcoinExchange();
        BitcoinExchange& operator=(const BitcoinExchange& base);

        class FileMissing: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};


#endif