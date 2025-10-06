#include <stdio.h>

int main() {
    int n, i, time = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n];

    for(i = 0; i < n; i++){
        pid[i] = i+1;
        printf("P%d arrival & burst time: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    // FCFS scheduling
    for(i = 0; i < n; i++){
        if(time < at[i]) time = at[i];
        ct[i] = time + bt[i];
        time = ct[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    printf("\nGantt Chart:\n|");
    for(i = 0; i < n; i++) printf(" P%d |", pid[i]);

    int totalTAT = 0, totalWT = 0;
    printf("\n\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++){
        totalTAT += tat[i];
        totalWT += wt[i];
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage TAT = %.2f, Average WT = %.2f\n", (float)totalTAT/n, (float)totalWT/n);
    return 0;
}
