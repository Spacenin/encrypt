#include <iostream>
#include <fstream>
#include "write.h"
#include "read.h"
#include "cipher.h"

//Main driver function
int main() {
    int userOp;
    bool cont = true;

    //While loop that prints out menu, getting user input and following the user defined function
    while (cont) {
        std::cout << "Welcome to the encryptor!" << std::endl;
        std::cout << "1. Write file for encryption" << std::endl;
        std::cout << "2. Read File for decryption" << std::endl;
        std::cout << "3. Set what cipher you would like to use" << std::endl;
        std::cout << "4. End the program" << std::endl;
        std::cout << "--> ";

        std::cin >> userOp;
        std::cout << std::endl;

        //Switch statement for each option
        switch(userOp) {
            //Write to file option, creates new file and encrypts text given with key given
            case 1:
                {
                    int checkWrite = writeFile();

                    //Error check if write fails
                    if (checkWrite != 0) {
                        std::cerr << "Error, writing to file did not work!" << std::endl;

                        break;
                    }

                    else {
                        std::cout << "Message encrypted successfully!" << std::endl << std::endl;                        
                    }

                    break;
                }
                //Read from file option, takes in file and decrypts it based on key given
            case 2:
                {
                    int checkRead = readFile();

                    //Error if read fails
                    if (checkRead != 0) {
                        std::cerr << "Error, reading from file did not work!" << std::endl;

                        break;
                    }

                    break;
                }
                //Choose cipher option, allows user to pick which cipher to use when encrypting
            case 3:
                {
                    int chooseCheck = chooseCipher();

                    //Error if choose fails
                    if (chooseCheck != 0) {
                        std::cerr << "Error, choosing cipher did not work!" << std::endl;

                        break;
                    }

                    break;
                }
                //Quit program option
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