/*Filename: SpellChecker.h
Author:	Festus Osayi
Student Number : 170276216
-----------------------------------------------------------
Date: 2023/02/19
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.*/
#ifndef _SDDS_SPELLCHECKER_H_
#define _SDDS_SPELLCHECKER_H_
#include <iostream>
#define NUMWORDS 6
namespace sdds
{
    class SpellChecker
    {
        std::string m_badWords[NUMWORDS]{};
        std::string m_goodWords[NUMWORDS]{};
        int m_count[NUMWORDS]{};

    public:
        SpellChecker(){};
        SpellChecker(const char *filename);
        void operator()(std::string &text);
        void showStatistics(std::ostream &out) const;
    };
}

#endif // end of an if statement..