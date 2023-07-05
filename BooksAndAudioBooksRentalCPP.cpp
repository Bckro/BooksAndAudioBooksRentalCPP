#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book
{
public:
    string author;
    string title;
    bool available;
};

class Audiobook : public Book
{
public:
    string narrator;
};

class Library : Audiobook
{
public:
    vector<Book> books;
    vector<Audiobook> audiobooks;

    void Add()
    {
        cout << "\nDo you want to add a book or an audiobook?\n1 - Book, 2 - Audiobook\n" << endl;
        string response;
        cin >> response;

        if (response == "1")
        {
            cout << "\nEnter the author and title of the book" << endl;
            Book book;
            cin.ignore();
            getline(cin, book.author);
            getline(cin, book.title);
            book.available = true;
            books.push_back(book);
        }
        else if (response == "2")
        {
            cout << "\nEnter the author, title, and narrator of the audiobook" << endl;
            Audiobook audiobook;
            cin.ignore();
            getline(cin, audiobook.author);
            getline(cin, audiobook.title);
            getline(cin, audiobook.narrator);
            audiobook.available = true;
            audiobooks.push_back(audiobook);
        }
        else
        {
            Add();
        }
    }

    void Display()
    {
        cout << endl;
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].available)
            {
                cout << "Book available: " << books[i].title << " by " << books[i].author << endl;
            }
        }

        for (int i = 0; i < audiobooks.size(); i++)
        {
            if (audiobooks[i].available)
            {
                cout << "Audiobook available: " << audiobooks[i].title << " by " << audiobooks[i].author << ", Narrator: " << audiobooks[i].narrator << endl;
            }
        }
    }

    void RentBook()
    {
        int response;
        cout << "\nWhich book would you like to rent?\nAvailable books:" << endl;
        vector<Book> availableBooks;
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].available)
            {
                cout << i + 1 << ". " << books[i].title << " by " << books[i].author << endl;
                availableBooks.push_back(books[i]);
            }
        }
        if (availableBooks.size() == 0)
        {
            cout << "No books available for renting." << endl;
        }
        else
        {
            cin >> response;
            Find(availableBooks[response - 1].title, false);
            cout << "\nThank you for renting the book: " << availableBooks[response - 1].title << endl;
        }
    }

    void ReturnBook()
    {
        int response;
        cout << "\nWhich book would you like to return?" << endl;
        vector<Book> unavailableBooks;
        for (int i = 0; i < books.size(); i++)
        {
            if (!books[i].available)
            {
                cout << i + 1 << ". " << books[i].title << " by " << books[i].author << endl;
                unavailableBooks.push_back(books[i]);
            }
        }
        if (unavailableBooks.size() == 0)
        {
            cout << "No books to return." << endl;
        }
        else
        {
            cin >> response;
            Find(unavailableBooks[response - 1].title, true);
            cout << "\nThank you for returning the book: " << unavailableBooks[response - 1].title << endl;
        }
    }

    void Find(string title, bool availability)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].title == title)
            {
                books[i].available = availability;
                break;
            }
        }
    }
};

int main()
{
    cout << "Welcome to the library!" << endl;
    Library library;

    // Add sample books
    Book book1;
    book1.author = "John Doe";
    book1.title = "The Great Gatsby";
    book1.available = true;
    library.books.push_back(book1);

    Book book2;
    book2.author = "Jane Smith";
    book2.title = "To Kill a Mockingbird";
    book2.available = true;
    library.books.push_back(book2);

    Book book3;
    book3.author = "Mark Johnson";
    book3.title = "1984";
    book3.available = true;
    library.books.push_back(book3);

    // Add sample audiobooks
    Audiobook audiobook1;
    audiobook1.author = "Stephen King";
    audiobook1.title = "The Shining";
    audiobook1.narrator = "James Anderson";
    audiobook1.available = true;
    library.audiobooks.push_back(audiobook1);

    Audiobook audiobook2;
    audiobook2.author = "Agatha Christie";
    audiobook2.title = "Murder on the Orient Express";
    audiobook2.narrator = "Emily Johnson";
    audiobook2.available = true;
    library.audiobooks.push_back(audiobook2);

    Audiobook audiobook3;
    audiobook3.author = "J.K. Rowling";
    audiobook3.title = "Harry Potter and the Sorcerer's Stone";
    audiobook3.narrator = "Daniel Smith";
    audiobook3.available = true;
    library.audiobooks.push_back(audiobook3);

    do
    {
        cout << "\nChoose an action:" << endl;
        cout << "1. Add a book or an audiobook\n2. Display available books and audiobooks\n3. Rent a book\n4. Return a book\n5. Exit\n\n";
        int response;
        cin >> response;

        switch (response)
        {
        case 1:
            library.Add();
            break;
        case 2:
            library.Display();
            break;
        case 3:
            library.RentBook();
            break;
        case 4:
            library.ReturnBook();
            break;
        case 5:
            exit(0);
            break;
        default:
            break;
        }

    } while (true);

    return 0;
}
