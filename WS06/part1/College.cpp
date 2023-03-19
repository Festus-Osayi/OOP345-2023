#include <iostream>
#include <iomanip>
#include "College.h"

using namespace std;

namespace sdds{

    // adds the address of the person object received as parameter into the `m_persons` vector..
    College& College::operator +=(Person* thePerson){
        m_persons.push_back(thePerson);
        return *this;
    }

    // iterates over the persons stored in `m_persons` and prints their details  using the following format (one person per line, see the sample output for formatting details).
     void College::display(std::ostream& out) const{
        out << "------------------------------------------------------------------------------------------------------------------------" <<endl;
        out << "|                                        Test #1 Persons in the college!                                               |" <<endl;
        out << "------------------------------------------------------------------------------------------------------------------------" <<endl;

        for(auto i = m_persons.begin(); i != m_persons.end(); i++) {
            (*i)->display(out);
            out << std::endl;
        }

        out << "------------------------------------------------------------------------------------------------------------------------" <<endl;
        out << "|                                        Test #2 Persons in the college!                                               |" <<endl;
        out << "------------------------------------------------------------------------------------------------------------------------" <<endl;

        for(auto iterator = m_persons.begin(); iterator != m_persons.end(); iterator++) {
            out << std::left;
            out << "| " << std::setw(10) << (*iterator)->status() << " | ";
            out << std::setw(10) << (*iterator)->id() << " | ";
            out << std::setw(20) << (*iterator)->name() << " | ";
            out << std::setw(3) << (*iterator)->age() << " |";
            out << std::endl;
        }

        out << "-----------------------------------------" <<endl;
    
     }
}