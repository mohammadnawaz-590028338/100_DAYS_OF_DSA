#include <stdio.h>

// Insertion sort for each bucket
void insertionSort(float bucket[], int size) {
    for (int i = 1; i < size; i++) {
        float key = bucket[i];
        int j = i - 1;

        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

void bucketSort(float arr[], int n) {
    // Create buckets
    float buckets[n][n];
    int count[n];

    // Initialize counts
    for (int i = 0; i < n; i++)
        count[i] = 0;

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];
        buckets[index][count[index]++] = arr[i];
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i], count[i]);
    }

    // Concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[k++] = buckets[i][j];
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}
