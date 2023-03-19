/*Filename: SpellChecker.cpp
Author:	Festus Osayi
Student Number : 170276216
-----------------------------------------------------------
Date: 2023/02/19
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.*/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstring>
#include "SpellChecker.h"

using namespace std;

namespace sdds
{
    // receives the address of a C-style null-terminated string that holds the name of the file that contains the misspelled words. If the file exists, this constructor loads its contents.
    SpellChecker::SpellChecker(const char *filename)
    {
        std::ifstream file(filename);
        if (!file)
            throw "Bad file name!";
        else
        {
            std::string str{""};
            size_t i = 0u;
            do
            {
                std::getline(file, str);

                if (file)
                {
                    size_t index = str.find(' ');
                    m_badWords[i] = str.substr(0, index);
                    str.erase(0, index);
                    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
                    m_goodWords[i] = str;
                    i++;
                }
            } while (file);
        }
        file.close(); //optional but a good practice..
    }
    // this operator searches `text` and replaces any misspelled word with the correct version. It should also count how many times **each** misspelled word has been replaced.
    void SpellChecker::operator()(std::string &text)
    {
        size_t found = 0;
        for (size_t i = 0; i < NUMWORDS; i++)
        {
            while ((found = text.find(m_badWords[i])) != std::string::npos)
            {
                text.replace(found, m_badWords[i].length(), m_goodWords[i]);
                m_count[i]++;

            }
        }
    }

    // inserts into the parameter how many times each misspelled word has been replaced by the correct word using the current instance. The format of the output is
    void SpellChecker::showStatistics(std::ostream &out) const
    {
        out << "Spellchecker Statistics" << std::endl;
        for (size_t i = 0; i < NUMWORDS; i++)
        {
            out << std::right << std::setw(15) << m_badWords[i] << ": " << m_count[i] << " replacements" << std::endl;

            
        
        }



    }
}