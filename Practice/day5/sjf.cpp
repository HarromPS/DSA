#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

// process
class Process
{
public:
    int process_no;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
    // int response_time;
};

class SJF
{
public:
    Process *array;
    int top;
    int noOfProcesses;
    float AvgTAT, AvgWT;
    SJF(int noOfProcesses)
    {
        this->array = new Process[noOfProcesses]; // Use new for object allocation
        this->top = -1;
        this->noOfProcesses = noOfProcesses;
        this->AvgTAT = 0;
        this->AvgWT = 0;
    }

    // insert process one by one in the ready queue
    void insert(int pNo, int at, int bt)
    {
        if (this->top >= this->noOfProcesses)
        {
            printf("Ready Queue is Full\n");
            return;
        }

        this->top += 1;
        this->array[this->top].process_no = pNo;
        this->array[this->top].arrival_time = at;
        this->array[this->top].burst_time = bt;
        this->array[this->top].turn_around_time = 0;
        this->array[this->top].completion_time = 0;
        this->array[this->top].waiting_time = 0;
        // this->array[this->top].response_time = 0;
    }

    int sortByArrivalTime()
    {
        int isAllSame = 1;
        for (int i = 0; i < this->noOfProcesses - 1; i++)
        {
            if (this->array[i].arrival_time != 0)
            {
                isAllSame = 0;
            }
        }
        if (isAllSame)
        {
            return 1;
        }

        for (int i = 0; i < this->noOfProcesses - 1; i++)
        {
            int isSorted = 1;
            for (int j = 0; j < this->noOfProcesses - 1 - i; j++)
            {
                if (this->array[j].arrival_time > this->array[j + 1].arrival_time)
                {
                    Process temp = this->array[j];
                    this->array[j] = this->array[j + 1];
                    this->array[j + 1] = temp;
                    isSorted = 0;
                }
            }
            if (isSorted)
            {
                break;
            }
        }
        return 0;
    }

    void sortByProcessId()
    {
        for (int i = 0; i < this->noOfProcesses - 1; i++)
        {
            int isSorted = 1;
            for (int j = 0; j < this->noOfProcesses - 1 - i; j++)
            {
                if (this->array[j].process_no > this->array[j + 1].process_no)
                {
                    Process temp = this->array[j];
                    this->array[j] = this->array[j + 1];
                    this->array[j + 1] = temp;
                    isSorted = 0;
                }
            }
            if (isSorted)
            {
                break;
            }
        }
    }

    int sortByBurstTime()
    {
        int isAllSame = this->array[0].burst_time;
        for (int i = 1; i < this->noOfProcesses; i++)
        {
            // if any one burst time is not same then return
            if (this->array[i].burst_time != isAllSame)
            {
                return 0;
            }
        }

        // means all are same
        return 1;
    }
    void completionTime()
    {
        if (this->top < 0)
        {
            printf("No process in queue");
            return;
        }

        // sort all the process on the basis of their burst time
        int aRes = sortByArrivalTime();
        int bRes = sortByBurstTime();

        // if all the processes are already sorted by their arrival time
        if (aRes && bRes)
        {
            sortByProcessId();
        }

        queue<Process> prevHoldingQueue;
        queue<Process> q;
        int index = 0;
        for (int i = 0; i < this->noOfProcesses; i++)
        {
            if (this->array[i].arrival_time > index)
            {
                while (index != this->array[i].arrival_time)
                {
                    index += 1;
                }
            }
            // add the process with the same arrival  time in the queue
            int j = i;
            queue<Process> tempQueue;
            while (this->array[j].arrival_time <= index && i < this->noOfProcesses)
            {
                tempQueue.push(this->array[j]);
                j++;
                i++;
            }
            i--;

            // Sort the queue according to burst time
            vector<Process> tempVector;
            while (!tempQueue.empty())
            {
                tempVector.push_back(tempQueue.front());
                tempQueue.pop();
            }

            // sort according to the burst time
            sort(tempVector.begin(), tempVector.end(), [](const Process &a, const Process &b)
                 { return a.burst_time < b.burst_time; });

            // Push the sorted elements back into the existing 'q'
            for (const Process &process : tempVector)
            {
                q.push(process);
            }
            this->array[i] = q.front();
            index += this->array[i].burst_time;
            this->array[i].completion_time = index;
            prevHoldingQueue.push(this->array[i]);
            q.pop();
        }

        while (!q.empty())
        {
            this->array[0] = q.front();
            index += this->array[0].burst_time;
            this->array[0].completion_time = index;
            prevHoldingQueue.push(this->array[0]);
            q.pop();
        }

        int i = 0;
        while (!prevHoldingQueue.empty() && i < this->noOfProcesses)
        {
            this->array[i] = prevHoldingQueue.front();
            prevHoldingQueue.pop();
            i++;
        }

        this->turnAroundTime();
        this->waitingTime();
    }
    void turnAroundTime()
    {
        // calculating the turn around time
        for (int i = 0; i < this->noOfProcesses; i++)
        {
            this->array[i].turn_around_time = this->array[i].completion_time - this->array[i].arrival_time;
            this->AvgTAT += this->array[i].turn_around_time;
        }
        this->AvgTAT /= this->noOfProcesses;
    }

    void waitingTime()
    {
        // calculating the waiting time
        for (int i = 0; i < this->noOfProcesses; i++)
        {
            this->array[i].waiting_time = this->array[i].turn_around_time - this->array[i].burst_time;
            this->AvgWT += this->array[i].waiting_time;
        }
        this->AvgWT /= this->noOfProcesses;
    }
    void printTable()
    {
        cout << "SJF\n"
             << endl;
        cout << "PNo\t"
             << "AT\t"
             << "BT\t"
             << "CT\t"
             << "TAT\t"
             << "WT\t" << endl;
        for (int i = 0; i < this->noOfProcesses; i++)
        {
            cout << this->array[i].process_no << "\t" << this->array[i].arrival_time << "\t" << this->array[i].burst_time << "\t" << this->array[i].completion_time << "\t" << this->array[i].turn_around_time << "\t" << this->array[i].waiting_time << endl;
        }
        cout << "\nAverage TAT: " << this->AvgTAT << endl;
        cout << "Average WT: " << this->AvgWT << endl;
    }
    // void responseTime(){}
};

int main()
{
    int pNo[] = {1, 2, 3, 4};
    int at[] = {1, 2, 1, 4};
    int bt[] = {3, 4, 2, 4};

    SJF obj(4);
    for (int i = 0; i < 4; i++)
    {
        obj.insert(pNo[i], at[i], bt[i]);
    }
    obj.completionTime();
    obj.printTable();

    return 0;
}