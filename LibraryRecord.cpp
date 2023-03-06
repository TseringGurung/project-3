#include "LibraryRecord.hpp"

/** @param:   A reference to a Book object to be checked in
    @return:  returns true if a book was successfully added to items_, false otherwise
    @post:    adds book to items_.
 **/
bool LibraryRecord::checkIn(Book& checkin_){
  if(add(checkin_)){
    return true;
  }
  return false;
}


/** @param:   A reference to a Book object to be checked out   
    @return:  returns true if a book was successfully removed from items_, false otherwise
    @post:    removes the book from the LibraryRecord and if remove was successful, it adds the book to the vector of checked-out books.
 **/
bool LibraryRecord::checkOut(Book& checkout_){
  if(remove(checkout_)){
    return true;
  }
  return false;
}


/**
  @param:   A reference to a Book object
  @return:  The number of times (int) the referenced Book has been checked out
*/
int LibraryRecord::getCheckOutHistory(Book& History_){
  return getFrequencyOf(History_);
}


/**
    @post:    Outputs the names of the Books in the LibraryRecord and the number of times each Book has been cheked out

      For each Book in the LibraryRecord you will output:
             "[title_] is written by [author_]. Page Count: [page_count_]. [It is / It is not] available digitally.\n
             It has been checked out [_] times.\n"
  **/
void LibraryRecord::display(){
  for(int i = 0; i < getCurrentSize(); i++){
    std::cout << book_title << " is written by " << book_author << ". Page Count: " << page_count << ". ";
        if(digital){
        std::cout << "It is available digitally.\n";
        } 
        else{
        std::cout << "It is not available digitally.\n";
        }
  }
}




/**
  @post:    Prints the title of each Book in the LibraryRecord
  Example:
  "title1, title2, title3, title4!\n" Note the commas and exclamation mark.
*/
void LibraryRecord::displayTitles(){
  for(int i = 0; i < getCurrentSize(); i++){
    std::cout << book_title[i];
  }
}



/**
  @return:    Returns true if the LibraryRecord was successfully duplicated, false otherwise (there is nothing to duplicate or duplicating would exceed DEFAULT_CAPACITY).
  @post:      Duplicates all the items in the LibraryRecord
  Example: we originally have [book1, book2] and after duplication we have [book1, book2, book1, book2]
*/
bool LibraryRecord::duplicateStock(){
  //copy array
}


/**
  @param:   A reference to a book
  @return: True if at least one copy of the referenced book was removed from items_, false otherwise 
  @post: remove all occurrences of the referenced book
*/
bool LibraryRecord::removeStock(Book& removestock_){

}


/**
  @param:   A reference to another LibraryRecord
  @return:  Returns true if the 2 library records have the same contents (including the same number of duplicates for each book), regardless of their order. For example, if the current holdings of the LibraryRecord are [book1, book2, book3]
  and those of the referenced LibraryRecord are [book3, book1, book2], it will return true.

  However, [book1, book2, book2, book3] is not equivalent to [book1, book2, book3, book3], because it contains two copies of book2 and only one copy of book3*/
bool LibraryRecord::equivalentRecords(LibraryRecord& LibraryRecord_){

}



/**
    @param:   A reference to another LibraryRecord object
    @post:    Combines the contents from both LibraryRecord objects, including duplicates.
    Example: [book1, book2, book3] += [book1, book4] will produce [book1, book2, book3, book1, book4]

    IMPORTANT: We are carrying over the number of times a book has been checked out. For example, if we have LibraryRecord1 += LibraryRecord2 and
    book4 is in LibraryRecord2 and has been checked out 2 times, then it should still be checked out 2 times in LibraryRecord1 after the += operation
    Hint: use getCheckOutHistory and the checkout history vector
*/
void LibraryRecord::operator+=(LibraryRecord& duplicate_add){
  std::vector <int> add;
   for(int i = 0; i < duplicate_add.item_count_; i++){
      add.push_back(items_[i]);
   }
   for(int i = 0; i < duplicate_add.item_count_; i++){
      add.push_back(duplicate_add[i]);
   }
}



/** @param:   A reference to another LibraryRecord object
    @post:    Combines the contents from both LibraryRecord objects, EXCLUDING duplicates.
    Example: [book1, book2, book3] /= [book1, book4] will produce [book1, book2, book3, book4]

    IMPORTANT: We are carrying over the nunber of times a book has been checked out. For example, if we have LibraryRecord1 /= LibraryRecord2 and
    book4 is in LibraryRecord2 and has been checked out 2 times, then it should still be checked out 2 times in LibraryRecord1 after the /= operation
    Hint: use getCheckOutHistory and the checkout history vector
*/
void LibraryRecord::operator/=(LibraryRecord& non_duplicate_add){
  std::vector <int> add;
   for (int i = 0; i < non_duplicate_add.item_count_; i++)
    {
        if (!contains(non_duplicate_add.items_[i]))
        {
            add(non_duplicate_add.items_[i]);
        }
    }
}