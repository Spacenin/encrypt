#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "write.h"
#include "read.h"

int main (void) {
    int userOp;
    bool cont = true;

    while (cont) {
        int write = -1;
        int read = -1;

        fprintf(stdout, "Welcome to The Encryptor!\n");
        fprintf(stdout, "1. Write file for encryption\n");
        fprintf(stdout, "2. Read file for decryption\n");
        fprintf(stdout, "3. (NOT IMPLETMENTED) Set what cipher you would like to use\n");
        fprintf(stdout, "4. End program\n--> ");

        fscanf(stdin, "%d", &userOp);

        switch(userOp) {
            case 1:
                write = writeFile();

                if (write == -1) {
                    fprintf(stderr, "Error, writing failed\n");
                    break;
                }

                fprintf(stdout, "Done writing! Returning to menu...\n\n");

                break;
            case 2:
                read = readFile();
                
                if (read == -1) {
                    fprintf(stderr, "Error, reading failed\n");
                    break;
                }

                fprintf(stdout, "Done reading! Returning to menu...\n\n");

                break;
            case 3:
                //SET ENCRYPTION
                break;
            case 4:
                cont = false;
                break;
            default:
                fprintf(stdout, "Error, user input is not one of the options\n");
        }
    }

    fprintf(stdout, "Thank you for using The Encryptor!\n");

    return(0);
}