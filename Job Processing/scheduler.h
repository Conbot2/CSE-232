#include <string>
using std::string;
#include <iostream>
using std::cin; using std::cout; using std::endl; 
#include <iomanip>
using std::setw;
#include <deque>
using std::deque;
#include "job.h"

#ifndef __SCHEDULER_H_INCLUDED__
#define __SCHEDULER_H_INCLUDED__

class Scheduler
{
    private:
        deque<Job> arrival_queue;
        deque<Job> process_queue;
        deque<Job> finished_jobs;
    public:
        Scheduler();
        void load_jobs(string);
        void round_robin();
        bool finished();
        void display();
};

#endif