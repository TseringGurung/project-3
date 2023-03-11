/*
Name: Tsering Gurung
Date: 03/10/2023
Class: CS 235
Professor: Tiziana Ligorio
Assignment: LibraryRecord.hpp
Project 3: Create a subclass of the ArrayBag.
*/

#ifndef LIBRARYRECORD_HPP_
#define LIBRARYRECORD_HPP_

#include "ArrayBag.hpp"
#include "Book.hpp"

class LibraryRecord : public ArrayBag<Book>{
    /*- A vector containing a copy of all the Books that have been checked out.*/
    private:
    std::vector<Book> Book_copy;

    public:
    /*Default Constructor*/
    LibraryRecord();

    /** @param:   A reference to a Book object to be checked in
    @return:  returns true if a book was successfully added to items_, false otherwise
    @post:    adds book to items_.
    **/
    bool checkIn(const Book& checkin_); 

    /** @param:   A reference to a Book object to be checked out   
    @return:  returns true if a book was successfully removed from items_, false otherwise
    @post:    removes the book from the LibraryRecord and if remove was successful, it adds the book to the vector of checked-out books.
    **/
    bool checkOut(const Book& checkout_);

    /**
    @param:   A reference to a Book object
    @return:  The number of times (int) the referenced Book has been checked out
    */
    int getCheckOutHistory(const Book& History_) const;

    /* @post:    Outputs the names of the Books in the LibraryRecord and the number of times each Book has been cheked out*/
    void display() const; 

    /*@post:    Prints the title of each Book in the LibraryRecord*/
    void displayTitles() const; 

    /**
    @return:    Returns true if the LibraryRecord was successfully duplicated, false otherwise (there is nothing to duplicate or duplicating would exceed DEFAULT_CAPACITY).
    @post:      Duplicates all the items in the LibraryRecord
    Example: we originally have [book1, book2] and after duplication we have [book1, book2, book1, book2]
    */
    bool duplicateStock();

    /**
    @param:   A reference to a book
    @return: True if at least one copy of the referenced book was removed from items_, false otherwise 
    @post: remove all occurrences of the referenced book
    */
    bool removeStock(const Book& removestock_); 

    /*@param:   A reference to another LibraryRecord*/
    bool equivalentRecords(const LibraryRecord& LibraryRecord_) const; 

    /*@param:   A reference to another LibraryRecord object*/
    void operator+=(const LibraryRecord& duplicate_add);

    /*@param:   A reference to another LibraryRecord object*/
    void operator/=(const LibraryRecord& non_duplicate_add);

};

#endif
