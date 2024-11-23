#include <bits/stdc++.h>
using namespace std;

int n = 5;
int burstTime[] = {10, 29, 3, 7, 12};
float fcfsWaitingTime, sjfWaitingTime, rrWaitingTime;

void FCFS() {
    // find waiting time for all processes
    int waitingTime[n];
    waitingTime[0] = 0;
    for (int i = 1; i < n; i++) {
        waitingTime[i] = burstTime[i-1] + waitingTime[i-1];
    }

    int totalWaitingTime = 0;
    for (int i = 0; i < n; i++) totalWaitingTime += waitingTime[i];
    fcfsWaitingTime = (float)totalWaitingTime / (float)n;
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

    int totalWaitingTime = 0;
    for (int i = 0; i < n; i++) totalWaitingTime += waitingTime[i];
    sjfWaitingTime = (float)totalWaitingTime / (float)n;
}

void RR() {
    int quantum = 10;

    //find waiting time of all processes
    int remainingBurstTime[n];
    for (int i = 0; i < n; i++) {
        remainingBurstTime[i] = burstTime[i];
    }

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

    int totalWaitingTime = 0;
    for (int i = 0; i < n; i++) totalWaitingTime += waitingTime[i];
    rrWaitingTime = (float)totalWaitingTime / (float)n;
}

int main()
{
    FCFS();
    SJF();
    RR();

    if (fcfsWaitingTime < sjfWaitingTime and fcfsWaitingTime < rrWaitingTime) {
        cout << "FCFS give the minimum average waiting time.";
    }
    else if (sjfWaitingTime < fcfsWaitingTime and sjfWaitingTime < rrWaitingTime) {
        cout << "SJF give the minimum average waiting time.";
    }
    else {
        cout << "RR give the minimum average waiting time.";
    }

    return 0;
}
