/*Filename: FoodOrder.h
Author:	Festus Osayi
Student Number : 170276216
-----------------------------------------------------------
Date: 2023/01/22
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#ifndef _SDDS_FOODORDER_H_
#define _SDDS_FOODORDER_H_
#define CSTR_MAX 10
#define CSTR_STRING 25
#include <iostream>
extern double g_dailydiscount;
extern double g_taxrate;
namespace sdds
{

    // class declaration//
    class FoodOrder
    {
        char cstr[CSTR_MAX + 1];
        char cstr_desc[CSTR_STRING + 1];
        double price_value{};
        bool dailySpecial;

    public:
        void read(std::istream &istr);
        void display() const;
    };
}

#endif // end of an if statement.