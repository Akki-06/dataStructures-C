#include <stdio.h>

void bucketSort(int a[],int n){
    int bucket[10][n], buckcount[10];
    int i,j,k,r,digitcount=0,divisor=1,largest,passNo;

    largest = a[0];

    for(i=1; i<n; i++){
        if(a[i]>largest)
            largest = a[i];
    }

    while(largest>0){
        digitcount++;
        largest /= 10;
    }

    for(passNo=0; passNo<digitcount; passNo++){
        for(k=0; k<10; k++)
            buckcount[k] = 0;

        for(i=0; i<n; i++){
            r = (a[i]/divisor)%10;
            bucket[r][buckcount[r]++] = a[i];
        }

        i=0;
        for(k=0; k<10; k++){
            for(j=0; j<buckcount[k]; j++)
                a[i++] = bucket[k][j];
        }
        divisor *= 10;
    }

}

void printArray(int arr[], int n) {
    for (int i=0; i<n; i++) {
        printf("\t%d",arr[i]);
    }
    printf("\n");
}

int main(){
    int n;

    printf("***********************************************************\n");
    printf("\t\t\tBUCKET SORT\n");
    printf("***********************************************************\n");
    printf("\n\tEnter number of Elements: ");
    scanf("%d", &n);
    printf("\n");

    int arr[n];

    for(int i=0; i<n; i++){
        printf("\tEnter Element at Index [%d]: ",i);
        scanf("%d",&arr[i]);
    }

    printf("\n\n\t..........ELEMENTS BEFORE SORTING..........\n\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("\n\n\t..........ELEMENTS AFTER SORTING..........\n\n");
    printArray(arr, n);

    return 0;
}
