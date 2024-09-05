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
    int burst_time_temp;
    int completion_time;
    int turn_around_time;
    int waiting_time;
    int priority;
};

class Priority
{
public:
    Process *array;
    int top;
    int noOfProcesses;
    float AvgTAT, AvgWT;
    Priority(int noOfProcesses){
        try {
            this->array = new Process[noOfProcesses]; // Use new for object allocation
            this->top = -1;
            this->noOfProcesses = noOfProcesses;
            this->AvgTAT = 0;
            this->AvgWT = 0;
        } catch (const std::bad_alloc& e) {
            std::cerr << "Memory allocation failed: " << e.what() << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    // insert process one by one in the ready queue
    void insert(int pNo, int at, int bt, int pr)
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
        this->array[this->top].burst_time_temp = bt;
        this->array[this->top].turn_around_time = 0;
        this->array[this->top].completion_time = 0;
        this->array[this->top].waiting_time = 0;
        this->array[this->top].priority = pr;
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

    // time quantum = 1 i.e Q = 1
    void completionTime()
    {
        if (this->top < 0)
        {
            printf("No process in queue");
            return;
        }

        // sort all the process on the basis of their burst time
        int res = sortByArrivalTime();

        // if all the processes arrives at same time
        if (res)
        {
            sortByProcessId();
        }

        // completion time of the first process is same as its burst time
        queue<Process> q;
        queue<Process> tempQueue;
        vector<Process> tempVector;
        queue<Process> prevHoldingQueue;
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
            tempQueue.push(this->array[i]);

            // Sort the queue according to priority
            while (!tempQueue.empty())
            {
                tempVector.push_back(tempQueue.front());
                tempQueue.pop();
            }

            // sort according to the priority time
            sort(tempVector.begin(), tempVector.end(), [](const Process &a, const Process &b)
                 { return a.priority < b.priority; });

            // Push the sorted elements back into the existing 'q'
            for (const Process &process : tempVector)
            {
                q.push(process);
            }

            this->array[i] = q.front();
            if (this->array[i].burst_time - 1 == 0)
            {
                prevHoldingQueue.push(this->array[i]);
                q.pop();
            }
            this->array[i].burst_time -= 1;
            index += 1;
            this->array[i].completion_time = index;
        }

        while (!q.empty())
        {
            // Sort the queue according to priority
            while (!tempQueue.empty())
            {
                tempVector.push_back(tempQueue.front());
                tempQueue.pop();
            }

            // sort according to the priority time
            sort(tempVector.begin(), tempVector.end(), [](const Process &a, const Process &b)
                 { return a.priority < b.priority; });

            // Push the sorted elements back into the existing 'q'
            for (const Process &process : tempVector)
            {
                q.push(process);
            }

            this->array[0] = q.front();
            if (this->array[0].burst_time - 1 == 0)
            {
                prevHoldingQueue.push(this->array[0]);
                q.pop();
            }
            this->array[0].burst_time -= 1;
            index += 1;
            this->array[0].completion_time = index;
        }

        int i = 0;
        while (!prevHoldingQueue.empty() && i < this->noOfProcesses){
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
        cout << "Priority\n"
             << endl;
        cout << "PNo\t"
             << "AT\t"
             << "BT\t"
             << "CT\t"
             << "TAT\t"
             << "WT\t" << endl;
        for (int i = 0; i < this->noOfProcesses; i++)
        {
            cout << this->array[i].process_no << "\t" << this->array[i].arrival_time << "\t" << this->array[i].burst_time_temp << "\t" << this->array[i].completion_time << "\t" << this->array[i].turn_around_time << "\t" << this->array[i].waiting_time << endl;
        }

        cout << "\nAverage TAT: " << this->AvgTAT << endl;
        cout << "Average WT: " << this->AvgWT << endl;
    }
};

int main()
{
    int pNo[] = {1, 2, 3, 4};
    int at[] = {0, 1, 2, 4};
    int bt[] = {5, 4, 2, 1};
    int pr[] = {10, 20, 30, 40};

    Priority obj(4);
    for (int i = 0; i < 4; i++)
    {
        obj.insert(pNo[i], at[i], bt[i], pr[i]);
    }
    obj.completionTime();
    obj.printTable();

    return 0;
}
