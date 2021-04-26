#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "choose.h"
#include "write.h"

int chooseCipher () {
    int num;

    fprintf(stdout, "Enter the cipher you would like to use:\n");
    fprintf(stdout, "1. Ceaser Cipher\n");
    fprintf(stdout, "2. Vigenere Cipher\n");
    fprintf(stdout, "3. chep6 Cipher\n");

    fscanf(stdin, "%d", &num);

    return(num);
}
