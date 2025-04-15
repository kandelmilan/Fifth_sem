#include <stdio.h>

#define N 8

// Define the customer structure
struct customer {
    int interArrival;
    int arrivalTime;
    int serviceTime;
    int startTime;
    int endTime;
    int waitTime;
    int idleTime;
    int timeSpent;
};

int main() {
    struct customer c[N];
    int totalWait = 0, totalService = 0, totalTimeSpent = 0, totalIdle = 0;
    int simulationTime;

    // Step 1: Input all Inter-Arrival times first
    printf("Enter Inter-Arrival Time for each customer (2nd to %d):\n", N);
    c[0].interArrival = 0;
    printf("Customer 1 Inter-Arrival Time: 0 (first customer)\n");

    for (int i = 1; i < N; i++) {
        printf("Customer %d Inter-Arrival Time (1–8): ", i + 1);
        scanf("%d", &c[i].interArrival);
    }

    // Step 2: Input all Service times next
    printf("\nEnter Service Time for each customer:\n");
    for (int i = 0; i < N; i++) {
        printf("Customer %d Service Time (1–6): ", i + 1);
        scanf("%d", &c[i].serviceTime);
    }

    // Step 3: Compute arrival time
    c[0].arrivalTime = 0;
    for (int i = 1; i < N; i++) {
        c[i].arrivalTime = c[i - 1].arrivalTime + c[i].interArrival;
    }

    // Step 4: Compute start time, end time, wait, idle, time spent
    for (int i = 0; i < N; i++) {
        if (i == 0 || c[i].arrivalTime >= c[i - 1].endTime) {
            c[i].startTime = c[i].arrivalTime;
            c[i].idleTime = (i == 0) ? 0 : c[i].arrivalTime - c[i - 1].endTime;
        } else {
            c[i].startTime = c[i - 1].endTime;
            c[i].idleTime = 0;
        }

        c[i].waitTime = c[i].startTime - c[i].arrivalTime;
        c[i].endTime = c[i].startTime + c[i].serviceTime;
        c[i].timeSpent = c[i].endTime - c[i].arrivalTime;

        totalWait += c[i].waitTime;
        totalService += c[i].serviceTime;
        totalTimeSpent += c[i].timeSpent;
        totalIdle += c[i].idleTime;
    }

    simulationTime = c[N - 1].endTime;

    // Step 5: Print Table
    printf("\nCust\tIAT\tAT\tST\tStart\tEnd\tWait\tTimeSpent\tIdle\n");
    for (int i = 0; i < N; i++) {
        printf("%2d\t%3d\t%3d\t%3d\t%5d\t%4d\t%4d\t%9d\t%4d\n",
               i + 1,
               c[i].interArrival,
               c[i].arrivalTime,
               c[i].serviceTime,
               c[i].startTime,
               c[i].endTime,
               c[i].waitTime,
               c[i].timeSpent,
               c[i].idleTime);
    }

    // Step 6: Print performance metrics
    printf("\n--- Performance Metrics ---\n");
    printf("Average Wait Time         : %.2f minutes\n", (float)totalWait / N);
    printf("Average Service Time      : %.2f minutes\n", (float)totalService / N);
    printf("Average Time in System    : %.2f minutes\n", (float)totalTimeSpent / N);
    printf("Total Idle Time           : %d minutes\n", totalIdle);
    printf("Idle Time Percentage      : %.2f%%\n", (float)totalIdle * 100 / simulationTime);
    printf("Server Utilization        : %.2f%%\n", (float)totalService * 100 / simulationTime);

    return 0;
}
