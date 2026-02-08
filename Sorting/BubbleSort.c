#include<stdio.h>

void bubblesort(int arr[], int n)
{
    int i, j, temp;
    int swapped;
    for(i = 0; i < n - 1; i++)
    {
        swapped = 0;
        for(j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if(!swapped) break;
    }
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("\t%d", arr[i]);
    }
}

int main()
{
    int i, n;

    printf("***********************************************************\n");
    printf("                        BUBBLE SORT                        \n");
    printf("***********************************************************\n");

    printf("\n\tEnter no. of Elements : ");
    scanf("%d", &n);
    printf("\n");

    int arr[n];

    for(i = 0; i < n; i++)
    {
        printf("\tEnter Element at Index [%d] : ", i);
        scanf("%d", &arr[i]);
    }

    printf("\n\n\t..........ELEMENTS BEFORE SORTING..........\n\n");
    printArray(arr, n);

    printf("\n\n\t..........ELEMENTS AFTER SORTING..........\n\n");
    bubblesort(arr, n);
    printArray(arr, n);

    return 0;
}
