/*
Name: Faisal A Mohammed Abdulateef
Seneca E-mail: fabdulateef@myseneca.ca
Student ID: 163686215
Class Section: OOP345 ZDD
W2-P1
*/

#ifndef PROTEINDATABASE_H_
#define PROTEINDATABASE_H_

#include <iostream>
#include <fstream>
#include <iomanip>
#include <utility>
#include <chrono>
#include <string>

namespace sdds
{
    class ProteinDatabase
    {
    private:
        std::string* stringsArr{};

    public:
        ProteinDatabase();
        ProteinDatabase(std::string fileArg);
        ProteinDatabase(const ProteinDatabase& database);
        ProteinDatabase& operator=(const ProteinDatabase& database);
        ~ProteinDatabase();
        
        size_t size() const;
        std::string operator[](size_t index) const;
    };
}

#endif