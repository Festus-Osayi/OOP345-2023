/*Filename: College.h
Author:	Festus Osayi
Student Number : 170276216
-----------------------------------------------------------
Date: 2023/03/12
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.*/
#ifndef SDDS_COLLEGE_H
#define SDDS_COLLEGE_H

#include "Person.h"
#include <iostream>
#include <vector>
#include <list>

namespace sdds {
    class College {
    private:
        std::vector<Person*> m_persons {};
    public:
        College() = default;
        virtual ~College();
        // Disabling copy operations
        College(const College&) = delete;
        College& operator=(const College&) = delete;
        // Adds the address of the person object received as parameter into the m_persons vector
        College& operator +=(Person* thePerson);
        // Iterates over the persons stored in m_persons and prints their details
        void display(std::ostream& out = std::cout) const;
        // A template function that iterates over the persons stored in the m_persons, and adds to the second parameter all persons for which the test is true
        template <typename T>
        void select(const T& src, std::list<const Person*>& persons) {
            for (const auto& person : m_persons) {
                if (src(person)) {
                    persons.push_back(person);
                }
            }
        }
    };
}

#endif // SDDS_COLLEGE_H