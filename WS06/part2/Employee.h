/*Filename: Employee.h
Author:	Festus Osayi
Student Number : 170276216
-----------------------------------------------------------
Date: 2023/03/12
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.*/
#ifndef SDDS_EMPLOYEE_H
#define SDDS_EMPLOYEE_H
#include "Person.h"
#include <iostream>

namespace sdds {
    class Employee : public Person {
    private:
        std::string m_name {};
        std::string m_age {};
        std::string m_id {};
    public:
        // To store optional department
        std::string m_dept {};
        Employee() = default;
        // Overloaded Constructor that loads data in the object
        Employee(std::istream& is);
        // A query that returns the string Employee
        std::string status() const;
        // A query that returns the name of the employee
        std::string name() const;
        // A query that returns the id of the employee
        std::string id() const;
        // A query that returns the age of the employee
        std::string age() const;
        // A query that inserts in the first parameter the content of the employee object
        void display(std::ostream& out = std::cout) const;

    };
};

#endif // SDDS_EMPLOYEE_H