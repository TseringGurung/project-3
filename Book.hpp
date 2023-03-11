#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>

class Book{
/*
private:
	- The title of the book (a string)
	- The author of the book (a string)
	- The page count (an integer)
	- A flag indicating whether the book is available in digital form (a Boolean)
*/
private:
    std::string book_title;
    std::string book_author;
    int page_count;
    bool digital;
public:
    /**
      Default constructor.
      Default-initializes all private members. Booleans are default-initialized to False.
   */
   /**
      Parameterized constructor.
      @param      : The title of the book (a string)
      @param      : The author of the book (a string)
      @param      : The number of pages in the book (a positive int)
      @param      : A flag indicating whether the book is in digital form (a Boolean),
                    with default value False
      @post       : The private members are set to the values of the corresponding parameters.
    */

    Book();
    Book(const std::string Title,const std::string Author,const int PageCount,const bool Digital = false);

    void setTitle(const std::string Title);
    std::string getTitle() const;
    
    void setAuthor(const std::string Author);
    std::string getAuthor() const;
   
    void setPageCount(const int PageCount);
    int getPageCount() const;

    void setDigital();
    bool isDigital() const; 

    bool operator==(const Book& right_side_equal) const;
    bool operator!=(const Book& right_side_not_equal) const;

    void display() const;
};

#endif
