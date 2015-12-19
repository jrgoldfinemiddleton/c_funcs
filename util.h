/* Contains utility functions */

#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>

void clrstrm(FILE *stream);

int getrangedint(int min, int max);

int getvalint(const char prompt[]);

void readln(FILE *stream, char line[], int sz);

#endif /* UTIL_H */
