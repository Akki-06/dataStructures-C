#include <stdio.h>

void merge(int a[], int lbeg, int lend, int rbeg, int rend) {

    int temp[50];
    int i, j, k;
    i = lbeg;
    j = rbeg;
    k = 0;

    while(i<=lend && j<=rend){
        if(a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while(i <= lend)
        temp[k++] = a[i++];
    while(j <= rend)
        temp[k++] = a[j++];

    for(i=lbeg,j=0; i<=rend; i++,j++)
        a[i] = temp[j];

}
void mergeSort(int arr[], int beg, int end){
    if(beg < end){
        int mid = beg+(end - beg)/2;

        mergeSort(arr, beg, mid);
        mergeSort(arr, mid + 1, end);


        merge(arr, beg, mid, mid+1, end);
    }
}

void printArray(int arr[], int size) {
    for (int i=0; i<size; i++) {
        printf("\t%d",arr[i]);
    }
    printf("\n");
}

int main(){
    int n;

    printf("***********************************************************\n");
    printf("\t\t\tMERGE SORT\n");
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

    mergeSort(arr, 0, n-1);

    printf("\n\n\t..........ELEMENTS AFTER SORTING..........\n\n");
    printArray(arr, n);

    return 0;
}
