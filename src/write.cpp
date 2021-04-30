#include <iostream>
#include <fstream>
#include <string>
#include "write.h"
#include "cipher.h"

//Write file function, only used to work with ofstream and encrypting
int writeFile () {
    std::string writeFile;
    std::string plaintext;

    //Checks if cipher is loaded right
    int cipherChecker = cipherCheck();

    if (cipherChecker != 0) {
        return(-1);
    }

    //Gets user input and checks if file exists and is open
    std::cout << "Enter the file name you would like to write to:" << std::endl;
    std::cin.ignore();    
    std::getline(std::cin, writeFile);

    std::ofstream writer(writeFile);
    
    if (!writer.is_open()) {
        writer.close();
        return(-1);
    }

    //User enters in text and is sent to encrypting
    std::cout << "Enter in text you would like to encrypt (without new lines): " << std::endl;
    std::getline(std::cin, plaintext);
    
    plaintext = encrypt(plaintext);

    writer << plaintext;
    
    writer.close();

    return(0);
}