#ifndef BORROWING_STRATEGY_H
#define BORROWING_STRATEGY_H

#include <memory>
#include "../models/Book.h"

class BorrowingStrategy {
public:
    virtual void borrow(std::shared_ptr<Book> book) = 0;
    virtual ~BorrowingStrategy() = default;
};

#endif // BORROWING_STRATEGY_H