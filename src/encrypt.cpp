#include <iostream>
#include <fstream>
#include "write.h"
#include "read.h"
#include "cipher.h"

int main() {
    int userOp;
    bool cont = true;

    while (cont) {
        std::cout << "Welcome to the encryptor!" << std::endl;
        std::cout << "1. Write file for encryption" << std::endl;
        std::cout << "2. Read File for decryption" << std::endl;
        std::cout << "3. Set what cipher you would like to use" << std::endl;
        std::cout << "4. End the program" << std::endl;
        std::cout << "--> ";

        std::cin >> userOp;
        std::cout << std::endl;

        switch(userOp) {
            case 1:
                {
                    int checkWrite = writeFile();

                    if (checkWrite != 0) {
                        std::cerr << "Error, writing to file did not work!" << std::endl;

                        break;
                    }

                    else {
                        std::cout << "Message encrypted successfully!" << std::endl << std::endl;                        
                    }

                    break;
                }
            case 2:
                {
                    int checkRead = readFile();

                    if (checkRead != 0) {
                        std::cerr << "Error, reading from file did not work!" << std::endl;

                        break;
                    }

                    break;
                }
            case 3:
                {
                    int chooseCheck = chooseCipher();

                    if (chooseCheck != 0) {
                        std::cerr << "Error, choosing cipher did not work!" << std::endl;

                        break;
                    }

                    break;
                }
            case 4:
                {
                    std::cout << "Thank for using the encryptor!" << std::endl;

                    return(0);
                }
            default: 
                {
                    break;
                }
        }
    }
}