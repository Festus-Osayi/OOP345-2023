/*Filename: Bakery.h
Author:	Festus Osayi
Student Number : 170276216
-----------------------------------------------------------
Date: 2023/03/19
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete the workshop.*/
#ifndef _SDDS_BAKERY_H_
#define _SDDS_BAKERY_H_

#include <iostream>
#include <vector>
#include <list>

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
        std::vector<BakedGood> m_collection;
    public:
        Bakery() = default;
        Bakery(const char* filename);
        void showGoods(std::ostream& os = std::cout) const;
        void sortBakery(std::string field);
        std::vector<BakedGood> combine(Bakery& bakery);
        bool inStock(const std::string desc, const BakedType& bt) const;
        std::list<BakedGood> outOfStock(BakedType bt) const;
    };
    
    std::ostream& operator<<(std::ostream& out, const BakedGood& b);
    std::string trim(const std::string& str);
}

#endif // end of an if statement..