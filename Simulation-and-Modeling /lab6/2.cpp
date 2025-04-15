#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CUSTOMERS 20

int main()
{
    int i;
    int maxIAT, maxST;

    int interArrival[NUM_CUSTOMERS];
    int arrivalTime[NUM_CUSTOMERS];
    int serviceTime[NUM_CUSTOMERS];
    int serviceStart[NUM_CUSTOMERS];
    int serviceEnd[NUM_CUSTOMERS];
    int waitingTime[NUM_CUSTOMERS];
    int timeInSystem[NUM_CUSTOMERS];
    int idleTime[NUM_CUSTOMERS];

    int totalWaitingTime = 0, totalServiceTime = 0;
    int totalTimeInSystem = 0, totalIdleTime = 0;

    int minWaitingTime = 9999, maxWaitingTime = -1;
    float serverUtilization, avgNumInSystem;

    // User input for max inter-arrival and service time
    printf("Enter maximum Inter-Arrival Time: ");
    scanf("%d", &maxIAT);

    printf("Enter maximum Service Time: ");
    scanf("%d", &maxST);

    srand(time(NULL));

    // Generate times
    for (i = 0; i < NUM_CUSTOMERS; i++)
    {
        interArrival[i] = (i == 0) ? 0 : (rand() % maxIAT + 1);
        serviceTime[i] = rand() % maxST + 1;
    }

    // First customer
    arrivalTime[0] = 0;
    serviceStart[0] = 0;
    waitingTime[0] = 0;
    serviceEnd[0] = serviceTime[0];
    timeInSystem[0] = serviceEnd[0];
    idleTime[0] = 0;

    totalWaitingTime += waitingTime[0];
    totalServiceTime += serviceTime[0];
    totalTimeInSystem += timeInSystem[0];

    minWaitingTime = waitingTime[0];
    maxWaitingTime = waitingTime[0];

    // Process rest
    for (i = 1; i < NUM_CUSTOMERS; i++)
    {
        arrivalTime[i] = arrivalTime[i - 1] + interArrival[i];

        if (arrivalTime[i] >= serviceEnd[i - 1])
        {
            serviceStart[i] = arrivalTime[i];
            idleTime[i] = arrivalTime[i] - serviceEnd[i - 1];
        }
        else
        {
            serviceStart[i] = serviceEnd[i - 1];
            idleTime[i] = 0;
        }

        waitingTime[i] = serviceStart[i] - arrivalTime[i];
        serviceEnd[i] = serviceStart[i] + serviceTime[i];
        timeInSystem[i] = serviceEnd[i] - arrivalTime[i];

        // Totals
        totalWaitingTime += waitingTime[i];
        totalServiceTime += serviceTime[i];
        totalTimeInSystem += timeInSystem[i];
        totalIdleTime += idleTime[i];

        // Update min/max wait
        if (waitingTime[i] < minWaitingTime)
            minWaitingTime = waitingTime[i];
        if (waitingTime[i] > maxWaitingTime)
            maxWaitingTime = waitingTime[i];
    }

    // Display Table
    printf("\nCust\tIAT\tAT\tST\tStart\tWait\tEnd\tSysTime\tIdle\n");
    for (i = 0; i < NUM_CUSTOMERS; i++)
    {
        printf("%2d\t%3d\t%3d\t%3d\t%5d\t%4d\t%4d\t%6d\t%4d\n",
               i + 1, interArrival[i], arrivalTime[i], serviceTime[i],
               serviceStart[i], waitingTime[i], serviceEnd[i],
               timeInSystem[i], idleTime[i]);
    }

    // Final stats
    int totalSimTime = serviceEnd[NUM_CUSTOMERS - 1];

    float avgWaitingTime = (float)totalWaitingTime / NUM_CUSTOMERS;
    float avgServiceTime = (float)totalServiceTime / NUM_CUSTOMERS;
    float avgTimeInSystem = (float)totalTimeInSystem / NUM_CUSTOMERS;
    float idlePercentage = (float)totalIdleTime * 100 / totalSimTime;
    serverUtilization = (float)totalServiceTime * 100 / totalSimTime;

    avgNumInSystem = (float)totalTimeInSystem / totalSimTime;

    // Print results
    printf("\n--- Simulation Results ---\n");
    printf("Average Waiting Time            : %.2f min\n", avgWaitingTime);
    printf("Minimum Waiting Time            : %d min\n", minWaitingTime);
    printf("Maximum Waiting Time            : %d min\n", maxWaitingTime);
    printf("Average Service Time            : %.2f min\n", avgServiceTime);
    printf("Average Time in System          : %.2f min\n", avgTimeInSystem);
    printf("Total Idle Time                 : %d min\n", totalIdleTime);
    printf("Percentage Idle Time            : %.2f%%\n", idlePercentage);
    printf("Server Utilization              : %.2f%%\n", serverUtilization);
    printf("Average Number in System        : %.2f customers\n", avgNumInSystem);

    return 0;
}
