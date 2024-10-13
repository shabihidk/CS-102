#include <iostream>
#include <string>
using namespace std;

struct Book {
int accNum;  // Accession number
string auth; // Author
string title; // Title
bool issued; // Flag to indicate if the book is issued
};

const int MAX_BOOKS = 100;
Book library[MAX_BOOKS];
int totalBooks = 0;

// Function to display book information
void dispBookInfo(const Book& book) {
cout << "AccNum: " << book.accNum << endl;
cout << "Auth: " << book.auth << endl;
cout << "Title: " << book.title << endl;
cout << "Issued: " << (book.issued ? "Yes" : "No") << endl;
}

// Function to display all books in the library
void dispAllBooks() {
for (int i = 0; i < totalBooks; ++i) {
dispBookInfo(library[i]);
cout << "===============================" << endl;
}
}

// Function to add a new book to the library
void addNewBook() {
if (totalBooks < MAX_BOOKS) {
Book newBook;
cout << "Enter AccNum: ";
cin >> newBook.accNum;
cin.ignore(); // Clear the newline character left in the buffer
cout << "Enter Auth: ";
getline(cin, newBook.auth);
cout << "Enter Title: ";
getline(cin, newBook.title);
newBook.issued = false;

library[totalBooks] = newBook;
totalBooks++;

cout << "Book added successfully!\n";
} else {
cout << "Library is full. Cannot add more books.\n";
}
}

// Function to display books by a specific author
void dispBooksByAuth(const string& authName) {
cout << "Books by Auth '" << authName << "':\n";
for (int i = 0; i < totalBooks; ++i) {
if (library[i].auth == authName) {
dispBookInfo(library[i]);
cout << "===============================" << endl;
}
}
}

// Function to display the number of books with a particular title
void dispBookCountByTitle(const string& bookTitle) {
int count = 0;
for (int i = 0; i < totalBooks; ++i) {
if (library[i].title == bookTitle) {
count++;
}
}
cout << "Num of books with title '" << bookTitle << "': " << count << endl;
}

// Function to find a book index by accession number
int findBookIndexByAccNum(int accNum) {
for (int i = 0; i < totalBooks; ++i) {
if (library[i].accNum == accNum) {
return i;
}
}
return -1; // Book not found
}

// Function to issue a book
void issueBook() {
int accNum;
cout << "Enter AccNum of the book to be issued: ";
cin >> accNum;

int bookIndex = findBookIndexByAccNum(accNum);

if (bookIndex != -1) {
if (!library[bookIndex].issued) {
library[bookIndex].issued = true;
cout << "Book issued successfully!\n";
} else {
cout << "Book is already issued.\n";
}
} else {
cout << "Book not found in the library.\n";
}
}

int main() {
int choice;

do {
cout << "\nLibrary Menu:\n";
cout << "1. Disp Book Info\n";
cout << "2. Add New Book\n";
cout << "3. Disp All Books\n";
cout << "4. Disp Books by Auth\n";
cout << "5. Disp Num of Books by Title\n";
cout << "6. Disp Total Num of Books\n";
cout << "7. Issue a Book\n";
cout << "0. Exit\n";
cout << "Enter your choice: ";
cin >> choice;

switch (choice) {
case 1: {
int accNum;
cout << "Enter AccNum: ";
                cin >> accNum;
                int bookIndex = findBookIndexByAccNum(accNum);
                if (bookIndex != -1) {
                    dispBookInfo(library[bookIndex]);
                } else {
                    cout << "Book not found in the library.\n";
                }
                break;
            }
            case 2:
                addNewBook();
                break;
            case 3:
                dispAllBooks();
                break;
            case 4: {
                string authName;
                cout << "Enter Auth's Name: ";
                cin.ignore(); // Clear the newline character left in the buffer
                getline(cin, authName);
                dispBooksByAuth(authName);
                break;
            }
            case 5: {
                string bookTitle;
                cout << "Enter Book Title: ";
                cin.ignore(); // Clear the newline character left in the buffer
                getline(cin, bookTitle);
                dispBookCountByTitle(bookTitle);
                break;
            }
            case 6:
                cout << "Total Num of Books in the Library: " << totalBooks << endl;
                break;
            case 7:
                issueBook();
                break;
            case 0:
                cout << "Exiting the Library Menu. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 0);

    return 0;
}
