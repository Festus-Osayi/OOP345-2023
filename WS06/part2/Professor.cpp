/*Filename: Professor.cpp
Author:	Festus Osayi
Student Number : 170276216
-----------------------------------------------------------
Date: 2023/03/12
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.*/
#include "Professor.h"
#include <iostream>
using std::cout;
using std::endl;

namespace sdds {
    // Calls the constructor from Employee to build the sub-object
    Professor::Professor(std::istream& in) : Employee(in) {
        m_department = Employee::m_dept;
    }

    // calls the constructor from `Employee` to build the sub-object, and then it extracts the last field from the stream containing the department.
    void Professor::display(std::ostream& out) const {
        Employee::display(out);
        out << m_department;
        out << "| Professor";
    }

    // A query that returns word Professor
    std::string Professor::status() const { return "Professor"; }

    // A query that returns the department
    std::string Professor::department() const { return m_department; }
}