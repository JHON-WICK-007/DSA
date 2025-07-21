#include <stdio.h>

int main()
{
    char ch;
    int maxLen = 0, currLen = 0;

    while (scanf("%c", &ch) != EOF && ch != '\n')
    {
        if (ch != ' ')
        {
            currLen++;
        }
        else
        {
            if (currLen > maxLen)
            {
                maxLen = currLen;
            }
            currLen = 0;
        }
    }

    if (currLen > maxLen)
    {
        maxLen = currLen;
    }

    printf("%d", maxLen);
    return 0;
}