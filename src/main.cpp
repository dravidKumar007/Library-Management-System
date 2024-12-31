#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include "models/Library.h"
#include "commands/Command.h"
#include "users/UserFactory.h"

void displayMenu() {
    std::cout << "\nLibrary Management System\n";
    std::cout << "1. Add Book\n";
    std::cout << "2. Borrow Book\n";
    std::cout << "3. Return Book\n";
    std::cout << "4. Print All Books\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

void printAllBooks(const Library& library) {
    std::cout << "\nBooks in Library:\n";
    auto books = library.getAllBooks();
    if (books.empty()) {
        std::cout << "No books in the library.\n";
    } else {
        for (const auto& [id, book] : books) {
            std::cout << "ID: " << id << ", Title: " << book->title << ", Author: " << book->author << "\n";
        }
    }
}

int main() {
    Library library;

    int choice;
    while (true) {
        displayMenu();
        std::cin >> choice;

        if (choice == 5) {
            std::cout << "Exiting the system. Goodbye!\n";
            break;
        }

        switch (choice) {
            case 1: {
                int bookId;
                std::string title, author;
                std::cout << "Enter book ID: ";
                std::cin >> bookId;
                std::cin.ignore(); // To handle newline character from previous input
                std::cout << "Enter book title: ";
                std::getline(std::cin, title);
                std::cout << "Enter book author: ";
                std::getline(std::cin, author);

                auto book = std::make_shared<Book>(title, author);
                library.addBook(bookId, book);
                std::cout << "Book added successfully: " << title << " by " << author << "\n";
                break;
            }
            case 2: {
                int bookId;
                std::cout << "Enter book ID to borrow: ";
                std::cin >> bookId;

                auto book = library.getBook(bookId);
                if (book) {
                    BorrowBookCommand borrowCommand(book);
                    borrowCommand.execute();
                } else {
                    std::cout << "Book not found with ID: " << bookId << "\n";
                }
                break;
            }
            case 3: {
                int bookId;
                std::cout << "Enter book ID to return: ";
                std::cin >> bookId;

                auto book = library.getBook(bookId);
                if (book) {
                    ReturnBookCommand returnCommand(book);
                    returnCommand.execute();
                } else {
                    std::cout << "Book not found with ID: " << bookId << "\n";
                }
                break;
            }
            case 4:
                printAllBooks(library);
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
