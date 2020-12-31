#include <stdio.h>
#include <string.h>
#include "headertxt.h"
#define LINE 256
#define WORD 30

int main()
{
    char _option = ' ';
    char _string[WORD] = {0};
    char s[LINE] = {0};
    fgets(s, LINE, stdin);
    int i = 0;
    while (s[i] != ' ')
    {
        _string[i] = s[i];
        i++;
    }
    _option = s[++i];
    fgets(s, LINE, stdin);
    if (_option == 'a')
    {
        printlines(_string);
    }
    else
    {
        printword(_string);
    }
    return 0;
}
