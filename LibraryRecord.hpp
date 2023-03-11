#ifndef LIBRARYRECORD_HPP_
#define LIBRARYRECORD_HPP_

#include "ArrayBag.hpp"
#include "Book.hpp"

class LibraryRecord : public ArrayBag<Book>{
    /*- A vector containing a copy of all the Books that have been checked out.*/
    private:
    std::vector<Book> Book_copy;

    public:
    LibraryRecord();
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
