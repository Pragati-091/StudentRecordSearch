#include <iostream>
using namespace std;

struct Student {
    int roll;
    string name;
    int marks;
};

int main() {
    Student s[50];
    int n = 0;
    int choice;

    do {
        cout << "\n---- Student Record Search System ----\n";
        cout << "1. Add Student Record\n";
        cout << "2. Display All Records\n";
        cout << "3. Linear Search (by Roll No)\n";
        cout << "4. Binary Search (by Roll No)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Roll No: ";
            cin >> s[n].roll;
            cout << "Enter Name: ";
            cin >> s[n].name;
            cout << "Enter Marks: ";
            cin >> s[n].marks;
            n++;
            cout << "Student added successfully.\n";
        }

        else if (choice == 2) {
            if (n == 0) {
                cout << "No records available.\n";
            } else {
                for (int i = 0; i < n; i++) {
                    cout << "\nRoll No: " << s[i].roll;
                    cout << "\nName: " << s[i].name;
                    cout << "\nMarks: " << s[i].marks << endl;
                }
            }
        }

        else if (choice == 3) {
            int key, found = 0;
            cout << "Enter Roll No to search: ";
            cin >> key;

            for (int i = 0; i < n; i++) {
                if (s[i].roll == key) {
                    cout << "Record Found!\n";
                    cout << "Name: " << s[i].name << endl;
                    cout << "Marks: " << s[i].marks << endl;
                    found = 1;
                    break;
                }
            }

            if (found == 0) {
                cout << "Record not found.\n";
            }
        }

        else if (choice == 4) {
            // Sorting by roll number (simple bubble sort)
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                    if (s[j].roll > s[j + 1].roll) {
                        Student temp = s[j];
                        s[j] = s[j + 1];
                        s[j + 1] = temp;
                    }
                }
            }

            int key, low = 0, high = n - 1, found = 0;
            cout << "Enter Roll No to search: ";
            cin >> key;

            while (low <= high) {
                int mid = (low + high) / 2;

                if (s[mid].roll == key) {
                    cout << "Record Found!\n";
                    cout << "Name: " << s[mid].name << endl;
                    cout << "Marks: " << s[mid].marks << endl;
                    found = 1;
                    break;
                } else if (s[mid].roll < key) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            if (found == 0) {
                cout << "Record not found.\n";
            }
        }

        else if (choice == 5) {
            cout << "Exiting program.\n";
        }

        else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
