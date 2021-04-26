#include <iostream>
#include <fstream>
#include <string>
#include "cipher.h"

int cipher = 0;

int cipherCheck() {
    switch(cipher) {
        case 0:
            {
                return(0);
                break;
            }
        case 1:
            {
                return(0);
                break;
            }
        default:
            {
                std::cerr << "Error, cipher is not loaded in! Better check it!" << std::endl;
                
                return(-1);
            }
    }
}

std::string encrypt(std::string plaintext) {
    int caesarKey;
    std::string ciphertext = plaintext;

    switch(cipher) {
        case 0:
        {
            for (char &i : ciphertext) {
                i++;
            }

            break;
        }
        case 1:
        {
            std::cout << "Enter key for Caesar cipher: ";
            std::cin >> caesarKey;

            for (char &i : ciphertext) {
                i = i + caesarKey;
            }

            break;
        }
        default:
        {
            std::cerr << "Error, chosen cipher is not loaded in!" << std::endl;

            return("ERROR");
        }
    }

    return(ciphertext);
}

std::string decrypt(std::string ciphertext) {
    int caesarKey;
    std::string plaintext = ciphertext;

    switch(cipher) {
        case 0:
        {
            for (char &i : plaintext) {
                i--;
            }

            break;
        }
        case 1:
        {
            std::cout << "Enter key for Caesar cipher: ";
            std::cin >> caesarKey;

            for (char &i : plaintext) {
                i = i - caesarKey;
            }

            break;
        }
        default:
        {
            std::cerr << "Error, chosen cipher is not loaded in!" << std::endl;

            return("ERROR");
        }
    }

    return(plaintext);
}

int chooseCipher() {
    std::string userOp;
    int whichCipher;

    std::cout << "The default cipher is Caesar with a key of 1, would you like to continue?" << std::endl;
    std::cout << "Yes or No? ";
    std::cin >> userOp;

    if (userOp.compare("Yes") != 0) {
        return(-1);
    }

    std::cout << "1. Caesar Cipher" << std::endl;
    std::cout << "2. Vigenere Cipher" << std::endl;
    std::cout << "Enter the cipher you would like to use:" << std::endl;
    std::cout << "--> ";
    std::cin >> whichCipher;

    cipher = whichCipher;

    std::cout << std::endl;

    return(0);
    
}