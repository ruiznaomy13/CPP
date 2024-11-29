
#ifndef BITCOIN_EXCHANGE_CPP
# define BITCOIN_EXCHANGE_CPP

#include <iostream>

class BitcoinExchange
{
	private:
		std::string _file_name;

	public:
		BitcoinExchange(std::string file_name);
		~BitcoinExchange();

        std::string getFileName();
};

#endif