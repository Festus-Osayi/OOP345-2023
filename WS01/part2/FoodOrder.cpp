/*Filename: FoodOrder.cpp
Author:	Festus Osayi
Student Number : 170276216
-----------------------------------------------------------
Date: 2023/01/22
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "foodorder.h"

using namespace std;

double g_taxrate{};
double g_dailydiscount{};

namespace sdds
{
    // `read()`: a modifier that receives an `istream` reference.
    void FoodOrder::read(std::istream &in)
    {
        char y_n{};
        char desc[75]{};

        if (!in.fail())
        {
            in.getline(this->cstr, CSTR_MAX, ',');
            in.getline(desc, 73, ',');
            in >> this->price_value;
            in.ignore(100, ',');
            in >> y_n;
            in.ignore(2000, '\n');

            y_n == 'N' ? daily_Special = false : daily_Special = true;

            delete[] this->cstr_desc;
            this->cstr_desc = nullptr;
            this->cstr_desc = new char[strlen(desc) + 1];
            strcpy(this->cstr_desc, desc);
        }
    }

    // `display()`: a query that displays to the screen the content of an `Food Order`
    void FoodOrder::display()
    {
        static int counter = 0;
        cout << left << setw(2) << ++counter << ". ";
        double priceTaxed = price_value + (price_value * g_taxrate);
        if (cstr[0] != '\0')
        {
            cout << left << setw(10) << cstr << "|"
                 << left << setw(25) << cstr_desc << "|" << left << setw(12) << setprecision(2) << priceTaxed << "|";

            if (daily_Special)
            {
                cout << right << setw(13) << fixed << priceTaxed - g_dailydiscount << std::endl;
            }
            else
            {
                cout << endl;
            }
        }
        else
        {
            cout << "No Order" << endl;
        }
    }

    // A food order default constructor..
    FoodOrder::FoodOrder()
    {
        this->cstr[0] = '\0';
        this->cstr_desc = nullptr;
        this->price_value = 0;
        this->daily_Special = false;
    }

    // A copy constructor for food order
    FoodOrder::FoodOrder(const FoodOrder &copy)
    {
        // shallow copy
        strcpy(this->cstr, copy.cstr);
        this->price_value = copy.price_value;
        this->daily_Special = copy.daily_Special;

        delete[] this->cstr_desc;
        this->cstr_desc = nullptr;

        // deep copying..
        this->cstr_desc = new char[strlen(copy.cstr_desc) + 1];
        strcpy(this->cstr_desc, copy.cstr_desc);
    }

    // A FoodOrder can be assign or copied
    FoodOrder &FoodOrder::operator=(const FoodOrder &assign)
    {
        // shallow copying..

        strcpy(this->cstr, assign.cstr);
        this->price_value = assign.price_value;
        this->daily_Special = assign.daily_Special;

        // deleting any previous allocation on order_desc if none.
        if (this->cstr_desc)
        {
            delete[] this->cstr_desc;
            this->cstr_desc = nullptr;
        }
        // deep copying..
        if (assign.cstr_desc != nullptr)
        {
            this->cstr_desc = new char[strlen(assign.cstr_desc) + 1];
            strcpy(this->cstr_desc, assign.cstr_desc);
        }
        else
        {
            this->cstr_desc = nullptr;
        }

        return *this;
    }

    // a foodorder destructor..
    FoodOrder::~FoodOrder()
    {
        delete[] this->cstr_desc;
        this->cstr_desc = nullptr;
    }

}