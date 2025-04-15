//Lab -6 Implementation of single server queuing system
/*
Scenario:
    Grocery shop with single checkout counter
    Customer arrives in 1 to 8 min gap with equal probability
    Each customer takes 1 to 6 min of service time with equal probability
*/
/*
Activity 1: Create a simulation table for give scenario for 20 customer and calculate:
            Average waiting time
            Average time spent in the system
            Average service time
            Server utilization
            Total idle time and percentage.
*/

/*
Algorithm:
    1. Create the structure customer with following:
        int arrival time
        int service time
        int start time
        int end time
    2. Generate customer, Arrival time, Service time, and store them in a structure.
    3. Calculate the service begin, service end time of each customer.
    4. Generate the statistics in tabular form with following
        Customer No., Interarrival time, Arrival time, Service time, Service begin time, Service end time, time spent, idle time
    5. Print the following performance parameters
        Average wait time
        Average time spent
        Average service time
        server utilization
        Total idle time and percentage
        
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CUSTOMERS 20

int main() {
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

    int totalWaitingTime = 0, totalServiceTime = 0, totalTimeInSystem = 0, totalIdleTime = 0;
    float serverUtilization;

    // Ask user for max values
    printf("Enter maximum Inter-Arrival Time: ");
    scanf("%d", &maxIAT);

    printf("Enter maximum Service Time : ");
    scanf("%d", &maxST);

    srand(time(NULL));

    // Generate inter-arrival and service times
    for (i = 0; i < NUM_CUSTOMERS; i++) {
        interArrival[i] = (i == 0) ? 0 : (rand() % maxIAT + 1);  // 0 for first customer
        serviceTime[i] = rand() % maxST + 1;  // 1 to maxST minutes
    }

    // First customer
    arrivalTime[0] = 0;
    serviceStart[0] = 0;
    waitingTime[0] = 0;
    serviceEnd[0] = serviceStart[0] + serviceTime[0];
    timeInSystem[0] = serviceEnd[0] - arrivalTime[0];
    idleTime[0] = 0;

    totalServiceTime += serviceTime[0];
    totalTimeInSystem += timeInSystem[0];

    // Remaining customers
    for (i = 1; i < NUM_CUSTOMERS; i++) {
        arrivalTime[i] = arrivalTime[i - 1] + interArrival[i];

        if (arrivalTime[i] >= serviceEnd[i - 1]) {
            serviceStart[i] = arrivalTime[i];
            idleTime[i] = arrivalTime[i] - serviceEnd[i - 1];
        } else {
            serviceStart[i] = serviceEnd[i - 1];
            idleTime[i] = 0;
        }

        waitingTime[i] = serviceStart[i] - arrivalTime[i];
        serviceEnd[i] = serviceStart[i] + serviceTime[i];
        timeInSystem[i] = serviceEnd[i] - arrivalTime[i];

        totalWaitingTime += waitingTime[i];
        totalServiceTime += serviceTime[i];
        totalTimeInSystem += timeInSystem[i];
        totalIdleTime += idleTime[i];
    }

    // Print table
    printf("\nCust\tIAT\tAT\tST\tStart\tWait\tEnd\tSysTime\tIdle\n");
    for (i = 0; i < NUM_CUSTOMERS; i++) {
        printf("%2d\t%3d\t%3d\t%3d\t%5d\t%4d\t%4d\t%6d\t%4d\n",
            i + 1, interArrival[i], arrivalTime[i], serviceTime[i],
            serviceStart[i], waitingTime[i], serviceEnd[i],
            timeInSystem[i], idleTime[i]);
    }

    // Print results
    float avgWaitingTime = (float)totalWaitingTime / NUM_CUSTOMERS;
    float avgServiceTime = (float)totalServiceTime / NUM_CUSTOMERS;
    float avgTimeInSystem = (float)totalTimeInSystem / NUM_CUSTOMERS;
    int totalSimulationTime = serviceEnd[NUM_CUSTOMERS - 1];
    serverUtilization = (float)totalServiceTime / totalSimulationTime * 100;
    float idlePercentage = (float)totalIdleTime / totalSimulationTime * 100;

    printf("\n--- Simulation Results ---\n");
    printf("Average Waiting Time       : %.2f min\n", avgWaitingTime);
    printf("Average Service Time       : %.2f min\n", avgServiceTime);
    printf("Average Time in System     : %.2f min\n", avgTimeInSystem);
    printf("Total Idle Time            : %d min\n", totalIdleTime);
    printf("Percentage Idle Time       : %.2f%%\n", idlePercentage);
    printf("Server Utilization         : %.2f%%\n", serverUtilization);

    return 0;
}

