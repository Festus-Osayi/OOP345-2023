/*Filename: Utilities.cpp
Author:	Festus Osayi
Student Number : 170276216
-----------------------------------------------------------
Date: 2023/03/12
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.*/
#include <iostream>
#include "Utilities.h"
#include "Employee.h"
#include "Professor.h"
#include "Student.h"

using namespace std;
namespace sdds{

// a single function that creates instances on the `Person` hierarchy.
    Person* buildInstance(std::istream& in){
        char temp{};
        in>>temp;

          if(temp == 'e' || temp == 'E'){
            return new Employee(in);
          }
          else if(temp == 'p' || temp == 'P'){
            return new Professor(in);
          }
          else if(temp == 's' || temp == 'S'){
            return new Student(in);
          }

        // ignore the rest of the string or character..
        in.ignore(1000, '\n');
        return nullptr;
    }

    
    
}
