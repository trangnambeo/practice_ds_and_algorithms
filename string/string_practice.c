#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////////////
// Reverse words in a string
//
// @param str string contains words to reverse
///////////////////////////////////////////////////////////////////////////////
void reverseWords(char *str)
{

}

///////////////////////////////////////////////////////////////////////////////
// Reverse a single word
//
// @param str pointer to a string that contains word to reverse
// @param begin pointer to the begin of the word to reverse
// @end end pointer to the end of the word to reverse
///////////////////////////////////////////////////////////////////////////////
void reverseWord(char *str, char *begin, char *end)
{
    // Length of word to be reversed
    unsigned int L = end - begin;
    for (unsigned int i = 0; i < L/2; i++)
    {
        char temp = str[i];
        str[i] = str[end - i - 1];
        str[end - i - 1] = temp;
    }
}

int main()
{
    printf("Play with string\n");

    return 0;
}
