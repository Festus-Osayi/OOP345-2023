/*
Name: Faisal A Mohammed Abdulateef
Seneca E-mail: fabdulateef@myseneca.ca
Student ID: 163686215
Class Section: OOP345 ZDD
W2-P1
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <utility>
#include <chrono>
#include <string>
#include "TimedTask.h"

using namespace std;
namespace sdds
{
    TimedTask::TimedTask()
    {
        this->numRecords = 0;
    }

    void TimedTask::startClock()
    {
        this->startTime = std::chrono::steady_clock::now();
    }

    void TimedTask::stopClock()
    {
        this->endTime = std::chrono::steady_clock::now();
    }

    void TimedTask::addTask(const char* taskname)
    {
        this->taskArr[this->numRecords].taskName = taskname;
        this->taskArr[this->numRecords].unitTime = "nanoseconds";
        this->taskArr[this->numRecords].taskDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(this->endTime - this->startTime);
        this->numRecords++;
    }

    ostream& operator<<(ostream& os, TimedTask& tasks)
    {
        os << "--------------------------" << endl;
		os << "Execution Times:  " << endl;
		os << "--------------------------" << endl;

		for (int i = 0; i < tasks.numRecords; i++)
		{
			os << left << setw(21) << tasks.taskArr[i].taskName;
			os << right << setw(13) << tasks.taskArr[i].taskDuration.count();
			os << " " << tasks.taskArr[i].unitTime << endl;
		}

		os << "--------------------------" << endl;

		return os;
    }
}