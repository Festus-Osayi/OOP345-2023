/*Filename: Child.cpp
Author:	Festus Osayi
Student Number : 170276216
-----------------------------------------------------------
Date: 2023/02/12
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.*/

#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include "Child.h"
#include "Toy.h"
using namespace std;
namespace sdds
{
    // constructor that receives as a parameter a name and an age, and an array of pointers to objects of  type `Toy`
    Child::Child(string name, int age, const Toy *toys[], size_t count) : child_age{age},
                                                                          child_toysNum{count},
                                                                          child_name{name}
    {
        obj_toys = new const Toy *[count];
        for (int i = 0; i < static_cast<int>(count); i++)
        {
            obj_toys[i] = new Toy(*toys[i]);
        }
    }

    // a query that returns the number of toys stored in the array attribute.
    size_t Child::size() const
    {
        return child_toysNum;
    }

    // the insertion operator to insert the content of a `Child` object into an `ostream` object. This operator should use a local to function variable to count how many times this operator has been called

    ostream &operator<<(std::ostream &ostr, const Child &os)
    {
        static int CALL_CNT = 0;
        ostr << "--------------------------" << endl;
        ostr << "Child " << ++CALL_CNT << ": " << os.child_name + " " << os.child_age << " years old:" << endl;
        ostr << "--------------------------" << endl;

        if (os.obj_toys != nullptr)
        {
            for (size_t i = 0; i < os.size(); i++)
            {
                ostr << *os.obj_toys[i];
            }
        }
        else
        {
            ostr << "This child has no toys!" << endl;
        }
        ostr << "--------------------------" << endl;
        return ostr;
    }

    // return true if the array pointer of toys is valid/not null
    Child::operator bool() const
    {
        return obj_toys;
    }
    // copy constructor
    Child::Child(const Child &copy)
    {
        if (copy)
        {
            *this = copy;
        }
    }
    // move copyconstructor
    Child::Child(Child &&move)
    {
        operator=(std::move(move));
    }
    // copy assignment operator
    Child &Child::operator=(const Child &assign)
    {
        if (this != &assign)
        { // if not self copy

            for (size_t i = 0; i < child_toysNum; i++)
            {
                delete this->obj_toys[i];
            }
            delete[] this->obj_toys;
            // shallow copying..
            this->child_age = assign.child_age;
            this->child_toysNum = assign.child_toysNum;
            this->child_name = assign.child_name;

            // deep copying
            obj_toys = new const Toy *[size()];
            for (size_t i = 0; i < size(); i++)
            {
                obj_toys[i] = new Toy(*assign.obj_toys[i]);
            }
        }
        return *this;
    }

    // move assignment operator
    Child &Child::operator=(Child &&move_assign)
    {
        if (this != &move_assign)
        {

            for (size_t i = 0; i < this->child_toysNum; i++)
            {
                delete this->obj_toys[i]; // this
            }
            delete[] this->obj_toys;
            // move
            this->obj_toys = move_assign.obj_toys;
            this->child_age = move_assign.child_age;
            this->child_name = move_assign.child_name;
            this->child_toysNum = move_assign.child_toysNum;
            // delete
            move_assign.obj_toys = nullptr;
            move_assign.child_age = 0;
            move_assign.child_name = "";
            move_assign.child_toysNum = 0;
        }
        return *this;
    }

    // a destructor
    Child::~Child()
    {

        for (size_t i = 0; i < child_toysNum; i++)
        {
            delete this->obj_toys[i];
        }
        delete[] this->obj_toys;
    }
}
