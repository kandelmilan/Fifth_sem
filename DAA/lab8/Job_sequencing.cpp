//write a program to implement the job sequencing with deadline
// JOB SEQUENCING
#include <iostream>
using namespace std;

// Structure to represent a Job
struct Job {
    char id;        // Job ID
    int deadline;   // Deadline of job
    int profit;     // Profit if job is completed before or on deadline
};

// Function to sort jobs in descending order of profit (simple bubble sort for clarity)
void sortJobs(Job jobs[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (jobs[j].profit < jobs[j + 1].profit) {
                Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
}

// Function to find maximum deadline from the jobs
int findMaxDeadline(Job jobs[], int n) {
    int maxDeadline = jobs[0].deadline;
    for (int i = 1; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }
    return maxDeadline;
}

// Main Job Sequencing Function
void JobSequencing(Job jobs[], int n) {
    // Sort jobs by profit in descending order
    sortJobs(jobs, n);

    // Find maximum deadline
    int maxDeadline = findMaxDeadline(jobs, n);

    // Initialize slots as free (-1 indicates free)
    char schedule[maxDeadline];
    for (int i = 0; i < maxDeadline; i++) {
        schedule[i] = '-';
    }

    int totalProfit = 0;

    // Iterate through all jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (from its deadline backward)
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (schedule[j] == '-') {
                schedule[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Print the scheduled jobs
    cout << "Scheduled Jobs: ";
    for (int i = 0; i < maxDeadline; i++) {
        if (schedule[i] != '-') {
            cout << schedule[i] << " ";
        }
    }
    cout << endl;

    cout << "Total Profit: " << totalProfit << endl;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    Job jobs[n];
    cout << "Enter Job ID, Deadline and Profit for each job:\n";
    for (int i = 0; i < n; i++) {
        cout << "Job " << i + 1 << " (ID Deadline Profit): ";
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    JobSequencing(jobs, n);

    return 0;
}
