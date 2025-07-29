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

        void    check_arg(int arg); // ajouter le file par la suite

        void    setMap(std::string& date, std::string& value);
        double  getExchange(const std::string& date);
        void    initDB();

        void    initInput(char* file);

        void    getValue(BitcoinExchange& db);
        void    processInputFile(char* file, BitcoinExchange& db);

        class FileMissing: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class FileExtension: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class NoValue: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        bool isValidDate(const std::string& date);
        bool isValidValue(const std::string& value);
        void processLine(const std::string& line, BitcoinExchange& db);
};


#endif