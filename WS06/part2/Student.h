/*Filename: Student.h
Author:	Festus Osayi
Student Number : 170276216
-----------------------------------------------------------
Date: 2023/03/12
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.*/
#ifndef _SDDS_STUDENT_H_
#define _SDDS_STUDENT_H_
#include <iostream>
#include "Person.h"
namespace sdds{
    class Student : public Person{
        std::string m_name;
        std::string m_age;
        std::string m_id;
        std::string* m_courses{};
        std::string m_count;
        int m_c{};

        public:
         Student() = default;
        ~Student();
        Student(std::istream&);
        // Disabling Copy Operations
        Student(const Student&) = delete;
        Student& operator=(const Student&) = delete;
        std::string status() const;
        std::string name() const;
        std::string age() const;
		std::string id() const;
        void display(std::ostream& out) const;
    };
}

#endif
