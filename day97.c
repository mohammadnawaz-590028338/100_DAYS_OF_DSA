#include <stdio.h>
#include <stdlib.h>

// Structure for meeting
struct Meeting {
    int start, end;
};

// Compare function for sorting by start time
int compare(const void *a, const void *b) {
    struct Meeting *m1 = (struct Meeting *)a;
    struct Meeting *m2 = (struct Meeting *)b;
    return m1->start - m2->start;
}

// Min heap functions
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int heap[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;

    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}

void insertHeap(int heap[], int *size, int val) {
    int i = (*size)++;
    heap[i] = val;

    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void replaceMin(int heap[], int val) {
    heap[0] = val;
    heapify(heap, 1, 0);
}

int main() {
    int n;
    scanf("%d", &n);

    struct Meeting arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    // Step 1: Sort by start time
    qsort(arr, n, sizeof(struct Meeting), compare);

    int heap[n];
    int size = 0;

    // Add first meeting
    insertHeap(heap, &size, arr[0].end);

    // Process remaining meetings
    for (int i = 1; i < n; i++) {
        if (heap[0] <= arr[i].start) {
            // reuse room
            heap[0] = arr[i].end;
            heapify(heap, size, 0);
        } else {
            // need new room
            insertHeap(heap, &size, arr[i].end);
        }
    }

    printf("%d\n", size);

    return 0;
}
