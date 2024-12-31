#ifndef BORROWING_CONTEXT_H
#define BORROWING_CONTEXT_H

#include "BorrowingStrategy.h"

class BorrowingContext {
private:
    BorrowingStrategy* strategy;
public:
    explicit BorrowingContext(BorrowingStrategy* strategy) : strategy(strategy) {}
    void executeBorrow(std::shared_ptr<Book> book) {
        strategy->borrow(book);
    }
};

#endif // BORROWING_CONTEXT_H