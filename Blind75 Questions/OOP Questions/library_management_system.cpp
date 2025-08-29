// 📚 BASIC LIBRARY MANAGEMENT SYSTEM
#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>
#include <string>

class Book {
    std::string title;
    std::string author;
    std::string isbn;
public:
    Book(std::string t, std::string a, std::string i) : title(t), author(a), isbn(i) {}
    std::string getTitle() const { return title; }
    std::string getISBN() const { return isbn; }
};

class BookCopy {
    const Book& book;
    int copyId;
    bool isAvailable;
public:
    BookCopy(const Book& b, int id) : book(b), copyId(id), isAvailable(true) {}

    bool available() const { return isAvailable; }
    void borrow() { isAvailable = false; }
    void returned() { isAvailable = true; }
    int getId() const { return copyId; }
    const Book& getBook() const { return book; }
};

class Member {
    std::string name;
    int memberId;
public:
    Member(std::string n, int id) : name(n), memberId(id) {}
    std::string getName() const { return name; }
    int getId() const { return memberId; }
};

class Loan {
    Member member;
    BookCopy& copy;
public:
    Loan(const Member& m, BookCopy& bc) : member(m), copy(bc) {
        copy.borrow();
    }
    void returnBook() {
        copy.returned();
    }
    void print() const {
        std::cout << member.getName() << " borrowed copy " << copy.getId()
                  << " of book: " << copy.getBook().getTitle() << "\n";
    }
};

class Library {
    std::vector<Book> books;
    std::vector<std::unique_ptr<BookCopy>> copies;
    std::vector<Member> members;
    std::vector<std::unique_ptr<Loan>> loans;
    int nextCopyId = 1;
public:
    const Book& addBook(std::string title, std::string author, std::string isbn) {
        books.emplace_back(title, author, isbn);
        return books.back();
    }

    BookCopy& addCopy(const Book& book) {
        copies.emplace_back(std::make_unique<BookCopy>(book, nextCopyId++));
        return *copies.back();
    }

    Member& addMember(std::string name) {
        int id = members.size() + 1;
        members.emplace_back(name, id);
        return members.back();
    }

    void borrowBook(Member& member, std::string isbn) {
        for (auto& copy : copies) {
            if (copy->getBook().getISBN() == isbn && copy->available()) {
                loans.emplace_back(std::make_unique<Loan>(member, *copy));
                std::cout << member.getName() << " borrowed: " << copy->getBook().getTitle() << "\n";
                return;
            }
        }
        std::cout << "No available copy for ISBN: " << isbn << "\n";
    }

    void listLoans() const {
        for (const auto& loan : loans) {
            loan->print();
        }
    }
};

int main() {
    Library library;

    auto& book1 = library.addBook("1984", "George Orwell", "123");
    auto& book2 = library.addBook("Brave New World", "Aldous Huxley", "456");

    library.addCopy(book1);
    library.addCopy(book1);
    library.addCopy(book2);

    auto& alice = library.addMember("Alice");
    auto& bob = library.addMember("Bob");

    library.borrowBook(alice, "123");
    library.borrowBook(bob, "123");
    library.borrowBook(bob, "123"); // No more available

    std::cout << "\nLoan List:\n";
    library.listLoans();

    return 0;
}
