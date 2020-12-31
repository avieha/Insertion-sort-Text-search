#include <stdio.h>
#include "headersort.h"
#define SIZE 50

int insertion_sort(int *arr, int len)
{
    int counter = 0;
    int counter2 = 0;
    int index = 0;
    int temp = 0;
    for (int i = 0; i < len; i++)
    {
        counter2 = i;
        index = 1;
        while (*arr < *(arr - index++) && (counter2-- > 0))
        {
            counter++;
        }
        temp = *arr;
        shift_element((arr - counter), counter);
        *(arr - counter) = temp;
        counter = 0;
        arr++;
    }
    return 0;
}

void shift_element(int *arr, int i)
{
    arr = arr + i;
    for (int j = 0; j < i; j++)
    {
        *(arr) = *(arr - 1);
        arr--;
    }
    return;
}
