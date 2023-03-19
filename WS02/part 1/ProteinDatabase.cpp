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
#include "ProteinDatabase.h"

using namespace std;
namespace sdds
{
    static size_t numOfStrings = 0;

    ProteinDatabase::ProteinDatabase() { numOfStrings = 0; }

    ProteinDatabase::ProteinDatabase(string fileArg)
    {
        numOfStrings = 0;
		string fileString;
		ifstream in;
		in.open(fileArg);
		in.ignore();

		while (in)
        {
			getline(in, fileString, '>');
			numOfStrings++;
		}

		numOfStrings--;

		in.clear();
		in.seekg(0);
		in.ignore();

		this->stringsArr = new string[numOfStrings];
		for (size_t i = 0; i < numOfStrings; i++)
		{
			in.ignore(1000, '\n');
			getline(in, fileString, '>');
			this->stringsArr[i] = fileString;
		}
    }

    ProteinDatabase::ProteinDatabase(const ProteinDatabase& database) { *this = database; }

    ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& database)
    {
        if (this != &database)
        {
            delete[] this->stringsArr;

            this->stringsArr = new string[numOfStrings];
            for (size_t i = 0; i < numOfStrings; i++)
            {
                this->stringsArr[i] = database.stringsArr[i];
            }
        }

        return *this;
    }

    ProteinDatabase::~ProteinDatabase() { delete[] this->stringsArr; }

    size_t ProteinDatabase::size() const { return numOfStrings; }

    string ProteinDatabase::operator[](size_t index) const
    {
        if (numOfStrings > 0 && index < numOfStrings && index >= 0)
        {
			return  this->stringsArr[index];
		}
		else
        {
			return "";
		}
    }
}