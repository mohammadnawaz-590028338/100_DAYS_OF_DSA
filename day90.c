#include <stdio.h>

// Check if painting is possible within maxTime
int isPossible(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int currSum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxTime)
            return 0;

        if (currSum + arr[i] > maxTime) {
            painters++;
            currSum = arr[i];

            if (painters > k)
                return 0;
        } else {
            currSum += arr[i];
        }
    }
    return 1;
}

// Find minimum time
int minTime(int arr[], int n, int k) {
    int sum = 0, max = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    int low = max, high = sum;
    int result = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, k, mid)) {
            result = mid;
            high = mid - 1; // try smaller time
        } else {
            low = mid + 1;  // increase time
        }
    }

    return result;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = minTime(arr, n, k);
    printf("%d\n", result);

    return 0;
}
