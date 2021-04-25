#include <iostream>
#include <fstream>
#include <string>
#include "write.h"

int writeFile () {
    std::string writeFile;

    std::cout << "Enter the file name you would like to write to (up to 15 chars): " << std::endl;    
    std::getline(std::cin, writeFile);
    std::cin.ignore();
    std::cout << writeFile << std::endl;

    std::ifstream writer (writeFile);

    if (!writer.is_open()) {
        writer.close();
        return(-1);
    }

    



    return(0);
}