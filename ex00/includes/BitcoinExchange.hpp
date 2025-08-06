#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
#include <iomanip>


class   BitcoinExchange
{
	private:
		std::map<std::string, double>   _map;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copied);
		~BitcoinExchange();
		BitcoinExchange&	operator=(const BitcoinExchange& base);

		void    			check_arg(int arg);

		void    			setMap(std::string& date, std::string& value);
		double  			getExchange(const std::string& date);
		void    			initDB();

		void    			exchange(char* file, BitcoinExchange& db);
		
		bool				isValidDate(const std::string& date);
		bool    			isValidValue(const std::string& value);
		bool    			isBisexYear(int year);
		void				initInput(const std::string& line, BitcoinExchange& db);
		
		class ErrorFile: public std::exception
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
};


#endif