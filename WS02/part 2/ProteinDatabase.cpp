/*
Name: Faisal A Mohammed Abdulateef
Seneca E-mail: fabdulateef@myseneca.ca
Student ID: 163686215
Class Section: OOP345 ZDD
W2-P2
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
    ProteinDatabase::ProteinDatabase()
	{
		this->stringsArr = nullptr;
		this->numOfStrings = 0;
	}

    ProteinDatabase::ProteinDatabase(string fileArg)
    {
        ifstream file(fileArg);
		size_t numberStrings = 0;
        string fileString;
        
        while (getline(file, fileString))
		{
            if (fileString[0] == '>')
			{
                string line;
                if (getline(file, line))
				{
					if (line[0] != '>')
					{
						numberStrings++;
					}
                }

                if (file.eof())
                {
                    break;
                }
            }
        }

        this->numOfStrings = numberStrings;
		this->stringsArr = new string[numOfStrings];
        
		file.clear();
		file.seekg(0, ios::beg);

        int index = 0;
        string line;

        while (getline(file, line))
        {
            if (line[0] != '>')
            {
                this->stringsArr[index - 1] += line;
            }
            else
			{
				index++;
            }
        }
    }

    ProteinDatabase::ProteinDatabase(const ProteinDatabase& database)
	{
		this->numOfStrings = database.numOfStrings;
        this->stringsArr = new string[this->numOfStrings];
		
        for (size_t i = 0; i < this->numOfStrings; i++)
		{
            this->stringsArr[i] = database.stringsArr[i];
        }
	}

    ProteinDatabase::ProteinDatabase(ProteinDatabase&& database)
	{
		this->stringsArr = database.stringsArr;
		database.stringsArr = nullptr;
		this->numOfStrings = database.numOfStrings;
		database.numOfStrings = 0;
	}

    ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& database)
    {
        if (this != &database)
        {
            delete[] this->stringsArr;
			this->numOfStrings = database.numOfStrings;

            this->stringsArr = new string[numOfStrings];
            for (size_t i = 0; i < this->numOfStrings; i++)
            {
                this->stringsArr[i] = database.stringsArr[i];
            }
        }

        return *this;
    }

    ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& database)
    {
        if (this != &database)
        {
			delete[] this->stringsArr;
			this->stringsArr = database.stringsArr;
			database.stringsArr = nullptr;
			this->numOfStrings = database.numOfStrings;
			database.numOfStrings = 0;
		}

		return *this;
    }

    ProteinDatabase::~ProteinDatabase()
	{
		delete[] this->stringsArr;
		this->stringsArr = nullptr;
	}

    size_t ProteinDatabase::size() const { return this->numOfStrings; }

    string ProteinDatabase::operator[](size_t index) const
    {
        if (this->numOfStrings > 0 && index < this->numOfStrings && index >= 0)
        {
			return  this->stringsArr[index];
		}
		else
        {
			return "";
		}
    }
}