#include <iostream>
#include <fstream>
#include <string>
#include "write.h"

int writeFile () {
    std::string writeFile;
    std::string plaintext;

    std::cout << "Enter the file name you would like to write to (up to 15 chars):" << std::endl;
    std::cin.ignore();    
    std::getline(std::cin, writeFile);

    std::ofstream writer(writeFile);
    
    if (!writer.is_open()) {
        writer.close();
        return(-1);
    }

    std::cout << "Enter in text you would like to encrypt: " << std::endl;
    std::getline(std::cin, plaintext);

    writer << plaintext;

    writer.close();

    return(0);
}