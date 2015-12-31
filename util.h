/* Contains utility functions */

#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>

/* Modify or return value of a bit */
void bitset(unsigned long long &num, const unsigned int pos);
void bitclr(unsigned long long &num, const unsigned int pos);
void bittgl(unsigned long long &num, const unsigned int pos);
unsigned int bitchk(const unsigned long long &num, const unsigned int pos);
void bitmod(unsigned long long &num, const unsigned int pos,
        unsigned int newval);

/* Clears a line from the stream */
void clrstrm(FILE *stream);

/* Prompt for integer types */
int geti();
int getir(int min, int max);
long getl();
long getlr(long min, long max);
long long getll();
long long getllr(long long min, long long max);

/* Parses an integer from a string */
_Bool prsll(const char *instr, long long *outll);

/* Stores a line of chars to a string */
void readln(FILE *stream, char line[], int sz);

#endif /* UTIL_H */
