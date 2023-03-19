/*Filename: Employee.cpp
Author:	Festus Osayi
Student Number : 170276216
-----------------------------------------------------------
Date: 2023/03/12
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.*/
#include "Employee.h"
#include <iostream>
#include <iomanip>

namespace sdds {
    // a custom constructor that receives an object of type `std::istream&` as parameter. This constructor should be able to read a single record from the stream, extract all the information about a single Employee and store it in the attributes.
    Employee::Employee(std::istream& is) {
        std::string temp {};
        is.ignore(1);

        std::getline(is, temp);
        size_t startPos {0};
        size_t endPos{temp.find(',')};

        // Getting the name and storing it
        m_name = temp.substr(startPos, (endPos - startPos));
        startPos = endPos + 1;
        endPos = temp.find(',', startPos);
        m_name.erase(0, m_name.find_first_not_of(" \t\r\n"));
        m_name.erase(m_name.find_last_not_of(" \t\r\n") + 1);

        // Getting the age and storing it
        m_age = temp.substr(startPos, (endPos - startPos));
        startPos = endPos + 1;
        endPos = temp.find(',', startPos);
        m_age.erase(0, m_age.find_first_not_of(" \t\r\n"));
        m_age.erase(m_age.find_last_not_of(" \t\r\n") + 1);

         // Validating the age
         for (auto& ch: m_age) {
             if (std::isdigit(ch) == 0) {
                std::string err{"++Invalid record!"};
                 throw m_name + err;
             }
         }

        // Getting the id and storing it
        m_id = temp.substr(startPos, (endPos - startPos));
        startPos = endPos + 1;
        endPos = temp.find(',', startPos);
        m_id.erase(0, m_id.find_first_not_of(" \t\r\n"));
        m_id.erase(m_id.find_last_not_of(" \t\r\n") + 1);

        // Validating the employee id
        if (tolower(m_id[0]) != 'e') {
            std::string err{"++Invalid record!"};
           throw m_name + err;
        }

        // Getting the id and storing it
        m_dept = temp.substr(startPos, (endPos - startPos));
        m_dept.erase(0, m_dept.find_first_not_of(" \t\r\n"));
        m_dept.erase(m_dept.find_last_not_of(" \t\r\n") + 1);
    }

    // A query that returns the word Employee
    std::string Employee::status() const { return "Employee"; }

    // A query that returns the name of the employee
    std::string Employee::name() const { return m_name; }

    // A query that returns the id of the employee
    std::string Employee::id() const { return m_id; }

    // A query that returns the age of the employee
    std::string Employee::age() const { return m_age; }

    // a query that inserts in the first parameter the content of the employee object
    void Employee::display(std::ostream& out) const {
        out << std::left;
        out << "| " << std::setw(10) << "Employee" << "| ";
        out << std::setw(10) << m_id << "| ";
        out << std::setw(20) << m_name << " | ";
        out << std::setw(3) << m_age << " |";
    }
}
