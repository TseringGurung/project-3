#ifndef LIBRARYRECORD_H
#define LIBRARYRECORD_H
#include "ArrayBag.hpp"
#include "Book.hpp"
#include <iostream>
#include <vector>

class LibraryRecord : public ArrayBag<Book>{
    /*- A vector containing a copy of all the Books that have been checked out.*/
    private:
    std::vector <Book> Book_copy;

    public:
    bool checkIn(Book& checkin_);
    bool checkOut(Book& checkout_);
    int getCheckOutHistory(Book& History_);
    void display();
    void displayTitles();
    bool duplicateStock();
    bool removeStock(Book& removestock_);
    bool equivalentRecords(LibraryRecord& LibraryRecord_);
    void operator+=(LibraryRecord& duplicate_add);
    void operator/=(LibraryRecord& non_duplicate_add);
};

#endif