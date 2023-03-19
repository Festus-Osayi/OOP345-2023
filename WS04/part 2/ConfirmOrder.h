/*Filename: ConfirmOrder.h
Author:	Festus Osayi
Student Number : 170276216
-----------------------------------------------------------
Date: 2023/02/12
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.*/
#ifndef SDDS_CONFIRMORDER_H_
#define SDDS_CONFIRMORDER_H_
#include <string>
#include <iostream>
#include "Toy.h"
namespace sdds
{
    class ConfirmOrder
    {
    private:
        int m_toysNum{};
        const Toy **m_toys{};

    public:
        ConfirmOrder &operator+=(const Toy &toy);
        ConfirmOrder &operator-=(const Toy &toy);
        friend std::ostream &operator<<(std::ostream &ostr, const ConfirmOrder &confirm);
        operator bool() const;
        ConfirmOrder();
        ConfirmOrder(const ConfirmOrder &copy);
        ConfirmOrder(ConfirmOrder &&move_assign);
        ConfirmOrder &operator=(const ConfirmOrder &assign);
        ConfirmOrder &operator=(ConfirmOrder &&move_assign);
        ~ConfirmOrder();
    };
}
#endif // !SDDS_CONFIRMORDER_H_