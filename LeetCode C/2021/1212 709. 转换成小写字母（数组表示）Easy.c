#include <stdio.h>
#include <ctype.h>  // isupper()º¯Êý
#include <string.h> // strlen()º¯Êý
#define LEN 80
char toLowerCase(char s[LEN]);

char toLowerCase(char s[LEN])
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (isupper(s[i]))
        {
            s[i] += 32;
        }
    }
    return *s;
}

int main(void)
{
    char s[LEN];
    printf("Please enter a string of characters:\n");
    scanf("%s", s);
    toLowerCase(s);
    for (int i = 0; i < strlen(s); i++)
        printf("%c", s[i]);
}
