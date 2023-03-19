/*Filename: Movie.cpp
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
#include "Movie.h"

using namespace std;

namespace sdds{

    // a query that returns the title of the movie
    const std::string &Movie::title() const{
        return this->movieTitle;
    }

    // receives the movie through a reference to a string.This constructor extracts the information about the movie from the string and stores the tokens in the attributes.
    Movie::Movie(const std::string &strMovie){
        int title = strMovie.find(',');
        this->movieTitle = strMovie.substr(0, title);
        this->movieTitle.erase(0, this->movieTitle.find_first_not_of(" "));
        this->movieTitle.erase(this->movieTitle.find_last_not_of(" ") + 1);
        int year = strMovie.find(',', title + 1);
        this->movieYearOfRelease = stod(strMovie.substr(title + 1, year - title - 1));

        int description = strMovie.find('.', year + 1);
        this->movieDesc = strMovie.substr(year + 1, description - year + 1);
        this->movieDesc.erase(0, movieDesc.find_first_not_of(" "));
    }

    // overload the insertion operator to insert the content of a movie object into an **ostream** object

    std::ostream &Movie::write(std::ostream &ostr) const{
        ostr<<setw(40)<<this->movieTitle<<" | "<<setw(4)<<this->movieYearOfRelease<<" | "<<this->movieDesc<<endl;

        return ostr;
    }

    std::ostream &operator<<(std::ostream &ostr, const Movie &os){
        if(!ostr.fail()){
            os.write(ostr);
        }else{
            ostr<< "";
        }
        return ostr;
    }
}