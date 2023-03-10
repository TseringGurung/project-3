#ifndef LIBRARYRECORD_H
#define LIBRARYRECORD_H
#include "ArrayBag.hpp"
#include "Book.hpp"
#include <iostream>
#include <vector>

class LibraryRecord : public ArrayBag<Book>{
    /*- A vector containing a copy of all the Books that have been checked out.*/
    private:
    std::vector<Book> Book_copy;

    public:
    bool checkIn(const Book& checkin_);
    bool checkOut(const Book& checkout_);
    int getCheckOutHistory(const Book& History_) const;
    void display() const;
    void displayTitles() const;
    bool duplicateStock();
    bool removeStock(const Book& removestock_);
    bool equivalentRecords(const LibraryRecord& LibraryRecord_) const;
    void operator+=(const LibraryRecord& duplicate_add);
    void operator/=(const LibraryRecord& non_duplicate_add);
};

#endif
