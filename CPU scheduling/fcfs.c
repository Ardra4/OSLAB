#include<stdio.h>

int main() {
    int p[10], at[10], bt[10], ct[10], tat[10], wt[10], i, j, temp = 0, n;
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input process IDs
    for(i = 0; i < n; i++) {
        p[i] = i + 1;
    }

    // Input arrival times
    printf("Enter arrival times for %d processes: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    // Input burst times
    printf("Enter burst times for %d processes: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    // Sorting processes based on arrival time using bubble sort
    for(i = 0; i < n; i++) {
        for(j = 0; j < (n - i - 1); j++) {
            if(at[j] > at[j + 1]) {
                temp = p[j + 1];
                p[j + 1] = p[j];
                p[j] = temp;

                temp = at[j + 1];
                at[j + 1] = at[j];
                at[j] = temp;

                temp = bt[j + 1];
                bt[j + 1] = bt[j];
                bt[j] = temp;
            }
        }
    }

    // Calculating completion times (ct), turnaround times (tat), and waiting times (wt)
    ct[0] = at[0] + bt[0];
    for(i = 1; i < n; i++) {
        temp = 0;
        if(ct[i - 1] < at[i]) {
            temp = at[i] - ct[i - 1];
        }
        ct[i] = ct[i - 1] + bt[i] + temp;
    }

    // Calculating turnaround time (tat) and waiting time (wt)
    printf("\nProcess\t Arrival\t Burst\t Completion\t Turnaround\t Waiting");
    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        atat += tat[i];
        awt += wt[i];
        printf("\n%d\t %d\t\t %d\t %d\t\t %d\t\t %d", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    // Calculating average turnaround time (atat) and average waiting time (awt)
    atat = atat / n;
    awt = awt / n;
    printf("\n\nAverage Turnaround Time: %f", atat);
    printf("\nAverage Waiting Time: %f\n", awt);

    return 0;
}
