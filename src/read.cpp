#include <iostream>
#include <fstream>
#include <string>
#include "read.h"
#include "cipher.h"

int readFile() {
    std::string readFile;
    std::string ciphertext;
    std::string ciphertextDummy;

    int cipherChecker = cipherCheck();

    if (cipherChecker != 0) {
        return(-1);
    }

    std::cout << "Enter the file name you would like to read from and decrypt:" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, readFile);

    std::ifstream reader(readFile);

    if (!reader.is_open()) {
        reader.close();
        return(-1);
    }

    std::getline(reader, ciphertext);

    ciphertextDummy = decrypt(ciphertext);

    std::cout << "Your decrypted message is: " << ciphertextDummy << std::endl;
    std::cout << "Shhh, it's a secret!" << std::endl << std::endl;

    reader.close();

    return(0);
}