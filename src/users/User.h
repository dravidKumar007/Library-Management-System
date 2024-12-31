#ifndef USER_H
#define USER_H

#include <string>
#include <memory>
#include "../models/Book.h"

class User {
public:
    virtual void borrowBook(std::shared_ptr<Book> book) = 0;
    virtual void returnBook(std::shared_ptr<Book> book) = 0;
    virtual ~User() = default;
};

#endif // USER_H