#ifndef WRITE_H
#define WRITE_H

int writeFile (void);

typedef struct Letter_struct {
    bool isCapital;
    char letter;
} letter;

letter checkText[100];

#endif