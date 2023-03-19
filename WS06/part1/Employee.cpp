#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Employee.h"

using namespace std;

namespace sdds{
    // a custom constructor that receives an object of type `std::istream&` as parameter. This constructor should be able to read a single record from the stream, extract all the information about a single Employee and store it in the attributes.
    Employee::Employee(std::istream& istr){
        string temp{};
        istr.ignore(1);

        getline(istr, temp);
        size_t startPos{0};
        size_t endPos{temp.find(',')};

        // getting the name and storing it, in it's attribute

        this->emp_name = temp.substr(startPos, (endPos - startPos));
        startPos = endPos + 1;
        endPos = temp.find(',', startPos);
        this->emp_name.erase(0, this->emp_name.find_first_not_of(" \t\r\n"));
        this->emp_name.erase(this->emp_name.find_last_not_of(" \t\r\n") + 1);

        // getting the age and storing it, in it's attribute
       
        this->emp_age = temp.substr(startPos, (endPos - startPos));
        startPos = endPos + 1;
        endPos = temp.find(',', startPos);
        this->emp_age.erase(0, this->emp_age.find_first_not_of(" \t\r\n"));
        this->emp_age.erase(this->emp_age.find_last_not_of(" \t\r\n") + 1);

         // age validation

         for (auto& ch: emp_age) {
            const char *temp{"Invalid record!"};
            string err{temp};
             if (std::isdigit(ch) == 0) {
                throw emp_name + "Invalid record!";
             }
         }
          // Getting the id and storing it
        emp_id = temp.substr(startPos, (endPos - startPos));
        emp_id.erase(0, emp_id.find_first_not_of(" \t\r\n"));
        emp_id.erase(emp_id.find_last_not_of(" \t\r\n") + 1);

        // Validating the employee id
        if (tolower(emp_id[0]) != 'e') {
            
           throw emp_name + "Invalid record!";
        }
        
    }
    // a query that returns the string "Employee"
    string Employee::status() const{
        return "Employee";
    }

    // a query that resturn the employee name..
    string Employee::name() const{
        return this->emp_name;
    }

    // a query that resturn the employee Id
    string Employee::id() const{
        return this->emp_id;
    }

    // a query that resturn the employee age
    string Employee::age() const{
        return this->emp_age;
    }

    // a query that inserts in the first parameter the content of the employee.
    void Employee::display(std::ostream& out) const{
        if(!out.fail()){
            out<<"| "<<left<<setw(10)<<"Employee"<<" | "
            <<left<<setw(10)<<this->emp_id<<" | "
            <<left<<setw(20)<<this->emp_name
            <<" | "<<left<<setw(3)<<this->emp_age<<" |";
        }
    }

}