#include <bits/stdc++.h>
using namespace std;

int n = 5;
int burstTime[] = {10, 29, 3, 7, 12};

void FCFS() {
    // find waiting time for all processes
    int waitingTime[n];
    waitingTime[0] = 0;
    for (int i = 1; i < n; i++) {
        waitingTime[i] = burstTime[i-1] + waitingTime[i-1];
    }

    // find turn around time for all processes
    int turnAroundTime[n];
    for (int i = 0; i < n; i++) {
        turnAroundTime[i] = burstTime[i] + waitingTime[i];
    }

    // Display processes along with all details
    cout << "Processes  " << " Burst time  " << " Waiting time  " << " Turn around time\n";

    // Calculate total waiting time and total turn around time
    int totalWaitingTime = 0, totalTurnAroundTime = 0;
    for (int i = 0; i < n; i++) {
        totalWaitingTime = totalWaitingTime + waitingTime[i];
        totalTurnAroundTime = totalTurnAroundTime + turnAroundTime[i];
        cout << "   " << i+1 << "\t\t" << burstTime[i] << "\t    " << waitingTime[i] << "\t\t  " << turnAroundTime[i] << "\n";
    }

    cout << "\nAverage waiting time = " << (float)totalWaitingTime / (float)n;
    cout << "\nAverage turn around time = " << (float)totalTurnAroundTime / (float)n;
}

void SJF() {
    // Burst Time and alloting Process Id.
    int bt[n][2];
    for (int i = 0; i < n; i++) {
        bt[i][0] = i;
        bt[i][1] = burstTime[i];
    }

    // Sorting process according to their Burst Time.
    for (int i = 0; i < n; i++) {
        int index = i;
        for (int j = i+1; j < n; j++) {
            if (bt[j][1] < bt[index][1]) index = j;
        }
        swap(bt[i][0], bt[index][0]);
        swap(bt[i][1], bt[index][1]);
    }

    // find waiting time for all processes
    int waitingTime[n];
    waitingTime[bt[0][0]] = 0;
    for (int i = 1; i < n; i++) {
        waitingTime[bt[i][0]] = bt[i-1][1] + waitingTime[bt[i-1][0]];
    }

    // find turn around time for all processes
    int turnAroundTime[n];
    for (int i = 0; i < n; i++) {
        turnAroundTime[i] = burstTime[i] + waitingTime[i];
    }

    // Display processes along with all details
    cout << "Processes  " << " Burst time  " << " Waiting time  " << " Turn around time\n";

    // Calculate total waiting time and total turn around time
    int totalWaitingTime = 0, totalTurnAroundTime = 0;
    for (int i = 0; i < n; i++)
    {
        totalWaitingTime = totalWaitingTime + waitingTime[i];
        totalTurnAroundTime = totalTurnAroundTime + turnAroundTime[i];
        cout << "   " << i + 1 << "\t\t" << burstTime[i] << "\t    " << waitingTime[i] << "\t\t  " << turnAroundTime[i] << "\n";
    }

    cout << "\nAverage waiting time = " << (float)totalWaitingTime / (float)n;
    cout << "\nAverage turn around time = " << (float)totalTurnAroundTime / (float)n;
}

void RR() {
    int quantum = 10;

    // Function to find waiting time of all processes
    int remainingBurstTime[n];
    for (int i = 0; i < n; i++) {
        remainingBurstTime[i] = burstTime[i];
    }

    // Keep traversing processes in round robin manner
    // until all of them are not done.
    int t = 0;
    int waitingTime[n] = {0};
    while (true) {
        bool done = true;

        for (int i = 0; i < n; i++) {
            if (remainingBurstTime[i] > 0) {
                done = false;

                if (remainingBurstTime[i] > quantum) {
                    t += quantum;
                    remainingBurstTime[i] -= quantum;
                }
                else {
                    t += remainingBurstTime[i];
                    waitingTime[i] = t - burstTime[i];
                    remainingBurstTime[i] = 0;
                }
            }
        }

        if (done == true) break;
    }

    // Function to find turn around time for all processes
    int turnAroundTime[n];
    for (int i = 0; i < n; i++)
        turnAroundTime[i] = burstTime[i] + waitingTime[i];

    // Display processes along with all details
    cout << "Processes  " << " Burst time  " << " Waiting time  " << " Turn around time\n";

    // Calculate total waiting time and total turn around time
    int totalWaitingTime = 0, totalTurnAroundTime = 0;
    for (int i = 0; i < n; i++)
    {
        totalWaitingTime = totalWaitingTime + waitingTime[i];
        totalTurnAroundTime = totalTurnAroundTime + turnAroundTime[i];
        cout << "   " << i + 1 << "\t\t" << burstTime[i] << "\t    " << waitingTime[i] << "\t\t  " << turnAroundTime[i] << "\n";
    }

    cout << "\nAverage waiting time = " << (float)totalWaitingTime / (float)n;
    cout << "\nAverage turn around time = " << (float)totalTurnAroundTime / (float)n;
}

int main()
{
    cout << "FCFS------------------\n";
    FCFS();
    cout << "\n\nSJF------------------\n";
    SJF();
    cout << "\n\nRR------------------\n";
    RR();
    return 0;
}
