#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int A[100][6];
    int done[100] = {0};
    int i;

    printf("Enter Arrival Times (space-separated):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i][1]);
        A[i][0] = i + 1;
    }

    printf("Enter Burst Times (space-separated):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i][2]);
    }

    int completed = 0;
    int current_time = 0;
    int total_wt = 0, total_tat = 0;

    int gantt_order[100];
    int gantt_start[100];
    int gantt_finish[100];
    int gcount = 0;

    while (completed < n) {
        int shortest = -1;

        for (i = 0; i < n; i++) {
            if (!done[i] && A[i][1] <= current_time) {
                if (shortest == -1 || A[i][2] < A[shortest][2])
                    shortest = i;
            }
        }

        if (shortest == -1) {
            int next_arrival = -1;
            for (i = 0; i < n; i++) {
                if (!done[i] && (next_arrival == -1 || A[i][1] < A[next_arrival][1]))
                    next_arrival = i;
            }
            current_time = A[next_arrival][1];
            continue;
        }

        gantt_order[gcount]  = A[shortest][0];
        gantt_start[gcount]  = current_time;

        current_time += A[shortest][2];

        gantt_finish[gcount] = current_time;
        gcount++;

        A[shortest][3] = current_time;
        A[shortest][4] = A[shortest][3] - A[shortest][1];
        A[shortest][5] = A[shortest][4] - A[shortest][2];

        total_tat += A[shortest][4];
        total_wt  += A[shortest][5];

        done[shortest] = 1;
        completed++;
    }

    float avg_tat = (float) total_tat / n;
    float avg_wt  = (float) total_wt  / n;

    printf("\nGantt Chart:\n");
    for (i = 0; i < gcount; i++) {
        printf("|  P%d  ", gantt_order[i]);
    }
    printf("|\n");

    printf("%d", gantt_start[0]);
    for (i = 0; i < gcount; i++) {
        printf("     %d", gantt_finish[i]);
    }
    printf("\n\n");

    printf("Job   AT   BT   FT   TAT   WT\n");
    for (i = 0; i < n; i++) {
        printf("P%-4d %-4d %-4d %-4d %-5d %-4d\n",
               A[i][0], A[i][1], A[i][2], A[i][3], A[i][4], A[i][5]);
    }

    printf("\nAverage Waiting Time   = %.2f\n", avg_wt);
    printf("Average Turnaround Time= %.2f\n", avg_tat);

    return 0;
}
