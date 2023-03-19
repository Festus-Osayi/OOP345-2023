/*Filename: ConfirmOrder.cpp
Author:	Festus Osayi
Student Number : 170276216
-----------------------------------------------------------
Date: 2023/02/12
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.*/
#include "Toy.h"
#include "ConfirmOrder.h"
using namespace std;
namespace sdds
{
    // a default constructor
    ConfirmOrder::ConfirmOrder(){}

    // adds the toy `toy` to the array by adding its address.
    ConfirmOrder &ConfirmOrder::operator+=(const Toy &toy)
    {
        bool unique = true;
        // allocate and copy
        // delete[] m_toys;
        const Toy **toys = new const Toy *[m_toysNum + 1] {};
        for (auto i = 0; i < m_toysNum; i++)
        {
            toys[i] = m_toys[i];
        }

        delete[] m_toys;
        m_toys = toys;

        // check for uniqueness
        for (int i = 0; i < m_toysNum; i++)
        {
            if (m_toys[i] == &toy)
            {
                unique = false;
            }
        }
        // add
        if (unique)
        {
            m_toys[m_toysNum++] = &toy;
        }
        return *this;
    }

    // removes the toy `toy` from the array by removing its address
    ConfirmOrder &ConfirmOrder::operator-=(const Toy &toy)
    {
        bool found = false;
        int index;
        // checking for uniqueness
        for (int i = 0; i < m_toysNum && !found; i++)
        {
            if (m_toys[i] == &toy)
            {
                index = i;
                found = true;
            }
        }
        // remove
        if (found)
        {
            m_toys[index] = nullptr;
        }
        return *this;
    }

    // return true if the array pointer of toys is valid/not null
    ConfirmOrder::operator bool() const
    {
        return m_toys;
    }

    // copy constructor
    ConfirmOrder::ConfirmOrder(const ConfirmOrder &copy)
    {
        if (copy)
        {
            *this = copy;
        }
    }
    // move copyconstructor
    ConfirmOrder::ConfirmOrder(ConfirmOrder &&move_assign)
    {
        operator=(move(move_assign));
    }
    // copy assignment operator
    ConfirmOrder &ConfirmOrder::operator=(const ConfirmOrder &assign)
    {
        if (this != &assign)
        { 
            m_toysNum = assign.m_toysNum;
            delete[] m_toys;
            m_toys = new const Toy *[m_toysNum] {};
            for (int i = 0; i < m_toysNum; i++)
            {
                m_toys[i] = assign.m_toys[i];
            }
        }
        return *this;
    }
    // move assignment operator
    ConfirmOrder &ConfirmOrder::operator=(ConfirmOrder &&move_assign)
    {
        if (this != &move_assign)
        {

            
            // move
            this->m_toysNum = move_assign.m_toysNum;
            this->m_toys = move_assign.m_toys;
            // delete
            move_assign.m_toys = nullptr;
            move_assign.m_toysNum = 0;
        }
        return *this;
    }

    // a destructor
    ConfirmOrder::~ConfirmOrder()
    {
        delete[] m_toys;
    }

    // the insertion operator to insert the content of a `ConfirmOrder` object into an **ostream** object
    std::ostream &operator<<(std::ostream &ostr, const ConfirmOrder &confirm)
    {
        ostr << "--------------------------" << endl;
        ostr << "Confirmations to Send" << endl;
        ostr << "--------------------------" << endl;
        
        if (confirm.m_toys != nullptr)
        {
            for (int i = 0; i < confirm.m_toysNum; i++)
            {
                if (confirm.m_toys[i]) //???
                    ostr << *(confirm.m_toys[i]);
            }
        }
        else
        {
            ostr << "There are no confirmations to send!" << endl;
        }
        ostr << "--------------------------" << endl;
        return ostr;
    }
}