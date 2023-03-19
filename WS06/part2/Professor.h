/*Filename: Professor.h
Author:	Festus Osayi
Student Number : 170276216
-----------------------------------------------------------
Date: 2023/03/12
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.*/
#ifndef _SDDS_PROFESSOR_H_
#define _SDDS_PROFESSOR_H_
#include <string>
#include <iostream>
#include "Employee.h"

namespace sdds{
    class Professor : public Employee{

        //the department the professor works at
        std::string m_department{};

        public:
        Professor(){};
        Professor(std::istream& in);
        void display(std::ostream& out) const;
        std::string status() const;
        std::string department() const;
    };

}

#endif //end of an if statement..