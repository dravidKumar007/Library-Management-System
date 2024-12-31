#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include "User.h"
#include "../models/Book.h"

class Member : public User {
public:
    void borrowBook(std::shared_ptr<Book> book) override {
        std::cout << "Member borrowing book: " << book->title << std::endl;
    }

    void returnBook(std::shared_ptr<Book> book) override {
        std::cout << "Member returning book: " << book->title << std::endl;
    }
};

#endif
