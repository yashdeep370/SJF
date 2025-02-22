#include <stdio.h>

struct Process {
    int id, burst_time, waiting_time, turnaround_time;
};

void sort_by_burst_time(struct Process proc[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (proc[j].burst_time > proc[j + 1].burst_time) {
                struct Process temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }
}

void calculate_waiting_time(struct Process proc[], int n) {
    proc[0].waiting_time = 0;
    for (int i = 1; i < n; i++) {
        proc[i].waiting_time = proc[i - 1].waiting_time + proc[i - 1].burst_time;
    }
}

void calculate_turnaround_time(struct Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnaround_time = proc[i].waiting_time + proc[i].burst_time;
    }
}

void display_processes(struct Process proc[], int n) {
    printf("\nProcess ID | Burst Time | Waiting Time | Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%10d | %10d | %12d | %15d\n", proc[i].id, proc[i].burst_time, proc[i].waiting_time, proc[i].turnaround_time);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];
    printf("Enter burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;
        printf("Process %d: ", i + 1);
        scanf("%d", &proc[i].burst_time);
    }

    sort_by_burst_time(proc, n);
    calculate_waiting_time(proc, n);
    calculate_turnaround_time(proc, n);
    display_processes(proc, n);

    return 0;
}
