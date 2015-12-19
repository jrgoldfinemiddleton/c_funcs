/* Contains utility functions */

#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>

void clrstrm(FILE *stream);

int getrangedint(int min, int max);

int getvalint(const char prompt[]);

_Bool prsi(const char *instr, int *outi);

_Bool prsl(const char *instr, long *outl);

_Bool prsll(const char *instr, long long *outll);

_Bool prsul(const char *instr, unsigned long *outul);

_Bool prsull(const char *instr, unsigned long long *outull);

void readln(FILE *stream, char line[], int sz);

#endif /* UTIL_H */
