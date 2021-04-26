#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "write.h"

int writeFile (void) {
    char fileName[15];
    char plainText[100];

    fprintf(stdout, "Enter the file name you would like to write to (up to 15 chars): \n");
    fscanf(stdin, "%s", fileName);

    FILE *fp = fopen(fileName, "w");

    if (fp == NULL) {
        fclose(fp);
        return(-1);
    }

    fprintf(stdout, "Enter in the text you would like to encrypt (up to 100 chars) with caps at the beginning of every new word and no spaces: \n");
    fscanf(stdin, "%s", plainText);

    for (int j = 0; j < strlen(plainText); ++j) {
        checkText[j].letter = plainText[j];

        if (isupper(checkText[j].letter) == 0) {
            checkText[j].isCapital = false;
        }
        else {
            checkText[j].isCapital = true;
        }

        plainText[j] = toupper(plainText[j]);
        //fprintf(stdout, "%c", plainText[j]);
    }

    for (int i = 0; i < strlen(plainText); ++i) {
        if (isalpha(plainText[i])) {
            //fprintf(stdout, "Before: %c\n", plainText[i]);
            plainText[i] = plainText[i] - 65;
            plainText[i] = plainText[i] + i;
            if (plainText[i] < 0) {
                plainText[i] = plainText[i] + 26;
            }
            else {
                plainText[i] = plainText[i] % 26;
            }
            plainText[i] = plainText[i] + 65;
            //fprintf(stdout, "After: %c\n", plainText[i]);
        }
    }

    fprintf(fp, "%s", plainText);

    fclose(fp);

    return(0);   
}