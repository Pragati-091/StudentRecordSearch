#include <iostream>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool issued;
};

int main() {
    Book library[50];
    int totalBooks = 0;
    int choice = 0;

    do {
        cout << "\n--- Library Management System ---\n";
        cout << "1. Add Book\n";
        cout << "2. View All Books\n";
        cout << "3. Search Book by ID\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Choice: ";

        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter a valid number.\n";
            continue;
        }

        if (choice == 1) {
            if (totalBooks == 50) {
                cout << "Library limit reached.\n";
                continue;
            }

            cout << "Book ID: ";
            cin >> library[totalBooks].id;
            cin.ignore();

            cout << "Book Title: ";
            getline(cin, library[totalBooks].title);

            cout << "Author: ";
            getline(cin, library[totalBooks].author);

            library[totalBooks].issued = false;
            totalBooks++;

            cout << "Book added.\n";
        }

        else if (choice == 2) {
            if (totalBooks == 0) {
                cout << "No books in library.\n";
                continue;
            }

            for (int i = 0; i < totalBooks; i++) {
                cout << "ID: " << library[i].id
                     << " | " << library[i].title
                     << " | " << library[i].author
                     << " | "
                     << (library[i].issued ? "Issued" : "Available") << endl;
            }
        }

        else if (choice == 3) {
            int id;
            cout << "Enter ID: ";
            cin >> id;

            bool found = false;
            for (int i = 0; i < totalBooks; i++) {
                if (library[i].id == id) {
                    cout << library[i].title << " by "
                         << library[i].author << " ("
                         << (library[i].issued ? "Issued" : "Available") << ")\n";
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Book not found.\n";
        }

        else if (choice == 4) {
            int id;
            cout << "Book ID to issue: ";
            cin >> id;

            bool done = false;
            for (int i = 0; i < totalBooks; i++) {
                if (library[i].id == id) {
                    if (library[i].issued)
                        cout << "Already issued.\n";
                    else {
                        library[i].issued = true;
                        cout << "Book issued.\n";
                    }
                    done = true;
                    break;
                }
            }

            if (!done)
                cout << "Invalid ID.\n";
        }

        else if (choice == 5) {
            int id;
            cout << "Book ID to return: ";
            cin >> id;

            bool done = false;
            for (int i = 0; i < totalBooks; i++) {
                if (library[i].id == id) {
                    if (!library[i].issued)
                        cout << "Book was not issued.\n";
                    else {
                        library[i].issued = false;
                        cout << "Book returned.\n";
                    }
                    done = true;
                    break;
                }
            }

            if (!done)
                cout << "Invalid ID.\n";
        }

    } while (choice != 6);

    cout << "Program closed.\n";
    return 0;
}
