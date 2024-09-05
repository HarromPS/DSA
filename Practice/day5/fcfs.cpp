#include <iostream>
#include <cstdio>
using namespace std;

// process
class Process{
public:
    int process_no;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
    // int response_time;
};

class FCFS{
public:
    Process *array;
    int top;
    int noOfProcesses;
    float AvgTAT,AvgWT;
    FCFS(int noOfProcesses){
        this->array = new Process[noOfProcesses]; // Use new for object allocation
        this->top = -1;
        this->noOfProcesses = noOfProcesses;
        this->AvgTAT=0;
        this->AvgWT=0;
    }

    // insert process one by one in the ready queue
    void insert(int pNo, int at, int bt){
        if (this->top >= this->noOfProcesses){
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

    int sortByArrivalTime(){
        int isAllSame=1;
        for(int i=0;i<this->noOfProcesses-1;i++){
            if(this->array[i].arrival_time != 0){
                isAllSame=0;
            }
        }
        if(isAllSame){
            return 1;
        }

        for(int i=0;i<this->noOfProcesses-1;i++){
            int isSorted=1;
            for(int j=0;j<this->noOfProcesses - 1 - i;j++){
                if(this->array[j].arrival_time > this->array[j+1].arrival_time){
                    Process temp = this->array[j];
                    this->array[j] = this->array[j+1];
                    this->array[j+1] = temp;
                    isSorted=0;
                }
            }
            if(isSorted){
                break;
            }
        }
        return 0;
    }

    void sortByProcessId(){
        for(int i=0;i<this->noOfProcesses-1;i++){
            int isSorted=1;
            for(int j=0;j<this->noOfProcesses - 1 - i;j++){
                if(this->array[j].process_no > this->array[j+1].process_no){
                    Process temp = this->array[j];
                    this->array[j] = this->array[j+1];
                    this->array[j+1] = temp;
                    isSorted=0;
                }
            }
            if(isSorted){
                break;
            }
        }
    }
    void completionTime(){
        if(this->top<0){
            printf("No process in queue");
            return;
        }

        // sort all the process on the basis of their burst time
        int res=sortByArrivalTime();

        // if all the processes arrives at same time
        if(res){
            sortByProcessId();
        }

        // completion time of the first process is same as its burst time
        int index=0;
        for(int i=0;i<this->noOfProcesses;i++){
            if(this->array[i].arrival_time <= index){
                index += this->array[i].burst_time;
                this->array[i].completion_time=index;
            }
            else if(this->array[i].arrival_time > index){
                while(index!=this->array[i].arrival_time){
                    index+=1;
                }
                index+=this->array[i].burst_time;
                this->array[i].completion_time=index;
            }
        }
        this->turnAroundTime();
        this->waitingTime();

    }
    void turnAroundTime(){
        // calculating the turn around time
        for(int i=0;i<this->noOfProcesses;i++){
            this->array[i].turn_around_time=this->array[i].completion_time - this->array[i].arrival_time;
            this->AvgTAT+=this->array[i].turn_around_time;
        }
        this->AvgTAT/=this->noOfProcesses;
    }

    void waitingTime(){
        // calculating the waiting time
        for(int i=0;i<this->noOfProcesses;i++){
            this->array[i].waiting_time=this->array[i].turn_around_time - this->array[i].burst_time;
            this->AvgWT+=this->array[i].waiting_time;
        }
        this->AvgWT/=this->noOfProcesses;
    }
    void printTable(){
        cout<<"FCFS\n"<<endl;
        cout<<"PNo\t"<<"AT\t"<<"BT\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<endl;
        for(int i=0;i<this->noOfProcesses;i++){
            cout<<this->array[i].process_no<<"\t"<<this->array[i].arrival_time<<"\t"<<this->array[i].burst_time<<"\t"<<this->array[i].completion_time<<"\t"<<this->array[i].turn_around_time<<"\t"<<this->array[i].waiting_time<<endl;
        }

        cout<<"\nAverage TAT: "<<this->AvgTAT<<endl;
        cout<<"Average WT: "<<this->AvgWT<<endl;
    }
    // void responseTime(){}
};

int main(){
    // int pNo[] = {1,2,3,4,5};
    // int at[] = {0,0,0,0,0};
    // int bt[] = {20,29,3,7,12};
    int pNo[] = {1, 2, 3, 4};
    int at[] = {0, 1, 5, 6};
    int bt[] = {2, 2, 3, 4};

    FCFS obj(4);
    for(int i=0;i<4;i++){
        obj.insert(pNo[i],at[i],bt[i]);
    }
    obj.completionTime();
    obj.printTable();

    return 0;
}