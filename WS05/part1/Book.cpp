/*Filename: Book.cpp
Author:	Festus Osayi
Student Number : 170276216
-----------------------------------------------------------
Date: 2023/02/19
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.*/

#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include "Book.h"
#include <algorithm>
#include <iterator>
using namespace std;

namespace sdds
{
    // a default constructor..
    Book::Book() {}

    // a query that returns the title of the book
    const std::string &Book::title() const
    {
        return this->bookTitle;
    }

    // a query that returns the publication country..
    const std::string &Book::country() const
    {
        return this->countryOfPubliction;
    }

    // a query that returns the publication year
    const size_t &Book::year() const
    {
        return this->yearOfPublication;
    }

    // a function that returns the price **by reference**,
    // allowing the client code to update the price
    double &Book::price()
    {
        return this->priceOfBook;
    }

    // a constructor that receives a reference to an unmodifiable string that contains information about the book; this constructor extracts the information about the book from the string by parsing it and stores the tokens in the object's attributes.
    Book::Book(const std::string &strBook)
    {
        int author = strBook.find(',');
        bookAuthor = strBook.substr(0, author);
        bookAuthor.erase(0, bookAuthor.find_first_not_of(" "));
        bookAuthor.erase(bookAuthor.find_last_not_of(" ") + 1);

        int title = strBook.find(',', author + 1);
        bookTitle = strBook.substr(author + 1, title - author - 1);
        bookTitle.erase(0, bookTitle.find_first_not_of(" "));
        bookTitle.erase(bookTitle.find_last_not_of(" ") + 1);

        int country = strBook.find(',', title + 1);
        countryOfPubliction = strBook.substr(title + 1, country - title - 1);
        countryOfPubliction.erase(0, countryOfPubliction.find_first_not_of(" "));
        countryOfPubliction.erase(countryOfPubliction.find_last_not_of(" ") + 1);

        int price = strBook.find(',', country + 1);
        priceOfBook = stod(strBook.substr(country + 1, price - country - 1));

        int year = strBook.find(',', price + 1);
        yearOfPublication = stod(strBook.substr(price + 1, year - price - 1));

        int description = strBook.find('.', year + 1);
        bookDesc = strBook.substr(year + 1, description - year + 1);
        bookDesc.erase(0, bookDesc.find_first_not_of(" "));
    }

    // overload the insertion operator to insert the content of a book object into an **ostream** object..

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

    // overload the insertion operator to insert the content of a book object into an **ostream** object..
    std::ostream &operator<<(std::ostream &ostr, const Book &os)
    {
        if (!ostr.fail())
        {
            os.write(ostr);
        }
        return ostr;
    }

   
}