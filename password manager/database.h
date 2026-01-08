#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include "Record.h"

void saveRecord(const Record& r);
std::vector<Record> loadRecords();
void deleteRecord(const std::string& website);

#endif
