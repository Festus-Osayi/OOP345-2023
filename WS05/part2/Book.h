/*Filename: Book.h
Author:	Festus Osayi
Student Number : 170276216
-----------------------------------------------------------
Date: 2023/02/19
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.*/
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <string>

namespace sdds
{
    class Book
    {
        std::string bookAuthor{};
        std::string bookTitle{};
        std::string countryOfPubliction;
        size_t yearOfPublication{};
        double priceOfBook{};
        std::string bookDesc;

    public:
        Book(){};
        const std::string &title() const;
        const std::string &country() const;
        const size_t &year() const;
        double &price();
        Book(const std::string &strBook);
        std::ostream& write(std::ostream &ostr) const;
        friend std::ostream &operator<<(std::ostream &os, const Book &obj);

        template <typename T>
        void fixSpelling(T &spellChecker)
        {
            spellChecker(bookDesc);
        };
      
    };
}
#endif //! SDDS_BOOK_H