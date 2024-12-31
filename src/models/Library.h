#ifndef LIBRARY_H
#define LIBRARY_H

#include <unordered_map>
#include <memory>
#include "Book.h"

class Library {
private:
    std::unordered_map<int, std::shared_ptr<Book>> books;

public:
std::unordered_map<int, std::shared_ptr<Book>> getAllBooks() const {
    return books;
}
    void addBook(int id, std::shared_ptr<Book> book) {
        books[id] = book;
    }

    std::shared_ptr<Book> getBook(int id) {
        return books.count(id) ? books[id] : nullptr;
    }
};

#endif // LIBRARY_H