#include "util.h"

#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>


/* Removes the next line of input or all characters left on a stream,
 * whichever comes first. */
void clrstrm(FILE *stream)
{
    int cur;
    while ((cur = getc(stream)) != EOF && cur != '\n');
}


/* Prompts the user until a valid int value is entered and returns it. */
int geti()
{
    return getir(INT_MIN, INT_MAX);
}


/* Prompts the user until a valid int value is entered in the
 * range [min,max] and returns it. */
int getir(int min, int max)
{
    return (int) getllr((long long) min, (long long) max);
}


/* Prompts the user until a valid long value is entered and returns it. */
long getl()
{
    return getlr(LONG_MIN, LONG_MAX);
}


/* Prompts the user until a valid long value is entered in the
 * range [min,max] and returns it. */
long getlr(long min, long max)
{
    return (long) getllr((long long) min, (long long) max);
}


/* Prompts the user until a valid long long value is entered and returns it. */
long long getll()
{
    return getllr(LLONG_MIN, LLONG_MAX);
}


/* Prompts the user until a valid long long value is entered in the
 * range [min,max] and returns it. */
long long getllr(long long min, long long max)
{
    char arr[BUFSIZ];       // copy of input
    char prmt[BUFSIZ];      // prompt
    long long out;          // value to return
    _Bool done = false;     // success flag

    // set up prompt
    snprintf(prmt, sizeof prmt, "Enter an integer between %lli and %lli:",
            min, max);

    // prompt until a valid long long in range [min,max] is entered
    while (!done)
    {
        puts(prmt);
        if (fgets(arr, sizeof arr, stdin) != NULL)
            if (prsll(arr, &out) && (out >= min) && (out <= max))
                done = true;
    }

    return out;
}


/* Attempts to parse a valid long long value from a string.  If the string
 * contains any extra characters other than a trailing '\n' or if the
 * parsed value is out of range, returns false.  Otherwise returns true
 * and outll points to the valid value. */
_Bool prsll(const char *instr, long long *outll)
{
    errno = 0;              // clear global error flag
    char *end;              // either char after last interpreted char in
                            // buffer or equal to instr if error
    _Bool valid = true;     // success flag
    const int base = 0;     // let strtoll auto-determine base

    // attempt to parse a valid value
    *outll = strtoll(instr, &end, base);

    // any of the following conditions indicate failure to parse valid value
    if (end == instr || (*end != '\0' && *end != '\n') ||
            ((*outll == LLONG_MIN || *outll == LLONG_MAX) && errno == ERANGE))
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


/*
// TEST DRIVER

int main(void)
{
    int         i1,     i2;
    long        l1,     l2;
    long long   ll1,    ll2;

    i1 = geti();
    i2 = getir(0, 100);
    l1 = getl();
    l2 = getlr(-734235, 2342523523);
    ll1 = getll();
    ll2 = getllr(-10000000000, 10000000000);

    return 0;
}
*/
