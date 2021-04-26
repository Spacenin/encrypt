#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "read.h"
#include "write.h"

int readFile (void) {
    char fileName[15];
    char cipherText[100];

    fprintf(stdout, "Enter the file name you would like to read to (up to 15 chars): \n");
    fscanf(stdin, "%s", fileName);

    FILE *fp = fopen(fileName, "r");

    if (fp == NULL) {
        fclose(fp);
        return(-1);
    }

    fprintf(stdout, "Now decrypting text from your file...\n");
    fscanf(fp, "%s", cipherText);

    for (int i = 0; i < strlen(cipherText); ++i) {
        if (isalpha(cipherText[i])) {
            //fprintf(stdout, "Before: %c\n", cipherText[i]);
            cipherText[i] = cipherText[i] - 65;
            cipherText[i] = cipherText[i] - i;
            if (cipherText[i] < 0) {
                cipherText[i] = cipherText[i] + 26;
            }
            else {
                cipherText[i] = cipherText[i] % 26;
            }
            cipherText[i] = cipherText[i] + 65;
            //fprintf(stdout, "After: %c\n", cipherText[i]);
        }
    }

    for (int j = 0; j < strlen(cipherText); ++j) {
        if (checkText[j].isCapital == false) {
            cipherText[j] = tolower(cipherText[j]);
        }
    }

    fprintf(stdout, "Your encrypted text is \n%s\nShhh it's a secret!\n", cipherText);

    fclose(fp);

    return(0);
}