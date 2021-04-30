#include <iostream>
#include <fstream>
#include <string>
#include "read.h"
#include "cipher.h"

//Read file function, only used to work with ifstream and decryption
int readFile() {
    std::string readFile;
    std::string ciphertext;
    std::string ciphertextDummy;

    //Checks if cipher is loaded correctly
    int cipherChecker = cipherCheck();

    if (cipherChecker != 0) {
        return(-1);
    }

    //Gets the file to be decrypted from the user and checks if it is open
    std::cout << "Enter the file name you would like to read from and decrypt:" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, readFile);

    std::ifstream reader(readFile);

    if (!reader.is_open()) {
        reader.close();
        return(-1);
    }

    std::getline(reader, ciphertext);

    //Sends the encrypted text from ifstream readFile to decrypting
    ciphertextDummy = decrypt(ciphertext);

    std::cout << "Your decrypted message is: " << ciphertextDummy << std::endl;
    std::cout << "Shhh, it's a secret!" << std::endl << std::endl;

    reader.close();

    return(0);
}