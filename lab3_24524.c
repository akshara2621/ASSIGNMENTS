#include <stdio.h>
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int at[n], bt[n], tat[n], wt[n], ct[n];
    double atat, awt;
    printf("Enter the arrival times:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }
    printf("Enter the burst times:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }
    ct[0] = at[0] + bt[0];

    for(int i = 1; i < n; i++) {
        if(at[i] > ct[i-1])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i-1] + bt[i];
    }
    for(int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
    int total_tat = 0, total_wt = 0;

    for(int i = 0; i < n; i++) {
        total_tat += tat[i];
        total_wt += wt[i];
    }
    atat = (double) total_tat / n;
    awt = (double) total_wt / n;
    printf("\nAverage Turnaround Time: %.2f", atat);
    printf("\nAverage Waiting Time: %.2f\n", awt);

    return 0;
}