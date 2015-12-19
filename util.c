#include "util.h"


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
