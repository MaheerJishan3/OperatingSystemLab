#include <stdio.h>
#include <string.h>

#define MAX 20

int main() {
    int n, i, j;
    int arrival[MAX], burst[MAX], wt[MAX], tat[MAX], ct[MAX];
    char pname[MAX];
    int total_wt = 0, total_tat = 0;
    int temp;
    char ctemp;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival times (space separated): ");
    for(i = 0; i < n; i++)
        scanf("%d", &arrival[i]);

    printf("Enter burst times (space separated): ");
    for(i = 0; i < n; i++)
        scanf("%d", &burst[i]);
    
    for(i = 0; i < n; i++)
        pname[i] = 'A' + i;

    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(arrival[i] > arrival[j]) {
               
                temp = arrival[i]; arrival[i] = arrival[j]; arrival[j] = temp;
                
                temp = burst[i]; burst[i] = burst[j]; burst[j] = temp;
                
                ctemp = pname[i]; pname[i] = pname[j]; pname[j] = ctemp;
            }
        }
    }

    int current_time = 0;
    for(i = 0; i < n; i++) {
        if(current_time < arrival[i])
            current_time = arrival[i];
        wt[i] = current_time - arrival[i];
        ct[i] = current_time + burst[i];
        tat[i] = ct[i] - arrival[i];
        current_time = ct[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nGantt Chart:\n ");
    current_time = 0;
    int start_time;

    for(i = 0; i < n; i++) {
       
        if(current_time < arrival[i]) {
            printf("-------");
            current_time = arrival[i];
        }
        printf("-------");
        current_time += burst[i];
    }
    printf("\n|");

    current_time = 0;
    for(i = 0; i < n; i++) {
       
        if(current_time < arrival[i]) {
            printf(" Idle |");
            current_time = arrival[i];
        }
        printf("  %c   |", pname[i]);
        current_time += burst[i];
    }
    printf("\n ");

    current_time = 0;
    for(i = 0; i < n; i++) {

        if(current_time < arrival[i]) {
            printf("%-7d", current_time);
            current_time = arrival[i];
        }
        printf("%-7d", current_time);
        current_time += burst[i];
    }
    printf("%d\n", current_time);

    
    printf("\n%-10s %-10s %-10s %-13s %-17s %-15s\n", "Process", "Arrival", "Burst", "Waiting Time", "Turnaround Time", "Completion");
    for(i = 0; i < n; i++) {
        printf("%-10c %-10d %-10d %-13d %-17d %-15d\n", pname[i], arrival[i], burst[i], wt[i], tat[i], ct[i]);
    }

    
    printf("%-10s %-10s %-10s %-13.2f %-17.2f %-15s\n", "AVG", "-", "-", (float)total_wt/n, (float)total_tat/n, "-");

    return 0;
}