#include <stdio.h>

int binarySearch(int arr[], int n, int target)
{
    int LB, UB, mid;
    LB = 0;
    UB = n - 1;

    while(LB <= UB)
    {
        mid = (LB + UB) / 2;

        if(target > arr[mid])
            LB = mid + 1;
        else if(target < arr[mid])
            UB = mid - 1;
        else
            return mid;
    }
    if(LB > UB){
        return -1;
    }
}

void main()
{
    int i, se, n, index;

    printf("***********************************************************\n");
    printf("                       BINARY SEARCH                       \n");
    printf("***********************************************************\n");

    printf("\n\tEnter no. of elements in Sorted Array : ");
    scanf("%d",&n);
    printf("\n");

    int arr[n];

    for(i = 0;i < n;i++)
    {
        printf("\tEnter element at index %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("\n\tEnter Element to Search : ");
    scanf("%d", &se);

    index = binarySearch(arr, n, se);

    if(index != -1){
        printf("\n\tElement found at Index [%d]!!\n",index);
    }else{
        printf("\n\tElement not found !!\n");
    }
}
