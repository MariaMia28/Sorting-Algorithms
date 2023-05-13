#include <stdio.h>

void countingSort(int arr[], int n, int k) {
    int output[n]; 
    int count[k];
    int i;

    for (i = 0; i < k; i++)
        count[i] = 0;

    for (i = 0; i < n; i++)
        count[arr[i]]++;

    for (i = 1; i < k; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    int k = 9; 

    printf("Original array: ");
    printArray(arr, size);

    countingSort(arr, size, k);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}
