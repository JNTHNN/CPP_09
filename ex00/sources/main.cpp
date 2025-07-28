#include "../includes/BitcoinExchange.hpp"

// c'est pas la db qui faut recup en argument mais un fichier txt
// donc ouvrir la db au sein du prog

int main(int argc, char **argv)
{
    (void)argv;
    
    if (argc != 2)
        throw BitcoinExchange::FileMissing();

    std::string extension("./db/data.csv");
    if (extension.size() < 4 || extension.substr(extension.size() - 4) != ".csv")
        return std::cerr << "Error file/db extension" << std::endl, 1;

    std::ifstream   db("./db/data.csv");
    if (!db.is_open())
        return std::cerr << "Error open file/db 0" << std::endl, 1;
    
    std::string line;
    
    BitcoinExchange btc;
    btc.initDB(db); //parsing db
    
// je vais devoir utiliser un find pour definir l'iterator-> key pour lire dans les 2? maps
        
}