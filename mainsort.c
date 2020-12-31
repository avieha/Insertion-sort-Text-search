#include <stdio.h>
#include "headersort.h"
#define SIZE 50

int main()
{
    int arr[SIZE];
    int j = 0;
    while (j < SIZE)
    {
        scanf(" %d", arr + j++);
    }
    insertion_sort(arr, SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        if (i == SIZE - 1)
            printf("%d\n", arr[i]);
        else
            printf("%d,", arr[i]);
    }
    return 0;
}
