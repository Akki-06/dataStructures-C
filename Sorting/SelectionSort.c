#include<stdio.h>
void selectionsort(int arr[],int n)
{
    int i,j,temp,min_index;
    for(i=0;i<n;i++)
    {
        min_index = i;

        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min_index])
            {
                min_index = j;
            }
        }
        if(min_index!=i)
        {
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("\t%d",arr[i]);
    }
}

int main()
{
    int i,n;

    printf("***********************************************************\n");
    printf("                      SELECTION SORT                       \n");
    printf("***********************************************************\n");

    printf("\n\tEnter no. of elements in Array : ");
    scanf("%d",&n);
    printf("\n");

    int arr[n];

    for(i=0;i<n;i++)
    {
        printf("\tEnter Element at Index [%d] : ",i);
        scanf("%d",&arr[i]);
    }

    printf("\n\n\t..........ELEMENTS BEFORE SORTING..........\n\n");

     for(i=0;i<n;i++)
    {
        printf("\t%d",arr[i]);
    }

    printf("\n\n\t..........ELEMENTS AFTER SORTING..........\n\n");

    selectionsort(arr,n);

    return 0;
}
