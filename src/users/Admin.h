#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include "User.h"
#include "../models/Book.h"

class Admin : public User {
public:
    void borrowBook(std::shared_ptr<Book> book) override {
        std::cout << "Admin borrowing book: " << book->title << std::endl;
    }

    void returnBook(std::shared_ptr<Book> book) override {
        std::cout << "Admin returning book: " << book->title << std::endl;
    }
};

#endif
