/*Filename: FoodOrder.h
Author:	Festus Osayi
Student Number : 170276216
-----------------------------------------------------------
Date: 2023/01/22
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#ifndef FOODORDER_H
#define FOODORDER_H

#include <iostream>
#include <iomanip>
#include <fstream>

#define CSTR_MAX 10
extern double g_taxrate;
extern double g_dailydiscount;

namespace sdds
{
    class FoodOrder
    {
        char cstr[CSTR_MAX + 1];
        char *cstr_desc;
        double price_value;
        bool daily_Special;

    public:
        FoodOrder();
        ~FoodOrder();
        void read(std::istream &in);
        void display();
        FoodOrder(const FoodOrder &copy);
        FoodOrder &operator=(const FoodOrder &assign);
    };
}

#endif