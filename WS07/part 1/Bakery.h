/*Filename: Bakery.h
Author:	Festus Osayi
Student Number : 170276216
-----------------------------------------------------------
Date: 2023/03/19
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete the workshop.*/
#ifndef SDDS_BAKERY_H
#define SDDS_BAKERY_H

#include <iostream>
#include <vector>

namespace sdds {
    enum class BakedType{
        BREAD, PASTERY
    };

    struct BakedGood {
        BakedType m_bakedType {};
        std::string m_description {};
        int m_shelfLife {};
        int m_stockAmount {};
        double m_price;
    };

    class Bakery {
    private:
        std::vector<BakedGood> m_collection;
    public:
        Bakery() = default;
        // Constructor that populates the collection
        Bakery(const char* filename);
        // Print the content of the collection into the parameter
        void showGoods(std::ostream& os = std::cout) const;
    };

    // Inserts one BakedGood into the first parameter
    std::ostream& operator<<(std::ostream& out, const BakedGood& b);

    // Strips all the white spaces from a string
    std::string strip(const std::string& str);
}

#endif // SDDS_BAKERY_H