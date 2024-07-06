#include <stdio.h>

int pageIsFound(int f[], int count, int a) {
    for (int i = 0; i < count; i++) {
        if (f[i] == a)
            return 1;
    }
    return 0;
}

int totalAccessed(int arr[], int n, int i, int a) {
    int count = 0;
    for (int j = i; j >= 0; j--) {
        if (arr[j] == a)
            count++;
    }
    return count;
}

void lfu(int arr[], int n, int f[], int fno) {
    int index, count = 0, page_faults = 0, page_hits = 0, lfuArr[fno][n];

    for (int i = 0; i < n; i++) {
        if (pageIsFound(f, count, arr[i])) {
            // Page hit: Increment page hits and continue
            page_hits++;
        } else {
            // Page fault: Increment page faults and replace if necessary
            page_faults++;

            if (count < fno) {
                f[count++] = arr[i];
            } else {
                int min_access = totalAccessed(arr, n, i, f[0]);
                index = 0;
                for (int j = 1; j < fno; j++) {
                    int current_access = totalAccessed(arr, n, i, f[j]);
                    if (current_access < min_access) {
                        min_access = current_access;
                        index = j;
                    }
                }
                f[index] = arr[i];
            }
        }

        // Update LFU array for printing purposes
        for (int j = 0, k = 0; j < fno; j++) {
            if (k < count)
                lfuArr[j][i] = f[k++];
            else
                lfuArr[j][i] = -1;
        }
    }

    // Print LFU array
    printf("\nLFU Page Replacement Algorithm\n\n");
    printf("Page Frames:\n");
    for (int i = 0; i < fno; i++) {
        for (int j = 0; j < n; j++) {
            if (lfuArr[i][j] != -1)
                printf("%d  ", lfuArr[i][j]);
            else
                printf("   ");
        }
        printf("\n");
    }

    // Print page faults, page hits, and ratios
    printf("\nPage Faults: %d\n", page_faults);
    printf("Page Hits: %d\n", page_hits);

    float hit_ratio = (float)page_hits / n;
    float fault_ratio = (float)page_faults / n;

    printf("Hit Ratio: %.2f\n", hit_ratio);
    printf("Page Fault Ratio: %.2f\n", fault_ratio);
}

int main() {
    int n, frameNum;
    printf("LFU Page Replacement Algorithm\n");
    printf("Enter the number of frames: ");
    scanf("%d", &frameNum);
    printf("Enter the number of page requests: ");
    scanf("%d", &n);
    printf("Enter the page string each separated by a space:\n");
    int arr[n], F[frameNum];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\nPages:\n");
    for (int i = 0; i < n; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n\n");
    lfu(arr, n, F, frameNum);
    return 0;
}

