#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n], temp[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    scanf("%d", &k);

    k = k % n;   // Handle k > n

    // Rotate
    for(int i = 0; i < n; i++) {
        temp[(i + k) % n] = arr[i];
    }

    // Print rotated array
    for(int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }

    return 0;
}
