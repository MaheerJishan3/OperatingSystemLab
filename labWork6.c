#include <stdio.h>

int main() {
    int n, m;

    // Read counts
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource types: ");
    scanf("%d", &m);

    // Declare matrices/vectors (C99 VLAs)
    int max[n][m];
    int alloc[n][m];
    int need[n][m];
    int avail[m];

    // Input Available
    printf("Enter the Available vector (%d integers): ", m);
    for (int j = 0; j < m; j++) {
        scanf("%d", &avail[j]);
    }

    // Input Max matrix
    printf("Enter the Max matrix (%d x %d):\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Input Allocation matrix
    printf("Enter the Allocation matrix (%d x %d):\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    // Compute Need = Max - Allocation
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Safety algorithm
    int finish[n];
    int safeSeq[n];
    int work[m];

    for (int j = 0; j < m; j++) work[j] = avail[j];
    for (int i = 0; i < n; i++) finish[i] = 0;

    int count = 0;
    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int canRun = 1;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        canRun = 0;
                        break;
                    }
                }
                if (canRun) {
                    for (int j = 0; j < m; j++) work[j] += alloc[i][j];
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) break; // No allocatable process found in this pass
    }

    if (count == n) {
        printf("System is in a SAFE state.\nSafe sequence: ");
        for (int i = 0; i < n; i++) {
            printf("P%d", safeSeq[i]);
            if (i != n - 1) printf(" -> ");
        }
        printf("\n");
    } else {
        printf("System is NOT in a safe state.\n");
    }

    return 0;
}