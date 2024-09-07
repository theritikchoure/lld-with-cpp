#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Library {
    public:
        string name;
        Address location;
        vector<BookItem> books;
};

class Address {                        
    public:
        string street;
        string city;
        string state;
        string zipCode;
};

class Book {
    public:
         string uniqueIdNumber;
        string title;
        vector<Author> author;
        string ISBN;
        BookType bookType;
};

class BookItem : public Book {
    public:
        string barcode;
        tm publicationDate;
        Rack rackLocation;
        BookStatus bookStatus;
        BookFormat bookFormat;
        tm issueDate;
};

enum BookType {
    SCI_FI,
    ROMANTIC,
    FANTASY,
    DRAMA
};

enum BookFormat {
    HARDCOVER,
    PAPERBACK,
    NEWSPAPER,
    JOURNAL
};

enum BookStatus {
    ISSUED, 
    AVAILABLE,
    RESERVED,
    LOST
};

class Rack {
    int number;
    string locationId;
};

class Person {
    public:
        string firstName;
        string lastName;
};

class Author : public Person {
    public:
        vector<Book> booksPublished;
}; 

class SystemUser : public Person {
    public:
        string email;
        string phoneNumber;
        Account account;
};

class Account {
    public:
        string userName;
        string password;
        int accountId;
};

class Member : public SystemUser {
    public:
        int totalBookCheckedOut;

        Search searchObj;
        BookIssueService issueService;
};

class Librarian : public SystemUser {
    public:
        Search searchObj;
        BookIssueService issueService;

        void addBookItem(BookItem bookItem) {};
        void editBookItem(BookItem bookItem) {};
        void deleteBookItem(string barcode) {};
};

class Search {
    public:
        vector<BookItem> getBookByTitle(string title) {};
        vector<BookItem> getBookByAuth(Author author) {};
        vector<BookItem> getBookByType(BookType bookType) {};
        vector<BookItem> getBookByPublicationDate(tm publicationDate) {};
};

class BookIssueService {
    public:
        FineService fineService;

        BookReservationDetail getReservationDetail(BookItem book) {};

        void updateReservationDetail(BookReservationDetail bookReservationDetail) {};

        BookReservationDetail reserveBook(BookItem book, SystemUser user) {};
        BookIssueDetail issueBook(BookItem book, SystemUser user) {};

        // it will internally call the issueBook function after basic validation
        BookIssueDetail renewBook(BookItem book, SystemUser user) {};

        void returnBook(BookItem book, SystemUser user) {};
};

class BookLending {
    public:
        BookItem book;
        SystemUser user;
        tm startDate;
};

enum ReservationStatus {
    COMPLETED,
    PENDING,
    CANCELED
};

class BookReservationDetail : public BookLending {
    public:
        ReservationStatus reservationStatus;
};

class BookIssueDetail : public BookLending {
    public:
        tm dueDate;
};

class FineService {
    public:
        Fine calculateFine(BookItem book, SystemUser user, int days) {};
};

class Fine {
    public:
        tm fineDate;
        BookItem book;
        SystemUser user;
        double fineValue;
};

int main()
{
    return 0;
}