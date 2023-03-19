#ifndef SDDS_COLLECTION_H_
#define SDDS_COLLECTION_H_
#include <iostream>
#include "Pair.h"

namespace sdds
{
    template <typename T, unsigned int max_Capacity>
    class Collection
    {
    protected:
        unsigned int numOfRecords{};
        T m_objects[max_Capacity]{};
        T dummyObj{};

    public:
        virtual ~Collection();
        int size();
        void display(std::ostream &os = std::cout);
        virtual bool add(const T &item);
        virtual T operator[](size_t index);
    };

    template <typename T, unsigned int max_Capacity>
    Collection<T, max_Capacity>::~Collection()
    {}

    //  a query that returns the current number of elements in the collection
    template <typename T, unsigned int max_Capacity>
    int Collection<T, max_Capacity>::size()
    {
        return this->numOfRecords;
    }

    // a query that receives as the parameter an output stream (with default value `std::cout`) and   inserts into the stream all items from the collection
    template <typename T, unsigned int max_Capacity>
    void Collection<T, max_Capacity>::display(std::ostream &os)
    {
        os << "----------------------" << std::endl;
        os << "| Collection Content |" << std::endl;
        os << "----------------------" << std::endl;
        for (unsigned int i = 0; i < this->numOfRecords; i++)
            os << m_objects[i] << std::endl;
        os << "----------------------" << std::endl;
    }

    // a mutator that adds a copy of the parameter to the collection if there still is capacity. If   the item has been added, this function return `true`; `false` otherwise.
    template <typename T, unsigned int max_Capacity>
    bool Collection<T, max_Capacity>::add(const T &item)
    {
        if (this->numOfRecords < max_Capacity)
        {
            this->m_objects[numOfRecords++] = item;
            return true;
        }
        else
            return false;
    }

    //  a query that receives an index as parameter and returns a copy of the element stored in the collection at the specified index. If the index is not valid (outside the boundaries of the collection), this query returns the dummy object.
    template <typename T, unsigned int max_Capacity>
    T Collection<T, max_Capacity>::operator[](size_t index)
    {
        if (index >= 0 && index <= max_Capacity - 1)
        {
            return this->m_objects[index];
        }
        else
            return dummyObj;
    }

    // specialization for Collection of Pairs
    template <>
    Pair Collection<Pair, 100>::operator[](size_t index)
    {
        if (this->numOfRecords > 0 && index >= 0 && index <= this->numOfRecords - 1)
        {
            return m_objects[index];
        }
        else
            return dummyObj = Pair("No Key", "No Value");
    }
}
#endif // !SDDS_COLLECTION_H_