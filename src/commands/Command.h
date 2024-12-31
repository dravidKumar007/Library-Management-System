#ifndef COMMAND_H
#define COMMAND_H

#include <memory>
#include <iostream>
#include "../models/Book.h"

class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

class BorrowBookCommand : public Command {
private:
    std::shared_ptr<Book> book;
public:
    explicit BorrowBookCommand(std::shared_ptr<Book> book) : book(book) {}
    void execute() override {
        std::cout << "Borrowing book: " << book->title << std::endl;
    }
};

class ReturnBookCommand : public Command {
private:
    std::shared_ptr<Book> book;
public:
    explicit ReturnBookCommand(std::shared_ptr<Book> book) : book(book) {}
    void execute() override {
        std::cout << "Returning book: " << book->title << std::endl;
    }
};

#endif // COMMAND_H