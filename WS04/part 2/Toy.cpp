/*Filename: Toy.cpp
Author:	Festus Osayi
Student Number : 170276216
-----------------------------------------------------------
Date: 2023/02/12
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.*/
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <iterator>
#include <functional>
#include <cstring>
#include "Toy.h"

using namespace std;

namespace sdds
{

    // a default constructor
    Toy::Toy(){};

    // a modifier that receives as a parameter the number of toys of this type to be ordered and updates the number of items attribute with the received value. Assume the parameter is correct and doesn't require validation.
    void Toy::update(int numItems)
    {
        this->t_items = numItems;
    }

    // A constructor that receives the toy attributes as a string; this constructor is responsible for extracting information about the toy from the string and storing the tokens in the instance's attributes. The string will always have the following format:
    Toy::Toy(const std::string &toy)
    {

        // a local varaibles to extract the given data..
        unsigned int s_pos{};
        unsigned int e_pos{};
        string toys{toy};

        // setting up the order id

        this->t_Id = stoi(toys);

        // setting up the name..

        s_pos = toys.find(':');
        toys = toys.substr(s_pos + 1);
        s_pos = 0;
        e_pos = toys.find(':');
        this->t_name = toys.substr(s_pos, e_pos);

        // removing all leading and trailing spaces from the **beginning and end** of any token extracted from the string. gotten from GeeksforGeeks

        this->t_name.erase(remove(this->t_name.begin(), this->t_name.end(), ' '), this->t_name.end());

        // set ITEMS NUM
        s_pos = toys.find(':');
        toys = toys.substr(s_pos + 1);
        toys.erase(std::remove(toys.begin(), toys.end(), ' '), toys.end());
        this->t_items = stoi(toys);

        // set PRICE
        s_pos = toys.find(':');
        toys = toys.substr(s_pos + 1);
        this->t_price = stod(toys);
    }

    // overload the insertion operator to insert the contents of a toy object into an `ostream` object
    std::ostream &Toy::write(std::ostream &ostr) const
    {
        double subtotal = this->t_price * this->t_items;
        double tax = subtotal * this->t_hst / 100;
        double total = subtotal + tax;
        ostr << "Toy " << t_Id << ":";
        ostr.setf(ios::right);
        ostr.width(18);
        ostr << this->t_name;
        ostr.width(3);
        ostr << this->t_items;
        ostr << " items";
        ostr.width(8);
        ostr << fixed << std::setprecision(2) << this->t_price;
        ostr << "/item  subtotal: ";
        ostr.width(6);
        ostr << subtotal;
        ostr << " tax: ";
        ostr.width(5);
        ostr << subtotal * this->t_hst / 100;
        ostr << " total: ";
        ostr.width(6);
        ostr << total << endl;
        ostr.unsetf(ios::right);
        return ostr;
    }

    std::ostream &operator<<(std::ostream &ostr, const Toy &helper)
    {
        if (!ostr.fail())
        {
            helper.write(ostr);
        }
        return ostr;
    }
}