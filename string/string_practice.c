#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///////////////////////////////////////////////////////////////////////////////
// Reverse a single word
//
// @param str pointer to a string that contains word to reverse
// @param start start index of the word to reverse
// @end finish finish index of the word to reverse
///////////////////////////////////////////////////////////////////////////////
void reverseWord(char *str, int start, int finish)
{
    // Length of word to be reversed
    unsigned int L = finish - start + 1;
    for (unsigned int i = 0; i < L/2; i++)
    {
        char temp = str[start + i];
        str[start + i] = str[finish - i];
        str[finish - i] = temp;
    }
}

///////////////////////////////////////////////////////////////////////////////
// Reverse words in a string
//
// @param str string contains words to reverse
///////////////////////////////////////////////////////////////////////////////
void reverseWords(char *str)
{
    unsigned int L = 0;
    // Get size of input string
    while(str[L++] != '\0')
    {
    }
    
    // First reverse the string
    reverseWord(str, 0, L - 2);

    // Then reverse words in string
    // Finish index of a word
    unsigned int j = 0;
    for (unsigned int i = 0; i < L - 1; )
    {
        // Skip whitespace
        while(str[i] == ' ')
        {
            i++;
        }
        j = i;

        // Skip non-whitespace
        while(str[j] != ' ' && str[j] != '\0')
        {
            j++;
        }
        j -= 1;
        // Reverse each word in string
        reverseWord(str, i, j);
        i = j + 1;
    }
}


///////////////////////////////////////////////////////////////////////////////
// Run length encode
//
// @param str string to be encoded
// 
// @return encoded string, e.x, "aaaabbbccccdde" --> "4a3b4c2d1e"
///////////////////////////////////////////////////////////////////////////////
char *runLengthEncode(char* str)
{
    
}

int main()
{
    printf("Play with string\n");
    char str[] = "   Hello nam trang    ";
    printf("Before: %s\n", str);
    reverseWords(str);
    printf("After: %s\n", str);

    return 0;
}
