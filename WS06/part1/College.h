#ifndef _SDDS_COLLEGE_H_
#define _SDDS_COLLEGE_H_
#include <iostream>
#include <vector>
#include "Person.h"

namespace sdds{
    class College{
        std::vector<Person*> m_persons;

        public:
        College(){};
        // The `College` should have the copy operations disabled
        College(const College&) = delete;
        College& operator=(const College&) = delete;
        College& operator +=(Person* thePerson);
        void display(std::ostream& out) const;
    };
}

#endif //end of an if statement..