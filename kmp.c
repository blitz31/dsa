#include<stdio.h>
#include<string.h>

void fillLPS(char string[20], int lps[20])
{
    int i = 1;
    int n = strlen(string);
    int len = 0;
    lps[0] = 0;
    while(i < n)
    {
        if(string[i] == string[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }  
}

void kmp(char pattern[20], char text[40])
{
    int i = 0, j = 0;
    int m = strlen(pattern);
    int n = strlen(text);
    int lps[20];
    fillLPS(pattern, lps);
    while(i < n)
    {
        if(pattern[j] == text[i]) {i++; j++;}
        if(j == m)
        {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        }
        else if(i < n && pattern[j] != text[i])
        {
            if(j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main()
{
    char text[40], pattern[20];
    printf("Enter the text: ");
    scanf("%s", text);
    printf("Enter the pattern: ");
    scanf("%s", pattern);
    kmp(pattern, text);
    return 0;
}
