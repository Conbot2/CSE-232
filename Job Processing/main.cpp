#include <iostream>
using std::cout; using std::endl; using std::cin;
#include "job.h"
#include "scheduler.h"

int main(){
    // Initialize the scheduler 
    Scheduler S;

    // Load the job list
    string jobfile;
    cout << "Please input the job file name:";
    cin >> jobfile;
    S.load_jobs(jobfile);

    // Scheduling the jobs
    S.round_robin();

    // Print the results
    S.display();
}
