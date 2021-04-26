#include <iostream>
#include <fstream>
#include <string>
#include "write.h"
#include "cipher.h"

int writeFile () {
    std::string writeFile;
    std::string plaintext;

    int cipherChecker = cipherCheck();

    if (cipherChecker != 0) {
        return(-1);
    }

    std::cout << "Enter the file name you would like to write to:" << std::endl;
    std::cin.ignore();    
    std::getline(std::cin, writeFile);

    std::ofstream writer(writeFile);
    
    if (!writer.is_open()) {
        writer.close();
        return(-1);
    }

    std::cout << "Enter in text you would like to encrypt: " << std::endl;
    std::getline(std::cin, plaintext);
    
    plaintext = encrypt(plaintext);

    writer << plaintext;

    writer.close();

    return(0);
}