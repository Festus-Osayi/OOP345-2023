#ifndef _SDDS_EMPLOYEE_H_
#define _SDDS_EMPLOYEE_H_
#include <iostream>
#include "Person.h"



namespace sdds{
    class Employee : public Person{
        std::string emp_name;
        std::string emp_age;
        std::string emp_id;
        public:
        Employee(){};
        Employee(std::istream& istr);
        std::string status() const;
        std::string name() const;
        std::string id() const;
        std::string age() const;
        void display(std::ostream& out) const;

    };

}

#endif // end of an if statement..