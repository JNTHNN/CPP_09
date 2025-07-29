#include "../includes/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    try
    {
        BitcoinExchange btc;
        btc.check_arg(argc);
        btc.initDB();
        btc.exchange(argv[1], btc);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
