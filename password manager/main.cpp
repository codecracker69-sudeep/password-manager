#include <iostream>
#include <vector>
#include <string>

#include "encryption.h"
#include "database.h"
#include "Record.h"

using namespace std;

int main() {

    system("mkdir -p data");

    cout << "\n--- PASSWORD MANAGER ---\n";
    cout << "Set your master key: ";
    string masterKey;
    getline(cin, masterKey);

    int choice;

    while (true) {
        cout << "\n---MENU---\n";
        cout << "1. Add Password\n";
        cout << "2. View Passwords\n";
        cout << "3. Search Password\n";
        cout << "4. Delete Password\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            Record r;
            cout << "Enter website: ";
            getline(cin, r.website);
            cout << "Enter username: ";
            getline(cin, r.username);
            cout << "Enter password: ";
            string plainPass;
            getline(cin, plainPass);

            r.encryptedPassword = encryptPassword(plainPass, masterKey);
            saveRecord(r);

            cout << "Password saved successfully.\n";
        }

        else if (choice == 2) {
            vector<Record> records = loadRecords();
            cout << "\n--- Saved Passwords ---\n";

            if (records.empty()) {
                cout << "No passwords saved yet.\n";
                continue;
            }

            for (auto& r : records) {
                cout << "Website: " << r.website << endl;
                cout << "Username: " << r.username << endl;
                cout << "Password: "
                     << decryptPassword(r.encryptedPassword, masterKey) << endl;
                cout << "------------------------\n";
            }
        }

        else if (choice == 3) {
            cout << "Enter website to search: ";
            string site;
            getline(cin, site);

            vector<Record> records = loadRecords();
            bool found = false;

            for (auto& r : records) {
                if (r.website == site) {
                    cout << "\nWebsite: " << r.website << endl;
                    cout << "Username: " << r.username << endl;
                    cout << "Password: "
                         << decryptPassword(r.encryptedPassword, masterKey) << endl;
                    found = true;
                    break;
                }
            }

            if (!found) cout << "No record found.\n";
        }

        else if (choice == 4) {
            cout << "Enter website to delete: ";
            string site;
            getline(cin, site);

            deleteRecord(site);
            cout << "Record deleted (if existed).\n";
        }

        else if (choice == 5) {
            cout << "Exiting...\n";
            break;
        }

        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}

