/*Filename: Toy.h
Author:	Festus Osayi
Student Number : 170276216
-----------------------------------------------------------
Date: 2023/02/12
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.*/
#ifndef SDDS_TOY_H_
#define SDDS_TOY_H_
#include <iostream>

namespace sdds
{
    class Toy
    {
        unsigned int t_Id{};
        std::string t_name{};
        int t_items{};
        double t_price{};
        const int t_hst = 13;

    public:
        Toy();
        void update(int numItems);
        Toy(const std::string &toy);
        std::ostream &write(std::ostream &ostr) const;
        friend std::ostream &operator<<(std::ostream &ostr, const Toy &helper);
    };

}

#endif