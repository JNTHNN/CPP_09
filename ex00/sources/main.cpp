#include "../includes/BitcoinExchange.hpp"

// c'est pas la db qui faut recup en argument mais un fichier txt
// donc ouvrir la db au sein du prog

int main(int argc, char **argv)
{
    try
    {
        BitcoinExchange btc;
        btc.check_arg(argc);
        btc.initDB(); //parsing db

        BitcoinExchange input;
        // input.initInput(argv[1]);

        btc.processInputFile(argv[1], btc);
        input.getValue(btc);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    
// je vais devoir utiliser un find pour definir l'iterator-> key pour lire dans les 2? maps
        
}