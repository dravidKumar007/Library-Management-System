#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:
    std::string title;
    std::string author;

    Book(const std::string& title, const std::string& author) : title(title), author(author) {}
};

#endif // BOOK_H