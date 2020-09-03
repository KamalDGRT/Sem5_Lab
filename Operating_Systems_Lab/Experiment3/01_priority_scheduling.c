#include<stdio.h>

int main() {

    int nop, t, wt[10], twt, tat[10], ttat, i, j, p[10], b[10], tmp;
    float awt, atat;

    awt = 0.0;
    atat = 0.0;

    printf("Enter the no. of process : ");
    scanf("%d", &nop);

    for(i = 0; i < nop; i++) {
        printf("Enter the burst time for process %d : ", i);
        scanf("%d", &b[i]);
    }

    for(i = 0; i < nop; i++) {
        printf("Enter priority number of each process %d : ", i);
        scanf("%d", &p[i]);
    }

    for(i = 0; i < nop; i++) {
        for(j = i + 1; j < nop; j++) {
            if(p[i] > p[j]) {
                t = p[i];
                p[i] = p[j];
                p[j] = t;

                tmp = b[i];
                b[i] = b[j];
                b[j] = tmp;
            }
        }
    }

    wt[0] = 0;
    tat[0] = b[0];
    twt = wt[0];
    ttat = tat[0];
    
    for(i = 1; i < nop; i++) {
        wt[i] = wt[i-1] + b[i-1];
        tat[i] = wt[i] + b[i];
        twt += wt[i];
        ttat += tat[i];
    }

    awt = (float)twt/nop;
    atat = (float)ttat/nop;

    printf("\n Process No:\tPriority\tBurstTime\tWaitingTime\tTurnaroundTime\n");
    for(i = 0; i < nop; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", i, p[i], b[i], wt[i], tat[i]);
    }

    printf("\n Total TurnAround Time : %d\n", ttat);
    printf("\n Total Waiting Time : %d\n", twt);
    printf("\n Average Waiting Time : %f\n", awt);
    printf("\n Average Total Around Time : %f\n", atat);
    return 0;

}