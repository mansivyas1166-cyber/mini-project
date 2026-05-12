#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// ================= BOOK =================
class Book {
public:
    int id, qty;
    string title, author;

    void input() {
        cout << "Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Title: ";
        getline(cin, title);

        cout << "Author: ";
        getline(cin, author);

        cout << "Quantity: ";
        cin >> qty;
    }

    void save() {
        ofstream f("books.txt", ios::app);
        f << id << "|" << title << "|" << author << "|" << qty << "\n";
        f.close();
    }
};

// ================= MEMBER =================
class Member {
public:
    int id;
    string name;

    void input() {
        cout << "Member ID: ";
        cin >> id;
        cin.ignore();

        cout << "Name: ";
        getline(cin, name);
    }

    void save() {
        ofstream f("members.txt", ios::app);
        f << id << "|" << name << "\n";
        f.close();
    }
};

// ================= TRANSACTION =================
class Transaction {
public:
    int tid, bookId, memberId;
    string date;

    void input() {
        cout << "Transaction ID: ";
        cin >> tid;

        cout << "Book ID: ";
        cin >> bookId;

        cout << "Member ID: ";
        cin >> memberId;
        cin.ignore();

        cout << "Issue Date: ";
        getline(cin, date);
    }

    void save() {
        ofstream f("trans.txt", ios::app);
        f << tid << "|" << bookId << "|" << memberId << "|" << date << "\n";
        f.close();
    }
};

// ================= DISPLAY FUNCTIONS =================
void displayBooks() {
    ifstream f("books.txt");
    string line;

    cout << "\n--- BOOKS ---\n";
    while (getline(f, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string id, title, author, qty;

        getline(ss, id, '|');
        getline(ss, title, '|');
        getline(ss, author, '|');
        getline(ss, qty, '|');

        cout << "ID: " << id << "\nTitle: " << title
             << "\nAuthor: " << author << "\nQty: " << qty << "\n\n";
    }
    f.close();
}

void displayMembers() {
    ifstream f("members.txt");
    string line;

    cout << "\n--- MEMBERS ---\n";
    while (getline(f, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string id, name;

        getline(ss, id, '|');
        getline(ss, name, '|');

        cout << "ID: " << id << "\nName: " << name << "\n\n";
    }
    f.close();
}

void displayTransactions() {
    ifstream f("trans.txt");
    string line;

    cout << "\n--- TRANSACTIONS ---\n";
    while (getline(f, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string tid, bid, mid, date;

        getline(ss, tid, '|');
        getline(ss, bid, '|');
        getline(ss, mid, '|');
        getline(ss, date, '|');

        cout << "TID: " << tid
             << "\nBook ID: " << bid
             << "\nMember ID: " << mid
             << "\nDate: " << date << "\n\n";
    }
    f.close();
}

// ================= MAIN =================
int main() {
    int ch;

    do {
        cout << "\n===== LIBRARY SYSTEM =====\n";
        cout << "1. Add Book\n2. Show Books\n";
        cout << "3. Add Member\n4. Show Members\n";
        cout << "5. Issue Book\n6. Show Transactions\n";
        cout << "0. Exit\n";

        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1: {
                Book b;
                b.input();
                if (!b.title.empty()) b.save();
                break;
            }
            case 2: displayBooks(); break;

            case 3: {
                Member m;
                m.input();
                if (!m.name.empty()) m.save();
                break;
            }
            case 4: displayMembers(); break;

            case 5: {
                Transaction t;
                t.input();
                t.save();
                break;
            }
            case 6: displayTransactions(); break;

            case 0: cout << "Exit\n"; break;
            default: cout << "Invalid!\n";
        }

    } while (ch != 0);

    return 0;
}
