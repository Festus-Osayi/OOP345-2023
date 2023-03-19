/*Filename: Book.cpp
Author:	Festus Osayi
Student Number : 170276216
-----------------------------------------------------------
Date: 2023/02/19
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.*/
#include <algorithm>
#include "Book.h"
#include <iostream>
#include <iomanip>

using namespace std;
namespace sdds
{

    // a constructor that receives a reference to an unmodifiable string that contains information about the book; this constructor extracts the information about the book from the string by parsing it and stores the tokens in the object's attributes.
    Book::Book(const std::string &strBook)
    {
        int author = strBook.find(',');
        this->bookAuthor = strBook.substr(0, author);
        this->bookAuthor.erase(0, this->bookAuthor.find_first_not_of(" "));
        this->bookAuthor.erase(this->bookAuthor.find_last_not_of(" ") + 1);

        int title = strBook.find(',', author + 1);
        this->bookTitle = strBook.substr(author + 1, title - author - 1);
        this->bookTitle.erase(0, this->bookTitle.find_first_not_of(" "));
        this->bookTitle.erase(this->bookTitle.find_last_not_of(" ") + 1);

        int country = strBook.find(',', title + 1);
        this->countryOfPubliction = strBook.substr(title + 1, country - title - 1);
        this->countryOfPubliction.erase(0, this->countryOfPubliction.find_first_not_of(" "));
        this->countryOfPubliction.erase(this->countryOfPubliction.find_last_not_of(" ") + 1);

        int price = strBook.find(',', country + 1);
        this->priceOfBook = stod(strBook.substr(country + 1, price - country - 1));

        int year = strBook.find(',', price + 1);
        this->yearOfPublication = stod(strBook.substr(price + 1, year - price - 1));

        int description = strBook.find('.', year + 1);
        this->bookDesc = strBook.substr(year + 1, description - year + 1);
        this->bookDesc.erase(0, this->bookDesc.find_first_not_of(" "));
    }

    // // a query that returns the title of the book
    const std::string &Book::title() const
    {
        return this->bookTitle;
    }

    // // a query that returns the publication country..
    const std::string &Book::country() const
    {
        return this->countryOfPubliction;
    }

    //   // a query that returns the publication year
    const size_t &Book::year() const
    {
        return this->yearOfPublication;
    }

    // // a function that returns the price **by reference**,
    // allowing the client code to update the price
    double &Book::price()
    {
        return this->priceOfBook;
    }

    // // overload the insertion operator to insert the content of a book object into an **ostream** object..

    std::ostream &Book::write(std::ostream &ostr) const
    {
        ostr << setw(20) << this->bookAuthor << " | "
             << setw(22) << this->bookTitle << " | "
             << setw(5) << this->countryOfPubliction << " | "
             << setw(4) << this->yearOfPublication << " | "
             << setw(6) << fixed << setprecision(2) << priceOfBook << " | "
             << bookDesc << endl;

        return ostr;
    }

    std::ostream &operator<<(std::ostream &os, const Book &obj)
    {
        if (!os.fail())
        {
            obj.write(os);
        }
        return os;
    }
}