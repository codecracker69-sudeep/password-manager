#include "database.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::string DB_FILE = "data/passwords.db";

void saveRecord(const Record& r) {
    std::ofstream file(DB_FILE, std::ios::app);
    if (!file) {
        std::cout << "Error opening database file.\n";
        return;
    }

    file << r.website << "|" << r.username << "|" << r.encryptedPassword << "\n";
}

std::vector<Record> loadRecords() {
    std::vector<Record> records;
    std::ifstream file(DB_FILE);

    if (!file) return records;

    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        Record r;
        getline(ss, r.website, '|');
        getline(ss, r.username, '|');
        getline(ss, r.encryptedPassword, '|');
        records.push_back(r);
    }

    return records;
}

void deleteRecord(const std::string& website) {
    std::vector<Record> records = loadRecords();
    std::ofstream file(DB_FILE, std::ios::trunc);

    for (auto& r : records) {
        if (r.website != website) {
            file << r.website << "|" << r.username << "|" << r.encryptedPassword << "\n";
        }
    }
}
