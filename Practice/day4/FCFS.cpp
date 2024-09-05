#include <iostream>
#include <cstdio>
using namespace std;

// First Come First Server algo

class FCFS
{
public:
    // Matrix for storing the process burst, arival, completn, tat, wt
    int *burstTime;
    int *turnAroundTime;
    int *watingTime;
    int n;
    FCFS(int n)
    {
        this->n = n;
        this->turnAroundTime = (int *)calloc(sizeof(int *), n);
        this->watingTime = (int *)calloc(sizeof(int *), n);
        this->burstTime = (int *)calloc(sizeof(int *), n);
    }

    void findAvgTAT()
    {
        findTurnaroundTime();
        float avgTAT = 0;
        for (int i = 0; i < this->n; i++)
        {
            avgTAT += this->turnAroundTime[i];
        }
        cout << "Average time is: " << avgTAT << endl;
    }
    void findAvgWT()
    {
        void findWaitingTime();

        float avgWT = 0;
        for (int i = 0; i < this->n; i++)
        {
            avgWT += this->turnAroundTime[i];
        }

        cout << "Average time is: " << avgWT << endl;
    }
    void findWaitingTime()
    {
        this->watingTime[0] = 0;
        for (int i = 1; i < this->n; i++)
        {
            this->watingTime[i] = this->burstTime[i - 1];
        }
    }
    void setBurstTime()
    {
        for (int i = 0; i < this->n; i++)
        {
            cout << "Enter burst time of " << (i + 1) << ": ";
            cin >> this->burstTime[i];
        }
    }
    void findTurnaroundTime()
    {
        this->turnAroundTime[0] = this->burstTime[0];
        for (int i = 1; i < this->n; i++)
        {
            this->turnAroundTime[i] = this->burstTime[i - 1] + this->burstTime[i];
        }
    }
};
int main()
{
    FCFS s(4);
    s.setBurstTime();
    s.findAvgTAT();
    s.findAvgWT();
    return 0;
}