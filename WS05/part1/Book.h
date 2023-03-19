#ifndef _SDDS_BOOK_H_
#define _SDDS_BOOK_H_
#include <iostream>
#include <string>

namespace sdds
{
    class Book
    {
        public:
        std::string bookAuthor{};
        std::string bookTitle{};
        std::string countryOfPubliction;
        size_t yearOfPublication{};
        double priceOfBook{};
        std::string bookDesc;

    public:
        // Public members
        Book();
        const std::string &title() const;
        const std::string &country() const;
        const size_t &year() const;
        double &price();
        Book(const std::string &strBook);
        std::ostream &write(std::ostream &ostr)const;
        friend std::ostream &operator<<(std::ostream &ostr, const Book &os);
    };
    // std::string &trim(std::string &str_to_trim, const std::string &trim_chars = " ");
}

#endif // end of an if statement