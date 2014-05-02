#ifndef __JOB_H_INCLUDED__
#define __JOB_H_INCLUDED__

class Job {
    private:
        int id, arrival, service, time_left, finish;
    public:
        Job();
        Job(int,int,int);
        int get_job_id();
        int get_arrival_time();
        int get_time_left();
        void update_time_left(int);
        void set_finish_time(int);
        int get_finish_time();
        int time_taken;
};

#endif