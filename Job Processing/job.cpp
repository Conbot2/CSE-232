#include "job.h"

Job::Job() {
    id = 0;
    arrival = 0;
    service = 0;
    time_left = 0;
}

Job::Job(int jobID,int arrival_time,int service_time) {
    id = jobID;
    arrival = arrival_time;
    service = service_time;
    time_left = service;
    // time_taken = 0;  // for checking math
}

int Job::get_job_id() {
    return id;
}

int Job::get_arrival_time() {
    return arrival;
}

int Job::get_time_left() {
    return time_left;
}

void Job::update_time_left(int spent) {
    time_left -= spent;
}

void Job::set_finish_time(int finish_time) {
    finish = finish_time;
}

int Job::get_finish_time() {
    return finish;
}
