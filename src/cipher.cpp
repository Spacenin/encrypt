#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "cipher.h"

//Global variable cipher, that represents which cipher is being used
int cipher = 0;

//Checks if cipher is loaded in and functioning right, is used before every encryption/decryption
int cipherCheck() {
    switch(cipher) {
        case 0:
        {
            return(0);
        }
        case 1:
        {
            return(0);
        }
        case 2:
        {
            return(0);
        }
        case 3:
        {
            return(0);
        }
        default:
        {
            std::cerr << "Error, cipher is not loaded in! Better check it!" << std::endl;
            
            return(-1);
        }
    }
}

//Encryption function
std::string encrypt(std::string plaintext) {
    std::string ciphertext = plaintext;

    switch(cipher) {
        //Default encrypt
        case 0:
        {
            for (char &i : ciphertext) {
                i++;
            }

            break;
        }
        //Caesar encrypt
        case 1:
        {
            int caesarKey;

            std::cout << "Enter key for Caesar cipher: ";
            std::cin >> caesarKey;

            for (char &i : ciphertext) {
                i = i + caesarKey;
            }

            break;
        }
        //Vignere encrypt
        case 2:
        {
            std::string vigenereKey;
            std::string vigenereKeyDummy;

            std::cout << "Enter key for Vigenere cipher: ";
            std::getline(std::cin, vigenereKey);

            for (int i = 0, j = 0; i < ciphertext.size(); ++i, ++j) {
                if (j == vigenereKey.size()) {
                    j = 0;
                }

                vigenereKeyDummy.push_back(vigenereKey.at(j));
            }

            for (int h = 0; h < ciphertext.size(); ++h) {
                ciphertext.at(h) = ciphertext.at(h) + vigenereKeyDummy.at(h);
            }

            break;
        }
        //Permutation encrypt
        case 3:
        {
            std::string permutationKey;
            std::string permutationKeyDummy;
            std::vector<int> permutationKeyNums;
            bool cond = false;
            int repeat;
            int factor;

            std::cout << "Your plaintext character size is " << ciphertext.size() << std::endl;

            while (cond == false) {
                std::cout << "Enter key for Permutation cipher (must be size n that is a factor of the ciphertext): " << std::endl;
                std::getline(std::cin, permutationKey);

                if (ciphertext.size() % permutationKey.size() == 0) {
                    cond = true;
                }
                else {
                    std::cout << "Error, you must choose a key that is a factor of the ciphertext!" << std::endl;
                }
            }

            factor = permutationKey.size();

            if (ciphertext.size() > permutationKey.size()) {
                repeat = ciphertext.size() / permutationKey.size();
            }

            permutationKeyDummy = permutationKey;

            for (int h = 0; h < repeat - 1; ++h) {
                permutationKey.insert(permutationKey.end(), permutationKeyDummy.begin(), permutationKeyDummy.end());
            }

            for (int i = 0; i < permutationKey.size(); ++i) {
                permutationKeyNums.push_back(permutationKey[i] - 48);
            }

            for (int k = 0; k < repeat; ++k) {
                for (int j = 0; j < ciphertext.size() / repeat; ++j) {
                    ciphertext.at(j + (k*factor)) = plaintext.at(permutationKeyNums.at(j)+(k*factor)-1);
                }
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

//Decryption function, decrypting based on which cipher is currently chosen
std::string decrypt(std::string ciphertext) {
    std::string plaintext = ciphertext;

    switch(cipher) {
        //Default decrypt
        case 0:
        {
            for (char &i : plaintext) {
                i--;
            }

            break;
        }
        //Caesar decrypt
        case 1:
        {
            int caesarKey;

            std::cout << "Enter key for Caesar cipher: ";
            std::cin >> caesarKey;

            for (char &i : plaintext) {
                i = i - caesarKey;
            }

            break;
        }
        //Vigenere decrypt
        case 2:
        {
            std::string vigenereKey;
            std::string vigenereKeyDummy;

            std::cout << "Enter key for Vigenere cipher: ";
            std::getline(std::cin, vigenereKey);

            for (int i = 0, j = 0; i < plaintext.size(); ++i, ++j) {
                if (j == vigenereKey.size()) {
                    j = 0;
                }
                
                vigenereKeyDummy.push_back(vigenereKey.at(j));
            }

            for (int h = 0; h < plaintext.size(); ++h) {
                plaintext.at(h) = plaintext.at(h) - vigenereKeyDummy.at(h);
            }

            break;
        }
        //Permutation decrypt
        case 3:
        {
            std::string permutationKey;
            std::string permutationKeyDummy;
            std::vector<int> permutationKeyNums;
            bool cond = false;
            int repeat;
            int factor;

            std::cout << "Your ciphertext character size is " << plaintext.size() << std::endl;

            while (cond == false) {
                std::cout << "Enter key for Permutation cipher (must be size n that is a factor of the ciphertext): " << std::endl;
                std::getline(std::cin, permutationKey);

                if (plaintext.size() % permutationKey.size() == 0) {
                    cond = true;
                }
                else {
                    std::cout << "Error, you must choose a key that is a factor of the ciphertext!" << std::endl;
                }
            }

            factor = permutationKey.size();

            if (plaintext.size() > permutationKey.size()) {
                repeat = plaintext.size() / permutationKey.size();
            }

            permutationKeyDummy = permutationKey;

            for (int h = 0; h < repeat - 1; ++h) {
                permutationKey.insert(permutationKey.end(), permutationKeyDummy.begin(), permutationKeyDummy.end());
            }

            for (int i = 0; i < permutationKey.size(); ++i) {
                permutationKeyNums.push_back(permutationKey[i] - 48);
            }

            for (int k = 0; k < repeat; ++k) {
                for (int j = 0; j < plaintext.size() / repeat; ++j) {
                    plaintext.at(j + (k*factor)) = ciphertext.at(permutationKeyNums.at(j)+(k*factor)-1);
                }
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

//Choose cipher option, allowing user to pick a cipher and returning if it works or not
int chooseCipher() {
    int whichCipher, userOp;

    if (cipher == 0) {
        std::cout << "You are currently set on default cipher Caesar with key 1, would you like to continue?" << std::endl;
        std::cout << "1 for yes, 0 for no: ";
        std::cin >> userOp;
        
        if (userOp == 0) {
            return(-1);
        }
    }

    std::cout << "0. Default cipher" << std::endl;
    std::cout << "1. Caesar Cipher" << std::endl;
    std::cout << "2. Vigenere Cipher" << std::endl;
    std::cout << "3. Permutation Cipher" << std::endl;
    std::cout << "Enter the cipher you would like to use:" << std::endl;
    std::cout << "--> ";
    std::cin >> whichCipher;

    cipher = whichCipher;

    std::cout << std::endl;

    return(0);
}