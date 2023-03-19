#ifndef _SDDS_COLLECTION_H_
#define _SDDS_COLLECTION_H_
#include <iostream>
#include "pair.h"
namespace sdds
{

    template <typename T, unsigned int max_Capacity>

    class Collection
    {
        T arr[max_Capacity]{};
        int numOfRecords{};
        T dummyObj;
        int capacity;

    public:
        Collection();
        int size();
        void display(std::ostream &istr = std::cout);
        bool add(const T &item);
        T operator[](size_t index) const;
    };

    // a no argument constructor..
    template <typename T, unsigned int max_Capacity>
    Collection<T, max_Capacity>::Collection() : capacity{max_Capacity}, dummyObj{}
    {
        this->capacity = max_Capacity;
    }

    // a query that returns the current number of elements in the collection
    template <typename T, unsigned int max_Capacity>
    int Collection<T, max_Capacity>::size()
    {
        return numOfRecords;
    }

    // a query that receives as the parameter an output stream (with default value `std::cout`) and inserts into the stream all items from the collection
    template <typename T, unsigned int max_Capacity>
    void Collection<T, max_Capacity>::display(std::ostream &istr)
    {
        istr << "----------------------" << std::endl;
        istr << "| Collection Content |" << std::endl;
        istr << "----------------------" << std::endl;
        for (auto i = 0; i < numOfRecords; i++)
        {
            istr << arr[i] << std::endl;
        }
    }

    // a mutator that adds a copy of the parameter to the collection if there still is capacity. If the item has been added, this function return `true`; `false` otherwise.
    template <typename T, unsigned int max_Capacity>
    bool Collection<T, max_Capacity>::add(const T &item)
    {
        if (this->numOfRecords < this->capacity)
        {
            this->arr[numOfRecords++] = item;
            return true;
        }
        else
        {
            return false;
        }
    }
    //
    template <typename T, unsigned int max_Capacity>
    T Collection<T, max_Capacity>::operator[](size_t index) const
    {
        if (index >= 0 && index <= this->capacity - 1)
        {
            return this->arr[index];
        }
        else
        {
            return this->dummyObj;
        }
    }
}

#endif // end of an if statement