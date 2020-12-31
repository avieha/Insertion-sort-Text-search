#include <stdio.h>
#include <string.h>
#include "headertxt.h"
#define LINE 256
#define WORD 30

void printword(char *s)
{
    char string[WORD] = {0};
    int x = -1;
    while (x)
    {
        x = getword(string);
        int y = similar(string, s, 1);
        if (y == 1)
        {
            printf("%s\n", string);
        }
    }
    return;
}

void printlines(char *s)
{
    char string[LINE] = {0};
    int x = -1;
    while (x)
    {
        x = mygetline(string);
        int y = substring(s, string);
        if (y == 1)
        {
            printf("%s\n", string);
        }
    }
    return;
}

int getword(char s[])
{
    char c = ' ';
    int j = 0;
    for (size_t i = 0; i < WORD; i++)
    {
        s[i] = 0;
    }
    while (1)
    {
        c = getchar();
        if (c == '\n' || c == EOF || c == ' ' || c == '\t' || c == '\r')
        {
            break;
        }
        s[j] = c;
        j++;
    }
    if (c == EOF)
        return 0;
    int counter = strlen(s);
    if (counter == 0 && c != '\0')
    {
        return -1;
    }
    return counter;
}

int mygetline(char s[])
{
    if (fgets(s, LINE, stdin) == NULL)
    {
        for (size_t j = 0; j < strlen(s); j++)
        {
            s[j] = ' ';
        }
        return 0;
    }
    int counter = 0;
    counter = strlen(s);
    s[counter - 1] = '\0';
    return counter;
}

int similar(char *a, char *b, int n)
{
    int a_len = strlen(a);
    int b_len = strlen(b);
    int bool = 0;
    if (a_len == b_len)
    {
        bool = strcmp(a, b);
        {
            return !bool;
        }
    }
    if (a_len - n > b_len || a_len < b_len)
    {
        return bool;
    }
    int index_a = 0;
    int flag = 0;
    char c = ' ';
    int j = 0;
    for (int i = 0; i < b_len; i++)
    {
        c = b[i];
        flag = 0;
        j = 0;
        while (j++ <= n && index_a < a_len)
        {
            if (a[index_a++] == c)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            return bool;
        }
    }
    return !bool;
}

int substring(char *a, char *b)
{
    int bool = 0;
    int a_len = strlen(a);
    int b_len = strlen(b);
    if (a_len > b_len)
        return 0;
    if (a_len == b_len)
        return !strcmp(a, b);
    int i = 0;
    int counter = 0;
    int index = 0;
    while (i < (b_len - a_len + 1))
    {
        if (a[counter] == b[i])
        {
            index = i + 1;
            counter++;
            while (counter < a_len)
            {
                if (a[counter] != b[index])
                    break;
                index++;
                counter++;
            }
        }
        if (counter == a_len)
            return 1;
        counter = 0;
        i++;
    }
    return bool;
}
