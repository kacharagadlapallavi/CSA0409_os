#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0;
    int bt[20], rt[20], p[20], wt[20], tat[20];
    int min, index;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter burst time for P%d: ", i+1);
        scanf("%d", &bt[i]);

        printf("Enter priority for P%d: ", i+1);
        scanf("%d", &p[i]);

        rt[i] = bt[i];
    }

    while(completed != n) {
        min = 9999;
        index = -1;

        for(i = 0; i < n; i++) {
            if(rt[i] > 0 && p[i] < min) {
                min = p[i];
                index = i;
            }
        }

        rt[index]--;
        time++;

        if(rt[index] == 0) {
            completed++;
            wt[index] = time - bt[index];
        }
    }

    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    float avg_wt = 0, avg_tat = 0;

    printf("\nProcess\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\n", i+1, wt[i], tat[i]);
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nAverage WT = %.2f", avg_wt/n);
    printf("\nAverage TAT = %.2f", avg_tat/n);

    return 0;
}