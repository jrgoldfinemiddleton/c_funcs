#include "util.h"

#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>


/* Removes the next line of input or all characters left on the stream,
 * whichever comes first. */
void clrstrm(FILE *stream)
{
    int cur;
    while ((cur = getc(stream)) != EOF && cur != '\n');
}


/* Prompts the user repeatedly for an integer within a range, and
 * returns a valid integer. */
int getrangedint(int min, int max)
{
    int i;
    char buf[BUFSIZ];

    // set up prompt
    snprintf(buf, sizeof buf, "Enter an integer between %i and %i:", min, max);

    // repeatedly ask for a valid int in range
    do
        i = getvalint(buf);
    while (i < min || i > max);

    return i;
}


/* Prompts the user repeatedly for an integer and once it parses one from
 * the user's input, returns the integer.  */
int getvalint(const char prompt[])
{
    int input;

    puts(prompt);

    // loop until an int is successfully parsed
    while (scanf("%d", &input) != 1)
    {
        // clear leftover characters
        clrstrm(stdin); 

        printf("Invalid value.  ");
        puts(prompt);
    }

    // clear leftover characters
    clrstrm(stdin); 

    return input;
}


_Bool prsi(const char *instr, int *outi)
{
    errno = 0;
    char *end;
    long temp;
    _Bool valid = true;
    const int base = 0;     // let strtol auto-determine base

    temp = strtol(instr, &end, base);

    if (end == instr || end[0] != '\0' ||
            (temp < INT_MIN  || temp > INT_MAX || errno == ERANGE))
        valid = false;
    else
        *outi = (int) temp;

    return valid;
}



_Bool prsl(const char *instr, long *outl)
{
    errno = 0;
    char *end;
    _Bool valid = true;
    const int base = 0;     // let strtol auto-determine base

    *outl = strtol(instr, &end, base);

    if (end == instr || end[0] != '\0' ||
            ((*outl == LONG_MIN || *outl == LONG_MAX) && errno == ERANGE))
        valid = false;

    return valid;
}


_Bool prsll(const char *instr, long long *outll)
{
    errno = 0;
    char *end;
    _Bool valid = true;
    const int base = 0;     // let strtoll auto-determine base

    *outll = strtoll(instr, &end, base);

    if (end == instr || end[0] != '\0' ||
            ((*outll == LLONG_MIN || *outll == LLONG_MAX) && errno == ERANGE))
        valid = false;

    return valid;
}


_Bool prsul(const char *instr, unsigned long *outul)
{
    errno = 0;
    char *end;
    _Bool valid = true;
    const int base = 0;     // let strtoul auto-determine base

    *outul = strtoul(instr, &end, base);

    if (end == instr || end[0] != '\0' || (*outul == ULONG_MAX && errno == ERANGE))
        valid = false;

    return valid;
}


_Bool prsull(const char *instr, unsigned long long *outull)
{
    errno = 0;
    char *end;
    _Bool valid = true;
    const int base = 0;     // let strtoull auto-determine base

    *outull = strtoull(instr, &end, base);

    if (end == instr || end[0] != '\0' || (*outull == ULLONG_MAX && errno == ERANGE))
        valid = false;

    return valid;
}


/* Reads up to "sz" characters from a stream into the string "line". */
void readln(FILE *stream, char line[], const int sz)
{
    int ch = '\0';
    int index = 0;

    // copy chars from the stream
    while (index < sz && ch != EOF && ch != '\n')
    {
        ch = getchar();
        line[index++] = (char) ch;
    }

    // clear remaining characters
    if (index == sz)
        clrstrm(stream);

    // terminate string with null character
    line[index - 1] = '\0';
}
