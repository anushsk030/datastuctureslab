#include<stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int limit, i;
    printf("Enter the limit: ");
    scanf("%d", &limit);
    int a[limit];
    
    printf("Enter the numbers to be sorted:\n");
    for (i = 0; i < limit; i++) {
        scanf("%d", &a[i]);
    }

    quickSort(a, 0, limit - 1);

    printf("Sorted array: ");
    for (i = 0; i < limit; i++) {
        printf("%d ", a[i]);
    }

    return 0;
