/*Filename: Bakery.cpp
Author:	Festus Osayi
Student Number : 170276216
-----------------------------------------------------------
Date: 2023/03/19
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete the workshop.*/
#include "Bakery.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

namespace sdds {
    // Constructor that populates the collection
    Bakery::Bakery(const char* filename) {
        ifstream file(filename);
        if (!file) {
            throw "Error: Could not open file";
        }

        // Reading and storing dataFile in collection
        std::string dataFile {};
        while (std::getline(file, dataFile)) {
            BakedGood bakedGood {};
            // Using the transform algorithm to convert baked type string to uppercase to avoid errors while validating
            string bakedType = dataFile.substr(0, 8);
            transform(bakedType.begin(), bakedType.end(), bakedType.begin(), ::toupper);
           
            bakedGood.m_bakedType = trim(bakedType) == "BREAD" ? BakedType::BREAD : BakedType::PASTERY;
            bakedGood.m_description = trim(dataFile.substr(8, 20));
            bakedGood.m_shelfLife = std::stoi(trim(dataFile.substr(28, 14)));
            bakedGood.m_stockAmount = std::stoi(trim(dataFile.substr(42, 8)));
            bakedGood.m_price = std::stod(trim(dataFile.substr(50, 6)));

            // Add the baked good to our list of collections
            m_collection.push_back(bakedGood);
        }
        
        file.close(); //optional but best practice
    }

    // trims all the white spaces from a string
    std::string trim(const std::string& str) {
        string bakeryValue {};
        size_t first = str.find_first_not_of(' ');
        size_t last = str.find_last_not_of(' ');
        if(first == string::npos){
            bakeryValue = str;
        }
        else{
            bakeryValue = str.substr(first, (last - first + 1));
        }

        return bakeryValue;
    }

    // function to display the total stock and price of the goods in the collection.
    void Bakery::showGoods(std::ostream& os) const {
        // Printing all the collection content by looping over all the entries using the for_each method..
        for_each(m_collection.begin(), m_collection.end(), [&os](BakedGood bakedGood) { os << bakedGood << endl; });

        // Calculating total stock amount and price using numeric functions
        auto total_stock = std::accumulate(m_collection.begin(), m_collection.end(), 0, [](int acc, const BakedGood& good) { return acc + good.m_stockAmount; });
        auto total_price = std::accumulate(m_collection.begin(), m_collection.end(), 0.00, [](double acc, const BakedGood& good) { return acc + good.m_price; });
       
        os << "Total Stock: " << total_stock << endl;
        os << "Total Price: " << std::fixed << std::setprecision(2) << total_price << endl;
    }

    // receives a parameter the name of the field used to sort the collection in ascending order.
    void Bakery::sortBakery(std::string field) {
        //The alorithm method to help transform all string field to uppercase, in other to avoid error while validating..
        transform(field.begin(), field.end(), field.begin(), ::toupper);

        // Sorting the collection
        sort(m_collection.begin(), m_collection.end(), [field](const BakedGood& bakedGood1, const BakedGood& bakedGood2) {
            bool success {};
        if (field == "DESCRIPTION"){
            success = bakedGood1. m_description < bakedGood2.m_description;
        }  
        else if (field == "SHELF") {
            success = bakedGood1. m_shelfLife < bakedGood2.m_shelfLife;
        }
        else if(field == "STOCK") {
            success = bakedGood1. m_stockAmount < bakedGood2.m_stockAmount;
        }
        else if(field == "PRICE"){
            success = bakedGood1. m_price < bakedGood2.m_price;
        } 
            return success;
        });
    }

    // receives a parameter of another Bakery object reference and combines the collection of BakedGoods from the current object and the parameter and returns the combined collection. 
    std::vector<BakedGood> Bakery::combine(Bakery& bakery) {
        vector<BakedGood> combined(m_collection.size() + bakery.m_collection.size());

        // Sorting both the vectors
        sortBakery("Price");
        bakery.sortBakery("Price");

        // combining
        merge(m_collection.begin(), m_collection.end(), bakery.m_collection.begin(), bakery.m_collection.end(), combined.begin(), [](const BakedGood& bg1, const BakedGood& bg2) {
            return bg1.m_price < bg2.m_price;
        });
        return combined;
    }

    //  and returns `true` if the collection contains Stock of that BakedGood.
    bool Bakery::inStock(const std::string desc, const BakedType& bt) const {
        return any_of(m_collection.begin(), m_collection.end(), [desc, bt](const BakedGood& bg) {
            return bg.m_description == desc && bg.m_bakedType == bt;
        });
    }

    // returns the list of all the out of stock items in the collection.
    std::list<BakedGood> Bakery::outOfStock(BakedType bt) const {
        list<BakedGood> itemsOutOfStock;
        copy_if(m_collection.begin(), m_collection.end(), std::back_inserter(itemsOutOfStock),[bt](const BakedGood& bg) {
            return bg.m_bakedType == bt && bg.m_stockAmount == 0;
        });
        // Sort the list out-of-stock items by their prices
        itemsOutOfStock.sort([](const BakedGood& bakeryPrice1, const BakedGood& baekryPrice2) {
            return bakeryPrice1.m_price < baekryPrice2.m_price;
        });
        return itemsOutOfStock;
    }

    // Inserts one BakedGood into the first parameter
    std::ostream& operator<<(std::ostream& out, const BakedGood& b) {
        string str{"* "};
        string str1{" * "};
        out << str << std::left << std::setw(10) << (b.m_bakedType == BakedType::BREAD ? "Bread" : "Pastry");
        out << str1 << std::left << std::setw(20) << b.m_description;
        out << str1 << std::left << std::setw(5) << b.m_shelfLife;
        out << str1 << std::left << std::setw(5) << b.m_stockAmount;
        out << str1 << std::right << std::fixed << std::setprecision(2) << std::setw(8) << b.m_price;
        out << str1;
        return out;
    }

    
}