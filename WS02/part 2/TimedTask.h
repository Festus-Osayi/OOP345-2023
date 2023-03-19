/*
Name: Faisal A Mohammed Abdulateef
Seneca E-mail: fabdulateef@myseneca.ca
Student ID: 163686215
Class Section: OOP345 ZDD
W2-P2
*/

#ifndef TIMEDTASK_H_
#define TIMEDTASK_H_

#include <iostream>
#include <fstream>
#include <iomanip>
#include <utility>
#include <chrono>
#include <string>

namespace sdds
{
    class TimedTask
    {
        int numRecords;
        std::chrono::steady_clock::time_point startTime;
        std::chrono::steady_clock::time_point endTime;

        struct Task
        {
            std::string taskName;
            std::string unitTime;
            std::chrono::steady_clock::duration taskDuration;
        };

        Task taskArr[10];

    public:
        TimedTask();
        void startClock();
        void stopClock();
        void addTask(const char* taskname);
        friend std::ostream& operator<<(std::ostream& os, TimedTask& tasks);
    };
}

#endif