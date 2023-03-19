#include <iostream>
#include "Utilities.h"
#include "Employee.h"

using namespace std;
namespace sdds{

// a single function that creates instances on the `Person` hierarchy.
    Person* buildInstance(std::istream& in){
        char temp{};
        in>>temp;

          if(temp == 'e' || temp == 'E'){
            return new Employee(in);
          }

        // ignore the rest of the string or character..
        in.ignore(2000, '\n');
        return nullptr;
    }

    
    
}
