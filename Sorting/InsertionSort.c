#include<stdio.h>

void insertionsort(int arr[],int n)
{
    int i,j,key;

    for(i=1;i<n;i++)
    {
        key = arr[i];
        j = i-1;

        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }

    for(i=0;i<n;i++)
    {
        printf("\t%d",arr[i]);
    }
}

int main()
{
    int i, n;

    printf("***********************************************************\n");
    printf("                      INSERTION SORT                       \n");
    printf("***********************************************************\n");

    printf("\n\tEnter no. of Elements : ");
    scanf("%d", &n);
    printf("\n");

    int arr[n];

    for(i=0;i<n;i++)
    {
        printf("\tEnter Element at Index [%d] : ",i);
        scanf("%d", &arr[i]);
    }

    printf("\n\n\t..........ELEMENTS BEFORE SORTING..........\n\n");

    for(i=0;i<n;i++)
    {
        printf("\t%d",arr[i]);
    }

    printf("\n\n\t..........ELEMENTS AFTER SORTING..........\n\n");

    insertionsort(arr,n);

    return 0;
}
