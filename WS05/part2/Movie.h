/*Filename: Book.h
Author:	Festus Osayi
Student Number : 170276216
-----------------------------------------------------------
Date: 2023/02/19
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.*/
#ifndef _SDDS_Movie_H_
#define _SDDS_Movie_H_
#include <iostream>
#include <string>
#include "SpellChecker.h"
namespace sdds{
    class Movie{
        std::string movieTitle{};
        size_t movieYearOfRelease{};
        std::string movieDesc{};

    public:
        Movie(){movieTitle = "", movieYearOfRelease = -1, movieDesc = "";};
        const std::string &title() const;
        Movie(const std::string &strMovie);
        template<typename T>
        void fixSpelling(T &spellChecker){
            spellChecker(movieTitle);
            spellChecker(movieDesc);
        }
        std::ostream& write(std::ostream& ostr)const;
        friend std::ostream& operator<<(std::ostream& ostr, const Movie &os);
    };
    
}

#endif //end of an if statements..