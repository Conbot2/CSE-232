#include "scheduler.h"
#include <fstream>
using std::ifstream;

Scheduler::Scheduler() {
    deque<Job> arrival_queue;
    deque<Job> process_queue;
    deque<Job> finished_jobs;
}

void Scheduler::load_jobs(string filename) {
    int id, arrival_time, service_time;
    ifstream job_file;
    job_file.open(filename);
    while (job_file >> id >> arrival_time >> service_time) {
        Job current_job(id,arrival_time,service_time);
        arrival_queue.push_back(current_job);
    }
    job_file.close();
}

void Scheduler::round_robin() {
    long time_clock = 0;
    for (auto obj : arrival_queue) {
        if (obj.get_arrival_time() >= time_clock)
            process_queue.push_back(obj);
        else
            arrival_queue.push_back(obj);
        arrival_queue.erase(arrival_queue.begin());
    }
    do {
        for (auto elem : process_queue) {
            elem.update_time_left(1);
            ++time_clock;
            // ++elem.time_taken;
            if (elem.get_time_left() == 0) {
                elem.set_finish_time(time_clock);
                finished_jobs.push_back(elem);
            }
            else
                process_queue.push_back(elem);
            process_queue.pop_front();
        }
    } while (!this->finished());
}

bool Scheduler::finished() {
        if (process_queue.empty() && arrival_queue.empty())
        return true;
    else
        return false;
}

void Scheduler::display() {
    double total_time, time_run;
    double num_jobs = 0;
    for (auto elem : finished_jobs) {
        time_run = elem.get_finish_time() - elem.get_arrival_time();
        total_time += time_run;
        ++num_jobs;
    }
    double avg = total_time / num_jobs;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "       JobID       Arrival Time       Finish Time" << endl;
    for (auto obj : finished_jobs) {
        cout << setw(10) << obj.get_job_id() << "               " << obj.get_arrival_time() << "                 "
        << obj.get_finish_time()<< "          " << endl; //<< obj.time_taken << endl;
    }
    cout << endl;
    cout << "The average amount of time to finish one job is " << avg << " seconds." << endl;
    cout << "--------------------------------------------------------------------" << endl;
}
