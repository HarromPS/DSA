#include <stdio.h>
// Structure to represent a process
struct Process
{
    int process_id;
    int priority;
    int burst_time;
};
// Function to perform Priority Scheduling
void priorityScheduling(struct Process processes[], int n)
{
    int total_time = 0;
    int turnaround_time = 0;
    int waiting_time = 0;
    // Sort the processes based on priority (higher priority first)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (processes[j].priority < processes[j + 1].priority)
            {
                // Swap processes
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
    // Calculate waiting time, turnaround time, and total time
    for (int i = 0; i < n; i++)
    {
        waiting_time += total_time;
        turnaround_time += total_time + processes[i].burst_time;
        total_time += processes[i].burst_time;
    }
    // Calculate average waiting time and average turnaround time
    double avg_waiting_time = (double)waiting_time / n;
    double avg_turnaround_time = (double)turnaround_time / n;
    // Display results
    printf("Process\tPriority\tBurst Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\n", processes[i].process_id, processes[i].priority, processes[i].burst_time);
    }
    printf("\nAverage Waiting Time: %.2lf\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2lf\n", avg_turnaround_time);
}
int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];
    // Input process details
    for (int i = 0; i < n; i++)
    {
        processes[i].process_id = i + 1;
        printf("Enter priority and burst time for process %d: ", i + 1);
        scanf("%d%d", &processes[i].priority, &processes[i].burst_time);
    }
    priorityScheduling(processes, n); // Perform Priority
    return 0;
}