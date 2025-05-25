#include <iostream>
#include <string>

using namespace std;

class Publication {
public:
    virtual void display() const = 0; 
    virtual string getTitle() const = 0; 
    virtual ~Publication() {} 
};

class Book : public Publication {
private:
    string title;
    string author;
    int pages;
public:
    Book(string t, string a, int p) : title(t), author(a), pages(p) {}

    void display() const override {
        cout << "Book: " << title << ", Author: " << author << ", Pages: " << pages << endl;
    }

    string getTitle() const override {
        return title;
    }

    int getPages() const {
        return pages;
    }
};


class Newspaper : public Publication {
private:
    string name;
    string date;
    string edition;
public:
    Newspaper(string n, string d, string e) : name(n), date(d), edition(e) {}

    void display() const override {
        cout << "Newspaper: " << name << ", Date: " << date << ", Edition: " << edition << endl;
    }

    string getTitle() const override {
        return name;
    }

    string getEdition() const {
        return edition;
    }
};

class Library {
private:
    Publication* collection[100]; 
    int count;

public:
    Library() : count(0) {}

    ~Library() {
        for (int i = 0; i < count; ++i) {
            delete collection[i]; 
        }
    }

    void addBook(const Book& book) {
        if (count < 100) {
            collection[count++] = new Book(book);
        }
    }

    void addNewspaper(const Newspaper& newspaper) {
        if (count < 100) {
            collection[count++] = new Newspaper(newspaper); 
        }
    }

    void displayCollection() const {
        for (int i = 0; i < count; ++i) {
            collection[i]->display();
        }
    }

    Book* searchBookByTitle(const string& title) {
        for (int i = 0; i < count; ++i) {
            Book* book = dynamic_cast<Book*>(collection[i]);
            if (book && book->getTitle() == title) {
                return book; 
            }
        }
        return nullptr; 
    }

    Newspaper* searchNewspaperByName(const string& name) {
        for (int i = 0; i < count; ++i) {
            Newspaper* news = dynamic_cast<Newspaper*>(collection[i]);
            if (news && news->getTitle() == name) {
                return news; 
            }
        }
        return nullptr;
    }

    // Binary search for books (requires sorted input)
    Book* binarySearchBooks(const string& title) {
        int low = 0, high = count - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            Book* book = dynamic_cast<Book*>(collection[mid]);
            if (book) {
                if (book->getTitle() == title) {
                    return book; 
                }
                else if (book->getTitle() < title) {
                    low = mid + 1; 
                }
                else {
                    high = mid - 1; 
                }
            }
        }
        return nullptr;
    }
};

// Main function
int main() {
    // Create book objects
    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);
    Book book3("1984", "George Orwell", 328);

    // Create newspaper objects
    Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
    Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");

    // Create a library object
    Library library;

    // Add books and newspapers to the library
    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);
    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);

    // Display the entire collection
    cout << "Library Collection:\n";
    library.displayCollection();

    // Search for a book by title using linear search
    Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");
    if (foundBook) {
        cout << "\nFound Book:\n";
        foundBook->display();
    }
    else {
        cout << "\nBook not found.\n";
    }

    // Search for a newspaper by name using linear search
    Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");
    if (foundNewspaper) {
        cout << "\nFound Newspaper:\n";
        foundNewspaper->display();
    }
    else {
        cout << "\nNewspaper not found.\n";
    }

    // Search for a book 
    Book* binaryFoundBook = library.binarySearchBooks("1984");
    if (binaryFoundBook) {
        cout << "\nFound Book using Binary Search:\n";
        binaryFoundBook->display();
    }
    else {
        cout << "\nBook not found in binary search.\n";
    }

    return 0;
}
