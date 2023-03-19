/*Filename: Child.h
Author:	Festus Osayi
Student Number : 170276216
-----------------------------------------------------------
Date: 2023/02/12
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.*/
#ifndef SDDS_CHILD_H_
#define SDDS_CHILD_H_
#include <string>
#include <iostream>
#include "Toy.h"
namespace sdds
{
    class Child
    {
    private:
        int child_age{};
        size_t child_toysNum{};
        std::string child_name{};
        const Toy **obj_toys{};

    public:
        Child(std::string name, int age, const Toy *toys[], size_t count);
        size_t size() const;
        friend std::ostream &operator<<(std::ostream &ostr, const Child &os);
        operator bool() const;
        Child(const Child &copy);
        Child(Child &&move);
        Child &operator=(const Child &assign);
        Child &operator=(Child &&move_assign);
        ~Child();
    };
}
#endif // !SDDS_CHILD_H_