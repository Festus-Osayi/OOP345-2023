/*Filename: Collection.h
Author:	Festus Osayi
Student Number : 170276216
-----------------------------------------------------------
Date: 2023/02/19
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.*/
#ifndef _SDDS_COLLECTION_H_
#define _SDDS_COLLECTION_H_
#include <string>
#include <iostream>
#include <stdexcept>
namespace sdds
{
    template <typename T>
    class Collection
    {
    private:
        std::string collectionName{};
        size_t collectionSize;
        T *collectionItem;
        void (*collectionObserver)(const Collection<T> &, const T &collection);

    public:
        // sets the name of the collection to the string referred to by the parameter and sets all other attributes to their default value
        Collection(const std::string &name)
        {
            this->collectionName = name;
            this->collectionSize = 0;
            this->collectionItem = nullptr;
            this->collectionObserver = nullptr;
        }
        // a destructor..
        ~Collection()
        {
            delete[] this->collectionItem;
        }

        // a query that returns the name of the collection.
        const std::string &name() const
        {
            return this->collectionName;
        }

        size_t size() const
        {
            return this->collectionSize;
        }

        // stores the address of the callback function (`observer`) into an attribute. This parameter is a pointer to a function
        // that returns `void`
        void setObserver(void (*observer)(const Collection<T> &, const T &))
        {
            this->collectionObserver = observer;
        }

        // adds a copy of `item` to the collection, only if the collection doesn't contain an item with the same title. If `item` is already in the collection, this function does nothing.
        Collection<T> &operator+=(const T &item)
        {
            bool validCollection = true;
            for (size_t i = 0; i < collectionSize && validCollection; i++)
            {
                if (collectionItem[i].title() == item.title())
                {
                    validCollection = false;
                }
            }
            if (validCollection)
            {
                T *temp = new T[collectionSize + 1];
                for (size_t i = 0; i < collectionSize; i++)
                {
                    temp[i] = collectionItem[i];
                }

                delete[] collectionItem;
                collectionItem = temp;
                collectionItem[collectionSize++] = item;

                if (collectionObserver != nullptr)
                {
                    collectionObserver(*this, item);
                }
            }
            return *this;
        }
        // returns the item at index `idx`.
        // - if the index is out of range, this operator throws an exception of type `std::out_of_range` with the message `Bad index[IDX].Collection has[SIZE] items.`.
        T &operator[](size_t idx) const
        {
            if (idx < collectionSize)
            {
                return collectionItem[idx];
            }
            throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(collectionSize) + "] items.");
        }

        // returns the address of the item with the title `title` (type `T` has a member function called `title()` that returns the title of the item). If no such item exists, this function returns `nullptr`.
        T *operator[](std::string title) const
        {
            for (size_t i = 0; i < collectionSize; i++)
            {
                if (title == collectionItem[i].title())
                {
                    return collectionItem + i;
                }
            }
            return nullptr;
        }

    };
    // overload the insertion operator to insert the content of a `Collection` object into an **ostream** object
    template <typename T>
    std::ostream &operator<<(std::ostream &os, const Collection<T> &c_obj)
    {
        for (size_t i = 0; i < c_obj.size(); i++)
        {
            os << c_obj[i];
        }
        return os;
    }
};

#endif // end of an if statements..