#include <stdio.h>

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

int partition(int array[], int low, int high){

  int pivot = array[high];
  int i = low;

  for(int j = low; j < high; j++){
    if (array[j] <= pivot){
      swap(&array[i], &array[j]);
      i++;
    }
  }

  swap(&array[i], &array[high]);
  return i;
}

void quicksort(int array[], int low, int high)
{
  if (low < high)
  {
    int pivot = partition(array, low, high);

    quicksort(array, low, pivot - 1);
    quicksort(array, pivot+ 1, high);
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
    printf("\t\t\tQUICK SORT\n");
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

    quicksort(arr,0,n-1);

    printf("\n\n\t..........ELEMENTS AFTER SORTING..........\n\n");
    printArray(arr, n);

    return 0;
}
